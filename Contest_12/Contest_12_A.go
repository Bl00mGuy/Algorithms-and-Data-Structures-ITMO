package main

import (
	"fmt"
	"sort"
)

type SNM struct {
	PARENT []int
	RANK   []int
}

func NewSNM(N int) *SNM {
	PARENT := make([]int, N+1)
	RANK := make([]int, N+1)
	for i := 1; i <= N; i++ {
		PARENT[i] = i
		RANK[i] = 0
	}
	return &SNM{PARENT: PARENT, RANK: RANK}
}

func (s *SNM) find(x int) int {
	if s.PARENT[x] != x {
		s.PARENT[x] = s.find(s.PARENT[x])
	}
	return s.PARENT[x]
}

func (s *SNM) merge(x, y int) {
	x_root := s.find(x)
	y_root := s.find(y)
	if x_root == y_root {
		return
	}
	if s.RANK[x_root] < s.RANK[y_root] {
		s.PARENT[x_root] = y_root
	} else if s.RANK[x_root] > s.RANK[y_root] {
		s.PARENT[y_root] = x_root
	} else {
		s.PARENT[y_root] = x_root
		s.RANK[x_root]++
	}
}

type Edge struct {
	from int
	to   int
	cost int
}

func minCost(edges []Edge, n int) int {
	min := 0
	sort.Slice(edges, func(i, j int) bool {
		return edges[i].cost < edges[j].cost
	})
	set := NewSNM(n)
	for _, edge := range edges {
		if set.find(edge.from) != set.find(edge.to) {
			set.merge(edge.from, edge.to)
			min += edge.cost
		}
	}
	root := set.find(1)
	for i := 2; i <= n; i++ {
		if set.find(i) != root {
			return -1
		}
	}
	return min
}

func main() {
	var N, M int
	fmt.Scan(&N, &M)
	edges := make([]Edge, M)
	for i := 0; i < M; i++ {
		var A, B, C int
		fmt.Scan(&A, &B, &C)
		edges[i] = Edge{from: A, to: B, cost: C}
	}
	min := minCost(edges, N)
	fmt.Println(min)
}
