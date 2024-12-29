package main


import (
    "fmt"
    "strconv"
)

func reverse(input string) string {
    output := []byte(input)
    for i, j := 0, len(output) - 1; i < j; i, j = i+1, j-1 {
        output[i], output[j] = output[j], output[i]
    }
    return string(output)
}

func DecimalToBinary(input string) string {
    num, err := strconv.ParseInt(input, 10, 64)
    if err != nil {
        panic(err.Error())
    }
    if num == 0 {
        return "0"
    }

    parts := []byte{}
    for num != 0 {
        if num % 2 == 1 {
            parts = append(parts, '1')
        } else {
            parts = append(parts, '0')
        }
        num /= 2
    }
    return reverse(string(parts))
}

func main() {
    input := "20"
    output := DecimalToBinary(input)
    fmt.Printf("%s(decimal) => %s(binary)\n", input, output)
}
