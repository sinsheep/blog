---
title: 79-word-search
date: 2020-04-28 09:26:50
tags: [dfs]
categories: [leetcode]
---
## 单词搜索 ##

[题目链接](https://leetcode-cn.com/problems/word-search/) 

### 题目思路

先判断第一个是否相等 然后传进dfs函数对四个方向进行判断

### go 解法

```go
var flag, m, n int
var dx = []int{1, 0, -1, 0}
var dy = []int{0, 1, 0, -1}

func dfs(board [][]byte, tx, ty int, word string) {
	
	if len(word) == 0 {
		flag = 1
		return
	}
    if flag == 1 || tx < 0 || ty < 0 || tx >= m || ty >= n {
		return
	}
	if board[tx][ty] != word[0] {
		return
	}
	tmp := board[tx][ty]
	board[tx][ty] = '.'
	for i := 0; i < 4; i++ {
		dfs(board, tx+dx[i], ty+dy[i], word[1:])
	}
	board[tx][ty] = tmp
}
func exist(board [][]byte, word string) bool {
    flag=0
	m = len(board)
	if m == 0 {
		return false
	}
	n = len(board[0])
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if board[i][j] == word[0] {
				dfs(board, i, j, word)
			}
			if flag == 1 {
				return true
			}
		}
	}
	return false
}
```



