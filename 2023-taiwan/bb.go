package main

import (
	"fmt"
)

func gcd(a int, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func Solution() {
	var Rt, Rj int
	var st, sj float64
	fmt.Scanln(&Rt, &Rj, &st, &sj)
	St := int(st*100 + 0.5)
	Sj := int(sj*100 + 0.5)
	lcm := St * Sj / gcd(St, Sj)
	Rkt := (Rt - 1) * (lcm / St)
	Rkj := (Rj - 1) * (lcm / Sj)
	var s string
	if Rkt == Rkj {
		s = "SAME"
	} else if Rkt < Rkj {
		s = "TAOYUAN"
	} else {
		s = "JAKARTA"
	}
	fmt.Println(s)
}

func main() {
	var _T int = 1
	// fmt.Scanln(&_T)
	for ; _T > 0; _T-- {
		Solution()
	}
}
