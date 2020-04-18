---
title: 542-01-matrix
date: 2020-04-15 23:13:37
tags: [bfs]
categories: [leetcode]
---

## 01矩阵

[题目链接](https://leetcode-cn.com/problems/01-matrix/) 
### 题目解法
这题记录所有0的点，并且把1的点先标记为最大的值，然后用bfs 搜索最近的一点靠近0的步数找到最小值
### go解法

```go
type point struct {
	x, y int
}

func updateMatrix(matrix [][]int) [][]int {
	m, n, nums := len(matrix), len(matrix[0]), 0

	var p []point
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if matrix[i][j] == 0 {
				p = append(p, point{i, j})
				nums++
			} else {
				matrix[i][j] = m * n
			}
		}
	}
	start := 0
	for {
		if nums <= start {
			break
		}
		dx := []int{1, 0, -1, 0}
		dy := []int{0, 1, 0, -1}
		for i := 0; i < 4; i++ {
			tx := p[start].x + dx[i]
			ty := p[start].y + dy[i]
			if tx < 0 || ty < 0 || tx >= m || ty >= n {
				continue
			}
			if matrix[tx][ty] > matrix[p[start].x][p[start].y]+1 {
				matrix[tx][ty] = matrix[p[start].x][p[start].y] + 1
				p = append(p, point{tx, ty})
				nums++
			}
		}
		start++
	}
	return matrix
}
```
