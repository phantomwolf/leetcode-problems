#!/usr/bin/env ruby
require 'open3'

class ProcManager
  def initialize(concurrency=3, debug=false)
    @concurrency = concurrency
    @debug = debug
    @procs = []
  end

  def finalize
    self.check_all
  end

  def wait_one
    exited_proc = nil
    until exited_proc or @procs.empty?
      @procs.each {|item| exited_proc = item if item['wait_thr'].join(0)}
      sleep 1
    end
    return @procs.delete(exited_proc)
  end

  def check_proc(item)
    if @debug or item['wait_thr'].value.exitstatus != 0
      puts "=" * 80
      puts "cmd: #{item['cmd']}"
      puts "pid: #{item['wait_thr'].pid}, exit status: #{item['wait_thr'].value.exitstatus}"
      puts item['stdout'].read
    end
  end

  def check_all
    until @procs.empty?
      item = self.wait_one
      self.check_proc(item)
    end
  end

  def submit(cmd)
    if @procs.size >= @concurrency
      item = self.wait_one
      self.check_proc(item)
    end
    item = {'cmd' => cmd}
    item['stdin'], item['stdout'], item['wait_thr'] = Open3.popen2e(cmd)
    @procs.push(item)
  end
end
