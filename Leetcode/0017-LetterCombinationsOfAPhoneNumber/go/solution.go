func letterCombinations(digits string) []string {
    res := []string{}
    // Base case
    if len(digits) == 0 {
        return res
    }

    dict := map[byte]string {
        '2': "abc",
        '3': "def",
        '4': "ghi",
        '5': "jkl",
        '6': "mno",
        '7': "pqrs",
        '8': "tuv",
        '9': "wxyz",
    }
    path := []byte{}
    backtracking(digits, dict, path, &res)
    return res
}

// Basically DFS
func backtracking(digits string, dict map[byte]string, path []byte, res *[]string) {
    // Check if path complete
    if len(path) == len(digits) {
        (*res) = append(*res, string(path))
        return
    }
    // Neighbors
    c := digits[len(path)]
    for i := 0; i < len(dict[c]); i++ {
        path = append(path, dict[c][i])
        backtracking(digits, dict, path, res)
        path = path[:len(path)-1]
    }
}
