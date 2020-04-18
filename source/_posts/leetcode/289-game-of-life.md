---
title: 289-game-of-life
date: 2020-04-13 09:33:46
tags: [dfs]
categories: [leetcode]
---

## 生命游戏

[题目链接](https://leetcode-cn.com/problems/game-of-life/submissions/) 

### 思路

这题 所有的细胞复活和死亡式在同一时间的, 所以我们采用另一个数组来代替他下一轮的状态, 对原数组进行遍历判断周围活细胞的数量即可。 注意要判断边界，要不然会数组越界

### go 语言实现

```go
func gameOfLife(board [][]int) {
	dx := []int{1, -1, 0, 0, 1, -1, 1, -1}
	dy := []int{1, -1, 1, -1, -1, 1, 0, 0}
	m := len(board)
	n := len(board[0])
	var tmp = make([][]int, m, m)
	for i := 0; i < m; i++ {
		tmp[i] = make([]int, n, n)
		for j := 0; j < n; j++ {
			sum := 0
			for k := 0; k < 8; k++ {
				tx := i + dx[k]
				ty := j + dy[k]
				if tx < 0 || tx >= m || ty < 0 || ty >= n {
					continue
				}
				if board[tx][ty] == 1 {
					sum++
				}
			}
			if board[i][j] == 0 && sum == 3 {
				tmp[i][j] = 1
				continue
			}
			if board[i][j] == 1 {
				if sum < 2 || sum > 3 {
					tmp[i][j] = 0
					continue
				}
			}
			tmp[i][j] = board[i][j]
		}
	}
    copy(board, tmp)
	//fmt.Println(tmp)
}

```
