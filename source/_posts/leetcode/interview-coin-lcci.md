---
title: interview-coin-lcci
date: 2020-04-23 18:32:59
tags: [dp]
categories: [leetcode]
---

## 硬币

[题目链接](https://leetcode-cn.com/problems/coin-lcci/) 

### 思路
dp即可

### go解法

```go
func waysToChange(n int) int {

	dp := make([]int, n+1)

	coins := []int{1, 5, 10, 25}

	for i := 0; i < 4; i++ {
		for j := 1; j <= n; j++ {
			if coins[i] < j {
				dp[j] += dp[j-coins[i]]
			}
			if coins[i] == j {
				dp[j]++
			}
			dp[j] %= 1000000007
		}
	}
	return dp[n]
}

```


