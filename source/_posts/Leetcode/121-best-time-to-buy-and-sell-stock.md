---
title: 121-best-time-to-buy-and-sell-stock
date: 2020-04-12 12:58:10
tags: [code math]
categories: [leetcode]
---
## 买卖股票最佳时间

[题目链接](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/) 

### 思路
这题思路是遍历数组同时记录最小的数，然后遇到比他大的数和他相减与最大利润相比取最大值，遇到比自己小的数就吧最小值替换成那该数
### go语言实现
```go
func maxProfit(prices []int) int {

    if len(prices)==0{
        return 0
    }
	maxNum, initNum := 0, prices[0]

	for i := 1; i < len(prices); i++ {
		if initNum >= prices[i] {
			initNum = prices[i]
		} else {

			if maxNum == 0 {
				maxNum = prices[i] - initNum
			} else if maxNum < prices[i]-initNum {
				maxNum = prices[i] - initNum
			}
		}
	}
	return maxNum
}

```


