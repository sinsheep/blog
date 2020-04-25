---
title: 46-permutations
date: 2020-04-25 11:18:45
tags: [dfs]
categories: [leetcode]
---

## 全排列

[题目链接](https://leetcode-cn.com/problems/permutations/) 

### 思路

对数组进行递归，每一次消除用了的元素，直到数组为空


### go解题

```go
var nlen int

func dfs(num []int, nums *[][]int, tmp []int) {

	l := len(num)
	if l == 1 {
		tmp = append(tmp, num[0])
		*nums = append((*nums), tmp)
		return
	}
	for i := 0; i < l; i++ {
		num[i], num[0] = num[0], num[i]
		dfs(num[1:], nums, append(tmp, num[0]))
		num[0], num[i] = num[i], num[0]
	}
}
func permute(nums []int) [][]int {

	var num [][]int
	nlen = len(nums)
	if nlen == 0 {
		return num
	}
	dfs(nums, &num, nil)
	return num
}

```


