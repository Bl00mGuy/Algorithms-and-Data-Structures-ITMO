package main

import "fmt"

func main() {
	var N int
	fmt.Scan(&N)
	table1 := make([]int, N)
	table2 := make([]int, N)
	var x, y int
	counter := 0
	for i := 0; i < N; i++ {
		fmt.Scan(&x, &y)
		h1 := x % N
		h2 := y % N
		if table1[h1] == 0 && table2[h2] == 0 {
			counter++
		}
		table1[h1] = x
		table2[h2] = y
	}
	if counter <= 3 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
