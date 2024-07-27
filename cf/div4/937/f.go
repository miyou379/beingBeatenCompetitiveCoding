package main

import (
	"fmt"
	"math"
)

func Solution() {
	var a, b, c int
	fmt.Scanln(&a, &b, &c)
	if a+1 != c {
		fmt.Println(-1)
		return
	}
	if a == 0 {
		fmt.Println(b)
		return
	}
	depth := int(math.Log2(float64(a))) + 1
	left := (1 << depth) - 1 - a
	next := left + 2*(1<<(depth-1)-left)
	ano := (b + c - left) / next
	if (b+c-left)%next != 0 {
		ano++
	}
	fmt.Println(depth - 1 + ano)
}

func main() {
	_T := 1
	fmt.Scanln(&_T)
	for ; _T > 0; _T-- {
		Solution()
	}
}
