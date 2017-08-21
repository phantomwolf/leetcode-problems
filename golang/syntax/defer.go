/* defer语句的特点：
   1.被defer的函数的参数，在defer语句的位置立即求值，之后不再改变
   2.被defer的函数们以LIFO的顺序执行
*/
package main

import (
	"fmt"
)

func calc(index string, a, b int) int {
	ret := a + b
	fmt.Println(index, a, b, ret)
	return ret
}

func main() {
	a := 1
	b := 2
	// calc("10", a, b)立即求值，其返回值为3
	// defer语句相当于：defer calc("1", 1, 3)。其参数不再改变。
	defer calc("1", a, calc("10", a, b))
	a = 0
	// calc("20", a, b)立即求值，返回值为2
	// defer语句相当于：defer calc("2", 0, 2)
	defer calc("2", a, calc("20", a, b))
	b = 1
	// 函数返回后，被defer的函数的运行顺序为：
	//      defer calc("2", 0, 2)
	//      defer calc("1", 1, 3)
}
