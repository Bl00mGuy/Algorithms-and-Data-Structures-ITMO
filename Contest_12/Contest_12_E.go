package main

import (
	"fmt"
)

const MAXN int = 200

type Graph struct {
	N     int
	GRAPH [MAXN][MAXN]int
}

func NewGraph(size int) *Graph {
	g := new(Graph)
	g.N = size
	for i := 0; i < g.N; i++ {
		for j := 0; j < g.N; j++ {
			g.GRAPH[i][j] = 0
		}
	}
	return g
}

func (g *Graph) addEdge(u, v, c int) {
	g.GRAPH[u][v] += c
}

func (g *Graph) FordFulkerson(source, sink int) int {
	remainder := [MAXN][MAXN]int{}
	for i := 0; i < g.N; i++ {
		for j := 0; j < g.N; j++ {
			remainder[i][j] = g.GRAPH[i][j]
		}
	}
	PARENT := [MAXN]int{}
	flowMax := 0
	for {
		visited := [MAXN]bool{}
		var q []int
		q = append(q, source)
		visited[source] = true
		PARENT[source] = -1
		for len(q) != 0 {
			u := q[0]
			q = q[1:]
			for v := 0; v < g.N; v++ {
				if !visited[v] && remainder[u][v] > 0 {
					q = append(q, v)
					PARENT[v] = u
					visited[v] = true
					if v == sink {
						break
					}
				}
			}
		}
		if !visited[sink] {
			break
		}
		flowPath := 1<<31 - 1
		for v := sink; v != source; v = PARENT[v] {
			u := PARENT[v]
			flowPath = min(flowPath, remainder[u][v])
		}
		for v := sink; v != source; v = PARENT[v] {
			u := PARENT[v]
			remainder[u][v] -= flowPath
			remainder[v][u] += flowPath
		}
		flowMax += flowPath
	}
	return flowMax
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	var N, M int
	fmt.Scan(&N, &M)
	graph := NewGraph(N)
	for i := 0; i < M; i++ {
		var u, v, c int
		fmt.Scan(&u, &v, &c)
		u, v = u-1, v-1
		graph.addEdge(u, v, c)
	}
	flowMax := graph.FordFulkerson(0, N-1)
	fmt.Println(flowMax)
}
