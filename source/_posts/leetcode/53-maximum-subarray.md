---
title: 53-maximum-subarray
date: 2020-05-03 09:46:19
tags: [dp]
categories: [leetcode]
---

## 最大连续子序和


[题目链接](https://leetcode-cn.com/problems/maximum-subarray/) 


### 解题思路
判断目前子序列最大的值，如果小于的当前nums的值 就吧当前子序列的值换成num值 并且每一步判断下num的值和max值大小

### go代码

```golang
func maxSubArray(nums []int) int {
	max := nums[0]
	num := nums[0]
	for i := 1; i < len(nums); i++ {
		if num+nums[i] > nums[i] {
			num += nums[i]
		} else {
			num = nums[i]
		}
		if num >= max {
			max = num
		}
	}
	return max
}


```
