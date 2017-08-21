package main

import (
    "fmt"
)

func foo() {
    defer func() {
        err := recover()
        fmt.Printf("recovering from: %v\n", err)
    }()

    panic("baka")
    fmt.Println("Won't reach here")
}

func main() {
    foo()
}
