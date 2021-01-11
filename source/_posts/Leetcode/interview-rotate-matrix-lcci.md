---
title: rotate-matrix-lcci
date: 2020-04-14 12:20:34
tags: 
categories: [leetcode,interview] 
---

## 旋转矩阵
[题目链接](https://leetcode-cn.com/problems/rotate-matrix-lcci/) 

### 解体思路

这题思路式数组每个元素按照对应的方位顺时针旋转 四个方块对应位置式(i,j) , (j, n-i-1) , (n-i-1, n-j-1), (n-j-1, i)

### go语言实现

```go
func rotate(matrix [][]int) {

	n := len(matrix)
	for i := 0; i < n/2; i++ {
		for j := i; j < n-1-i; j++ {
			matrix[i][j], matrix[j][n-i-1], matrix[n-i-1][n-j-1], matrix[n-1-j][i] = matrix[n-1-j][i], matrix[i][j], matrix[j][n-i-1], matrix[n-i-1][n-j-1]

			fmt.Println(i, j)
		}
	}

	fmt.Println(matrix)
}
```
