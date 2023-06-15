package main

import "fmt"

func main() {
	var N, M, Q int
	fmt.Scan(&N, &M, &Q)
	unavailable := make([][]bool, N)
	for i := 0; i < N; i++ {
		unavailable[i] = make([]bool, M)
	}
	for ; Q > 0; Q-- {
		var x, y int
		fmt.Scan(&x, &y)
		unavailable[x-1][y-1] = true
	}
	graph := make([][]int, N*M)
	for i := 0; i < N*M; i++ {
		graph[i] = []int{}
	}
	direction := [][]int{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}
	for x := 0; x < N; x++ {
		for y := 0; y < M; y++ {
			if unavailable[x][y] {
				continue
			}
			from := x*M + y
			for _, d := range direction {
				nx, ny := x+d[0], y+d[1]
				if nx < 0 || nx >= N || ny < 0 || ny >= M || unavailable[nx][ny] {
					continue
				}
				to := nx*M + ny
				graph[from] = append(graph[from], to)
			}
		}
	}
	match := make([]int, N*M)
	for i := range match {
		match[i] = -1
	}
	used := make([]bool, N*M)
	for i := 0; i < N*M; i++ {
		for j := range used {
			used[j] = false
		}
		Kuhn(i, graph, match, used)
	}
	output := 0
	for _, m := range match {
		if m != -1 {
			output++
		}
	}
	fmt.Println(output)
}

func Kuhn(v int, g [][]int, match []int, used []bool) bool {
	if used[v] {
		return false
	}
	used[v] = true
	for _, to := range g[v] {
		if match[to] == -1 || Kuhn(match[to], g, match, used) {
			match[to] = v
			return true
		}
	}
	return false
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}
