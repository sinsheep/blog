---
title: 136-single-number
date: 2020-04-27 14:07:27
tags: 
categories: [leetcode]
---

## 只出现一次的数字

[题目链接](https://leetcode-cn.com/problems/single-number/) 

### 题目思路

a^a=0
a^0=a

### go解题思路

```go
func singleNumber(nums []int) int {
	a := 0
	for _, v := range nums {
		a ^= v
	}
	return a
}

```


