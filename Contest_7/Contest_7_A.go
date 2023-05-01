package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	m := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&m[i])
	}
	length := make([]int, n)
	for i := 0; i < n; i++ {
		length[i] = 1
	}
	next := make([]int, n)
	for i := n - 1; i >= 0; i-- {
		next_length := 0
		next_best := -1
		for j := i + 1; j < n; j++ {
			if m[j] > m[i] && length[j] > next_length {
				next_length = length[j]
				next_best = j
			}
		}
		next[i] = next_best
		length[i] = next_length + 1
	}
	var (
		maximum int = 0
		start   int = -1
	)
	for i := 0; i < n; i++ {
		if length[i] > maximum {
			maximum = length[i]
			start = i
		}
	}
	fmt.Printf("%v\n", maximum)
	fmt.Printf("%v", m[start])
	for i := next[start]; i != -1; i = next[i] {
		fmt.Printf(" %v", m[i])
	}
}
