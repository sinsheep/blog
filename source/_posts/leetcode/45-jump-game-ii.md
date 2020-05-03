---
title: 45-jump-game-ii
date: 2020-05-01 13:06:04
tags: [greedy algorithm]
categories: [leetcode]
---

## 跳跃游戏

[题目链接](https://leetcode-cn.com/problems/jump-game-ii/) 
### 题目思路
贪心算法

### go题目思路

```go
func jump(nums []int) int {
	l := 0
	end := 0
	maxl := 0
	for i := 0; i < len(nums) -1; i++ {
		if nums[i]+i > maxl {
			maxl = nums[i] + i
		}
		if i == end {
			end = maxl
			l++
		}
	}
	return l
}

```


