package main

import (
    "fmt"
    "sync"
    "sync/atomic"
    "time"
)

type Singleton struct {
    something string
}

var initialized uint32 = 0
var mu sync.Mutex
var instance *Singleton

// Get the pointer of the only instance of Singleton.
// Create it if it's not available yet(lazy initialization)
// check-lock-check pattern
func GetInstance1() *Singleton {
    // check
    if atomic.LoadUint32(&initialized) == 1 {
        // object already initialized. just return
        return instance
    }
    // lock
    mu.Lock()
    defer mu.Unlock()
    // check
    if initialized == 0 {
        instance = &Singleton{"baka1"}
        atomic.StoreUint32(&initialized, 1)
    }
    return instance
}

// Use the once.Do() function in package "sync"
var once sync.Once

func GetInstance2() *Singleton {
    once.Do(func() {
        instance = &Singleton{"baka2"}
    })
    return instance
}


func main() {
    go fmt.Println(GetInstance2().something)
    go fmt.Println(GetInstance2().something)
    time.Sleep(1 * time.Second)
}
