package main

import (
    "fmt"
    "strconv"
)


func BinaryToDecimal(input string) string {
    var output int64 = 0
    var exp int64 = 1
    for i := len(input) - 1; i >= 0; i-- {
        if input[i] == '1' {
            output += exp
        }
        exp *= 2
    }
    return strconv.FormatInt(output, 10)
}

func main() {
    input := "1101"
    output := BinaryToDecimal(input)
    fmt.Printf("%s(binary) => %s(decimal)\n", input, output)
}
