# @param {String} s
# @return {Integer}

R2I = {
  'I' => 1,
  'V' => 5,
  'X' => 10,
  'L' => 50,
  'C' => 100,
  'D' => 500,
  'M' => 1000,
  nil => 0,       # place holder
}

def roman_to_int(s)
  result = 0
  i = 0
  while i < s.length
    c = s[i]
    next_c = s[i + 1]
    if R2I[next_c] > R2I[c]
      result += R2I[next_c] - R2I[c]
      i += 2
      next
    end
    result += R2I[c]
    i += 1
  end
  return result
end


puts roman_to_int('VI')
