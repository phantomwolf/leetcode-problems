#!/usr/bin/env ruby

# @param {String} s
# @return {Integer}
def length_of_longest_substring(s)
    max = 0
    hash = {}
    left = 0
    right = 0
    while right != s.length
        if hash[s[right]] == nil
            # s[right]不在hash里，right可以继续前进
            hash[s[right]] = true
            right += 1
            next
        end
        # 既然能运行到这里，说明s[right]肯定在hash中出现了
        # 这样我们就得到一个结果：s[left...right-1]
        max = (max > right - left) ? max : right - left
        # 从左边去掉字符，直到去掉会引起重复的那一个(即跟s[right]相等那个)
        while s[left] != s[right]
            hash[s[left]] = nil
            left += 1
        end
        # 循环结束后，显然s[left]等于s[right]
        # 我们还得去掉s[left]
        hash[s[left]] = nil
        left += 1
    end
    # 主循环结束后，right等于s.length，right已经越界
    # 此时，仍然有一个可能的结果：s[left]到s[right-1]
    max = (max > right - left) ? max : right - left
    return max
end
