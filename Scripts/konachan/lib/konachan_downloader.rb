#!/usr/bin/env ruby
require 'uri'
require 'downloader_base'


class KonachanDownloader < DownloaderBase
  HOST = 'konachan.com'

  def initialize(concurrency=3, debug=false)
    @host = KonachanDownloader::HOST
    @port = 80
    super(concurrency, debug)
  end

  def finalize
    super
  end

  def auth(user, password)
    url = "#{@scheme}://#{@host}:#{@port}/user/authenticate"
    data = {'user[name]' => user, 'user[password]' => password}
    res = self.http_post(url, data)
    return res
  end

  def _get_list_url(tag, page=nil)
    args = {'tags' => tag}
    args['page'] = page.to_i if page
    url = "#{@scheme}://#{@host}/post?#{URI.encode_www_form(args)}"
    return url
  end

  def _get_post_urls(html)
    urls = []
    elements = html.scan(/(<a[^>]*class=(?:'|")[^'"]*thumb[^'"]*(?:'|")[^>]*>)\s*<img[^>]*class=(?:'|")[^'"]*preview[^'"]*(?:'|")[^>]*>/m)
    elements.each {|groups|
      a_elem = groups[0]
      # Process properties
      a_properties = self._get_elem_properties(a_elem)
      if a_properties[:href] =~ /^(http|https|ftp):\/\//
        urls.push(a_properties[:href])
      else
        urls.push("#{@scheme}://#{@host}#{a_properties[:href]}")
      end
    }
    return urls
  end

  def _get_pic_url(html)
    # Get url
    url = self._get_pic_png_url(html)
    url = self._get_pic_larger_url(html) unless url
    url = self._get_pic_normal_url(html) unless url
    url = self._get_pic_fallback_url(html) unless url
    # Process it
    if url
      url = "#{@scheme}://#{@host}#{url}" unless url.start_with?('http')
    else
      puts "<" * 80
      puts html
      puts ">" * 80
    end
    return url
  end

  def _get_pic_png_url(html)
    regexp = /<a[^>]+id=(?:"|')png(?:"|')[^>]*>\s*download png/im
    if html =~ regexp
      Regexp.last_match.to_s =~ /href=(?:"|')([^"']+)(?:"|')/im
      puts "[DEBUG] Downloading png version: #{Regexp.last_match[1]}" if @debug
      return Regexp.last_match[1]
    else
      return nil
    end
  end

  def _get_pic_larger_url(html)
    regexp = /<a[^>]+id=(?:'|")highres(?:'|")[^>]*>\s*download larger/im
    if html =~ regexp
      Regexp.last_match.to_s =~ /href=(?:"|')([^"']+)(?:"|')/im
      puts "[DEBUG] Downloading larger version: #{Regexp.last_match[1]}" if @debug
      return Regexp.last_match[1]
    else
      return nil
    end
  end

  def _get_pic_normal_url(html)
    regexp = /<a[^>]+id=(?:'|")highres(?:'|")[^>]*>\s*image/im
    if html =~ regexp
      Regexp.last_match.to_s =~ /href=(?:"|')([^"']+)(?:"|')/im
      puts "[DEBUG] Downloading normal version: #{Regexp.last_match[1]}" if @debug
      return Regexp.last_match[1]
    else
      return nil
    end
  end

  def _get_pic_fallback_url(html)
    regexp = /<img[^>]+id=(?:'|")image(?:'|")[^>]*>/im
    if html =~ regexp
      Regexp.last_match.to_s =~ /src=(?:"|')([^"']+)(?:"|')/im
      puts "[DEBUG] Downloading fallback version: #{Regexp.last_match[1]}" if @debug
      return Regexp.last_match[1]
    else
      return nil
    end
  end
end
