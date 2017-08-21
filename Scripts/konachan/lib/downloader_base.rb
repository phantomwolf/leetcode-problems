#!/usr/bin/env ruby
require 'uri'
require 'open3'
require 'ostruct'
require 'fileutils'
require 'uri'
require 'net/http'
require 'rexml/document'
require 'rexml/xpath'
require 'proc_manager'


class DownloaderBase
  def initialize(concurrency=3, debug=false)
    @port = 80 unless @port
    if @port == 80
      @scheme = 'http'
    elsif @port == 443
      @scheme = 'https'
    end
    @debug = debug
    # Create Net::HTTP object
    @proxy_uri = ENV['http_proxy'] ? URI(ENV['http_proxy']) : OpenStruct.new
    @httpobj = Net::HTTP.new( @host, @port,
                              @proxy_uri.host, @proxy_uri.port, @proxy_uri.user, @proxy_uri.password)
    @proc_manager = ProcManager.new(concurrency, @debug)
    @file_list = {}
  end

  def finalize
    @proc_manager.finalize
    begin
      @httpobj.finish
    rescue IOError
    end
  end

  def _get_list_url(tag, page=nil)
    raise Exception("Method not implemented")
  end

  def _get_post_urls(html)
    raise Exception("Method not implemented")
  end

  def _get_pic_url(html)
    raise Exception("Method not implemented")
  end

  def _get_elem_properties(elem)
    hash = {}
    pairs = elem.scan(/(\w+)=(?:'|")(.*?)(?:'|")/m)
    pairs.each {|key, value| hash[key.to_sym] = value}
    return hash
  end

  def exists?(path)
    dir = File.dirname(path)
    file_name = File.basename(path)
    @file_list[dir] = Dir.entries(dir) unless @file_list[dir]
    if @file_list[dir].include?(file_name)
      return true
    else
      return false
    end
  end

  def _download(url, program='wget', dest=nil, options=nil)
    # Generate cmd line
    case program
      when 'axel'
        dest = "-o '#{dest}'" if dest
        cmd = "axel #{dest} #{options} '#{url}'"
      when 'aria2'
        dest = "-o '#{dest}'" if dest
        cmd = "aria2c -m 2 --allow-overwrite=false #{dest} #{options} '#{url}'"
      else
        dest = "-O '#{dest}'" if dest
        cmd = "wget -nc -t 2 #{dest} #{options} '#{url}'"
    end
    # Start download program
    begin
      @proc_manager.submit(cmd)
    rescue => e
      STDERR.write("=" * 80 + "\n")
      STDERR.write("[ERROR] cmd: #{cmd}\n")
      STDERR.write("[ERROR] Download failed: #{e.to_s}\n")
    end
  end

  def download(url, program='wget', dest=nil, options=nil)
    # Init variables
    src_filename = URI.decode(File.basename(url))
    dest_dirname = './'
    dest_filename = nil
    if dest
      dest = File.expand_path(dest)
      if self.exists?(dest)
        if File.directory?(dest)
          dest_dirname = dest
        else
          # Remove existing file
          FileUtils.rm(dest)
          dest_dirname = File.dirname(dest)
          dest_filename = File.basename(dest)
        end
      else
        dest_dirname = File.dirname(dest)
        dest_filename = File.basename(dest)
        # Create the destination directory
        FileUtils.mkdir_p(dest_dirname)
      end
    else
      # Download to current dir if not specified
      dest_dirname = Dir.pwd
    end
    if dest_filename
      dest = File.expand_path(File.join(dest_dirname, dest_filename))
    else
      dest = File.expand_path(File.join(dest_dirname, src_filename))
    end
    # Start wget process
    if self.exists?(dest)
      puts "[WARN] File already existed: #{dest}" if @debug
    else
      Dir.chdir(dest_dirname) {
        self._download(url, program, dest_filename, options)
      }
    end
  end

  def http_get(url)
    uri = URI(url)
    req = Net::HTTP::Get.new(uri.request_uri)
    res = @httpobj.request(req)
    # Follow redirection
    for i in 1..2
      break unless [301, 302, 303].include?(res.code.to_i)
      req = Net::HTTP::Get.new(URI(res['Location']))
      res = @httpobj.request(req)
    end
    # return HTTPResponse
    return res
  end

  def http_post(url, data)
    uri = URI(url)
    req = Net::HTTP::Post.new(uri.request_uri)
    req.set_form_data(data)
    res = @httpobj.request(req)
    return res
  end

  def get_list_page(tag, page=nil)
    url = self._get_list_url(tag, page)
    begin
      res = self.http_get(url)
    rescue => e
      # try again
      begin
        res = self.http_get(url)
      rescue => e
        STDERR.write("[ERROR] Failed to get '#{url}'. #{e.to_s}\n")
        self.finalize
        exit 1
      end
    end
    return res.body
  end

  def get_post_page(url)
    begin
      res = self.http_get(url)
    rescue => e
      begin
        res = self.http_get(url)
      rescue => e
        STDERR.write("[ERROR] Failed to get '#{url}'. #{e.to_s}\n")
        return nil
      end
    end
    return res.body
  end

  def run(tag, program='wget', dest=nil, options=nil, from_page=1, to_page=nil)
    count = from_page
    loop do
      break if to_page and count > to_page
      # Get post list page
      list_page = get_list_page(tag, count)
      # Get post urls
      post_urls = self._get_post_urls(list_page)
      if post_urls.empty?
        puts "[WARN] No post urls found on page #{count}" if @debug
        break
      end
      # Download each pic
      post_urls.each {|post_url|
        post_page = self.get_post_page(post_url)
        if post_page
          pic_url = _get_pic_url(post_page)
          begin
            self.download(pic_url, program, dest, options)
          rescue => e
            STDERR.write("[ERROR] Failed to download '#{pic_url}': #{e.to_s}\n")
          end
        else
          STDERR.write("[ERROR] Failed to get post page '#{post_url}'\n")
        end
      }
      count += 1
    end
  end
end
