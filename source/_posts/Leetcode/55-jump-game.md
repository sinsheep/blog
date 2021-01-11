---
title: 55-jump-game
date: 2020-04-17 17:46:21
tags: [greedy algorithm]
categories: [leetcode]
---

### 跳跃游戏

[题目链接](https://leetcode-cn.com/problems/jump-game/) 

### 题目思路

我们从倒数第二个数开始倒序遍历, 先设置初始要走的步数为n=1，当我们可以走的步数小于n的时候n+1, 当步数够用时候我们再把n还原到1，最后再在0点判断他是否步数为1

### go解法

#### 方法一

```go
func canJump(nums []int) bool {

	n := 1
	for i := len(nums) - 2; i >= 0; i-- {
		if nums[i] >= n {
			n = 1
		} else {
			n++
		}
		if i == 0 && n != 1 {
			return false
		}
	}
	return true
}

```


#### 方法二

```go
func canJump(nums []int) bool {

    if len(nums) == 1 {
		return true
	}
	max := nums[0]
	for i := 0; i < len(nums)-1; i++ {
		max--
		if max < 0 {
			return false
		}
		if nums[i] > max {
			max = nums[i]
		}
	}
	if max < 1 {
		return false
	}
	return true


}
```

#### 方法三
```go
func canJump3(nums []int) bool {

	m := len(nums)
	dp := make([]int, m)
	dp[0] = nums[0] - 1
	for i := 1; i < m-1; i++ {
		if nums[i] >= dp[i-1] {
			dp[i] = nums[i]
		} else {
			dp[i] = dp[i-1]
		}
		dp[i]--
		if dp[i] < 0 {
			return false
		}
	}
	if dp[0] < 0 && m != 1 {
		return false
	}
	return true
}

```
