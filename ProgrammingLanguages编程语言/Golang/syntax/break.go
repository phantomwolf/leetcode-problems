/* Try the functionality of break/continue statement */
package main

import (
	"fmt"
)

func main() {
loop1:
	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			if i == 1 && j == 1 {
				continue loop1
			}
			fmt.Printf("i: %d, j: %d\n", i, j)
		}
	}
}
