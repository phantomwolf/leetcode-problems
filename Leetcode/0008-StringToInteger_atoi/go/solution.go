func myAtoi(s string) int {
    index := 0
    // Skip whitespace
    for index < len(s) && s[index] == ' ' {
        index++
    }
    if index >= len(s) {
        return 0
    }
    // Sign
    isPositive := true
    if s[index] == '-' {
        isPositive = false
        index++
    } else if s[index] == '+' {
        index++
    }
    // Scanning each character
    result := int64(0)
    for index < len(s) {
        if s[index] < '0' || s[index] > '9' {
            // Not a digit
            break
        }
        result = result * 10 + int64(s[index] - '0')
        if isPositive && result >= math.MaxInt32 {
            return math.MaxInt32
        } else if !isPositive && -result <= math.MinInt32 {
            return math.MinInt32
        }
        index++
    }
    if isPositive {
        return int(result)
    }
    return int(-result)
}

/* Verification:
Input: s = " -042"
Output: -42

index = 0, s[index] = ' '
index = 1, s[index] = '-', isPositive = false
index = 2, s[index] = '0', result = 0 * 10 + 0 = 0
index = 3, s[index] = '4', result = 0 * 10 + 4 = 4
index = 4, s[index] = '2', result = 4 * 10 + 2 = 42
isPositive = false, return -42
*/
