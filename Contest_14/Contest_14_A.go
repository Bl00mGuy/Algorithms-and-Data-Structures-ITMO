package main

import "fmt"

var str1, str2 string
var array []uint64

func solution(count uint64) uint64 {
	for i := 0; i <= len(str1)-len(str2); i++ {
		match := true
		for j := 0; j < len(str2); j++ {
			if str1[i+j] != str2[j] {
				match = false
				break
			}
		}
		if match {
			count++
			array = append(array, uint64(i))
		}
	}
	return count
}

func main() {
	fmt.Scanln(&str1)
	fmt.Scanln(&str2)
	count := solution(0)
	fmt.Println(count)
	for _, index := range array {
		fmt.Printf("%d ", index)
	}
}
