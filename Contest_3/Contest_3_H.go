package main

import "fmt"

func SUM(array []int, number_of_elements int) int {
	sum := 0
	for i := 0; i < number_of_elements; i++ {
		sum += array[i]
	}
	return sum
}

func Max(array []int, number_of_elements int) int {
	max := -56
	for i := 0; i < number_of_elements; i++ {
		if array[i] > max {
			max = array[i]
		}
	}
	return max
}

func Mid(array []int, number_of_elements int, number_of_delimiters int, mid int) bool {
	count := 0
	sum := 0
	for i := 0; i < number_of_elements; i++ {
		sum += array[i]
		if sum > mid {
			count++
			sum = array[i]
		}
	}
	if count < number_of_delimiters {
		return true
	} else {
		return false
	}
}

func bin(array []int, number_of_delimiters int, number_of_elements int) int {
	left := Max(array, number_of_elements)
	right := SUM(array, number_of_elements)
	answer := 0
	for left <= right {
		mid := (left + right) / 2
		if Mid(array, number_of_elements, number_of_delimiters, mid) == true {
			answer = mid
			right = mid - 1
		} else {
			left = mid + 1
		}
	}
	return answer
}

func main() {
	var number_of_elements, number_of_delimiters, element, sum, counter, j int
	fmt.Scan(&number_of_elements, &number_of_delimiters)
	array := make([]int, number_of_elements)
	for i := 0; i < number_of_elements; i++ {
		fmt.Scan(&element)
		array[i] = element
	}
	summ := bin(array, number_of_delimiters, number_of_elements)
	arr := make([]bool, number_of_elements)
	for i := 0; i < number_of_elements; i++ {
		arr[i] = false
	}
	counter = 0
	for i := 0; i < number_of_elements; i++ {
		sum += array[i]
		if sum > summ {
			arr[i] = true
			counter++
			sum = array[i]
		}
	}
	sum = 0
	for counter != number_of_delimiters-1 {
		if !arr[j] {
			arr[j] = true
			counter++
		}
		j++
	}
	for i := 0; i < number_of_elements; i++ {
		if arr[i] {
			fmt.Print(i, " ")
		}
	}
}
