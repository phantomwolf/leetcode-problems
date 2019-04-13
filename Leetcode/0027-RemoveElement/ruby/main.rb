#!/usr/bin/env ruby#

# @param {Integer[]} nums
# @param {Integer} val
# @return {Integer}

def remove_element(nums, val)
    i = 0
    j = nums.length - 1
    loop do
        # Find the nearest val
        while i < nums.length and nums[i] != val
            i += 1
        end
        # Find the nearest non-val
        while j >= 0 and nums[j] == val
            j -= 1
        end
        # Check if i >= j
        if i >= j
            return j + 1
        end
        nums[i] = nums[j]
        # indexes
        i += 1
        j -= 1
    end
end


nums = [3, 2, 2, 3]
length = remove_element(nums, 3)
puts length
puts "#{nums}"
