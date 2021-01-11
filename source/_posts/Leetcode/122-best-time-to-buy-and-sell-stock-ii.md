---
title: 122-best-time-to-buy-and-sell-stock-ii
date: 2020-04-12 21:04:06
tags: [code math]
categories: [leetcode]
---

## 买卖股票最佳时机II

[题目链接](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/submissions/) 

### 思路

这题思路是先找股票如果遇到更便宜的话吧最小值给他，遇到比最小值大的值在与最小值相见在取和最大的利润相比，如果今天的股票价格大于昨天的股票价格直接取前面最大利润的那次

### go阶梯代码

```go
func maxProfit(prices []int) int {
	var maxSum, minNum, Sum int
	minNum = prices[0]
	for i := 1; i < len(prices); i++ {
		if minNum >= prices[i] || prices[i] < prices[i-1] {
			minNum = prices[i]
			Sum += maxSum
			maxSum = 0
		} else if maxSum < prices[i]-minNum {
			maxSum = prices[i] - minNum
		}
	}
	if maxSum != 0 {
		Sum += maxSum
	}
	return Sum
}
```

<++>
