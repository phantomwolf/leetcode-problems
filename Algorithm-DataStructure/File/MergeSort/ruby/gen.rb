#!/usr/bin/env ruby

INT_MAX = 9999999

def gen_large_file(path, count)
  file = File.new(path, "wb")

  for i in 0...count
    file.write("#{rand(INT_MAX)}\n")
    puts "#{i.to_f/count * 100}%" if i % 1000000 == 0
  end

  file.close
end

gen_large_file("source.dat", INT_MAX)
