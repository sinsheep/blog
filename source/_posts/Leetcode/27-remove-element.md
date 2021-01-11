---
title: 27-remove-element
date: 2020-04-22 10:36:46
tags: 
categories: [leetcode]
---

## 移除数字

[题目链接](https://leetcode-cn.com/problems/remove-element) 

### 思路

这题有点nt, 直接遍历数组就好了

### go解法

```go

func removeElement(nums []int, val int) int {
	sum := 0
	for i := 0; i < len(nums); i++ {
		if nums[i] != val {
			nums[sum] = nums[i]
			sum++
		}
	}
	return sum
}

```


