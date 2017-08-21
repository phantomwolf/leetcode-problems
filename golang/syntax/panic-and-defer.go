package main

import (
	"fmt"
)

func main() {
	defer func() { fmt.Println("func1") }()
	defer func() { fmt.Println("func2") }()
	defer func() { fmt.Println("func3") }()

	// 触发panic后，先执行defer的函数。
	// 我们可以在defer的函数里进行restore，恢复panic状态，因此defer的函数必定先执行。
	// 本例中，触发panic后，被defer的函数并没有restore，因此最后程序还是会停止运行，打印panic信息
	panic("crash")
}
