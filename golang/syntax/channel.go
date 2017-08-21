package main

import (
	"fmt"
	"time"
)

// send some data, then print time
func sender(ch chan int) {
	ch <- 384
	fmt.Println("sender: ", time.Now())
}

func receiver(ch chan int) {
	time.Sleep(10000 * time.Millisecond)
	fmt.Println("receiver: ", time.Now())
	data := <-ch
	fmt.Println("data received: ", data)
	time.Sleep(3000 * time.Millisecond)
}

func main() {
	ch := make(chan int)
	go sender(ch)
	receiver(ch)
}
