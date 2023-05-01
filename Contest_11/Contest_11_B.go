package main

import "fmt"

var n, m int

func main() {
	fmt.Scan(&n, &m)
	graph := make([][]int, n)
	for i := 0; i < n; i++ {
		graph[i] = make([]int, n)
	}

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			graph[i][j] = 100000
		}
	}
	for i := 0; i < n; i++ {
		graph[i][i] = 0
	}

	for i := 0; i < m; i++ {
		var u, v, weight int
		fmt.Scan(&u, &v, &weight)
		u--
		v--
		graph[u][v] = weight
		graph[v][u] = weight
	}

	FloydWarshall(graph)

	distance := 0
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if graph[i][j] != 100000 {
				distance = max(graph[i][j], distance)
			}
		}
	}

	if distance != 0 {
		fmt.Println(distance)
	} else {
		fmt.Println(0)
	}
}

func FloydWarshall(graph [][]int) {
	for k := 0; k < n; k++ {
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j])
			}
		}
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
