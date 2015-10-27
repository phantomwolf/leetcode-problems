#!/usr/bin/env ruby


INT_MAX = 9999999
BUF_SIZE = 1048576

def buffer_min_with_index(buffer)
  min = INT_MAX + 1
  min_index = -1
  for i in 0...buffer.length
    if buffer[i] != nil and min > buffer[i]
      min = buffer[i]
      min_index = i
    end
  end
  return min, min_index
end

def merge_sort(path)
  # Generate sorted tmp file
  buffer = Array.new
  i = 0
  tmp_index = 0

  source_file = File.new('source.dat', 'rb')
  begin
    while true
      num = source_file.readline.chomp.to_i
      buffer[i] = num
      i += 1
      if i == BUF_SIZE
        # Buffer is full. Sort it and write to tmp file
        buffer.sort!
        File.open("tmp#{tmp_index}.dat", "wb") do |file|
          buffer.each {|elem| file.write("#{elem}\n")}
        end
        i = 0
        tmp_index += 1
      end
    end
  rescue EOFError => e
    # Write remnant elements
    File.open("tmp#{tmp_index}.dat", "wb") do |file|
      for j in 0...i
        file.write("#{buffer[j]}\n")
      end
    end
    tmp_index += 1
  end
  source_file.close
  buffer.clear

  # Open tmp files
  tmp_files = []
  for i in 0...tmp_index
    tmp_files.push(File.new("tmp#{i}.dat", "rb"))
  end

  # Open result file
  result_file = File.new("sorted.dat", "wb")

  # Merge tmp files
  remaining_files = tmp_index
  buffer = Array.new(tmp_index)
  for i in 0...tmp_index
    buffer[i] = tmp_files[i].readline.chomp.to_i
  end

  while remaining_files != 0
    min, index = buffer_min_with_index(buffer)
    begin
      buffer[index] = tmp_files[index].readline.chomp.to_i
    rescue EOFError => e
      buffer[index] = nil
      remaining_files -= 1
    end
    # Write min to result file
    result_file.write("#{min}\n")
  end

  # Close all files
  result_file.close
end

def file_is_sorted(path)
  prev = -1
  File.open(path, "rb") do |file|
    num = file.readline.chomp.to_i
    if num < prev
      return false
    end
  end
  return true
end

merge_sort("source.dat")
if file_is_sorted("sorted.dat")
  puts("sorted.dat is sorted")
else
  puts("sorted.dat is not sorted")
end
