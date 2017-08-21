#!/usr/bin/env ruby
$LOAD_PATH.unshift(File.join(File.dirname(__FILE__), '..', 'lib'))
require 'fileutils'
require 'optparse'
require 'ostruct'


def safe_file_name(dir_name)
  result = ''
  invalid_chars = '/\\?%*:|"<>.'
  for i in 0..dir_name.length-1
    if invalid_chars.include?(dir_name[i])
      result << '-'
    else
      result << dir_name[i]
    end
  end
  return result
end


if __FILE__ == $PROGRAM_NAME
  options = OpenStruct.new
  # Set default values
  options.supported_sites = ['konachan']
  options.site = 'konachan'
  options.supported_programs = ['wget', 'axel', 'aria2']
  options.program = 'wget'
  options.from_page = 1
  options.concurrency = 3
  options.debug = false
  # Parse command line options
  OptionParser.new {|opts|
    opts.banner = "Usage: #{$PROGRAM_NAME} [OPTION] TAG [DEST]"
    opts.separator('')
    opts.separator('Options')
    opts.on('-s', '--site [SITE]', String,
            'Supported sites: konachan') {|site|
      options.site = site.strip.downcase
      unless options.supported_sites.include?(options.site)
        raise Exception("Website #{options.site} not supported")
      end
    }
    opts.on('-u', '--auth [USER_PASSWD]', String,
            'User and password for authentication') {|auth|
      raise Exception('The auth info should match "<user>:<password>" pattern') unless auth =~ /[^:]+:[^:]+/
      options.user, options.passwd = auth.split(':')
    }
    opts.on('-p', '--program [PROGRAM]', String,
            "Supported download programs: #{options.supported_programs.join('/')}") {|program|
      options.program = program.strip.downcase
      unless options.supported_programs.include?(options.program)
        raise Exception("Program '#{program}' not supported")
      end
    }
    opts.on('-o', '--options [DOWNLOAD_OPTION]', String,
            'Download options for wget/axel/aria2') {|args|
      options.args = options
    }
    opts.on('-c', '--concurrency [PROC_LIMIT]', Integer,
            'Max limit of child processes') {|concurrency|
      options.concurrency = concurrency
    }
    opts.on('--from [PAGE_NUM]', Integer, 'The first page to download from') {|from_page|
      options.from_page = from_page
    }
    opts.on('--to [PAGE_NUM]', Integer, 'The last page to download from') {|to_page|
      options.to_page = to_page
    }
    opts.on('--debug', 'Enable debug output') {
      options.debug = true
    }
  }.parse!
  if ARGV.length < 1 or ARGV.length > 2
    raise Exception("Usage: #{$PROGRAM_NAME} [OPTION] TAG [DEST]")
  end
  options.tag = ARGV[0]
  options.dest = ARGV[1] if ARGV[1]
  # Ensure options
  options.dest = File.join(File.expand_path('~/Pictures/'), safe_file_name(options.tag)) unless options.dest
  raise Exception('Please specify site name with -s|--site option') if options.site == nil
  raise Exception('Please specify tag') if options.tag == nil
  # Create dir
  FileUtils.rm(options.dest) if File.file?(options.dest)
  FileUtils.mkdir_p(options.dest)
  # Init
  require "#{options.site}_downloader"
  dl = Kernel.const_get("#{options.site.capitalize}Downloader").new(options.concurrency, options.debug)
  if options.user
    res = dl.auth(options.user, options.passwd)
    raise Exception("Authentication failed") unless res.code.to_i >= 200 and res.code.to_i < 400
  end
  dl.run(options.tag, options.program, options.dest, options.args, options.from_page, options.to_page)
  dl.finalize
end
