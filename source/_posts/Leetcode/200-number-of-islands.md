---
title: 200-numbers-of-islands
date: 2020-04-20 21:34:42
tags: [dfs]
categories: [leetcode]
---

## 岛屿数量
[题目链接](https://leetcode-cn.com/problems/number-of-islands) 

### 解体思路
这题遇到了岛屿然后对此为止进行周围扫描把周围的1变成0, 题目有个坑,他可能会传个空数组回来

### go解题思路

```go
func dfs(grid *[][]byte, dx, dy int) {

	if dx < 0 || dy < 0 || dx >= m || dy >= n {
		return
	}
	if (*grid)[dx][dy] == '0' {
		return
	}
	(*grid)[dx][dy] = '0'

	for k := 0; k < 4; k++ {
		dfs(grid, dx+pos[k][0], dy+pos[k][1])
	}
}

var m, n int
var pos = [][]int{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}

func numIslands(grid [][]byte) int {
	var sum int
	m = len(grid)
    if m==0{
        return sum
    }
	n = len(grid[0])
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] == '1' {
				dfs(&grid, i, j)
				sum++
			}
		}
	}
	return sum
}

```


