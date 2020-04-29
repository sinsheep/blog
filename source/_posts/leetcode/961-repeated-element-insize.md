---
title: 961-repeated-element-insize
date: 2020-04-29 15:09:43
tags: [easy]
categories: [leetcode]
---

## 找重复n词的数字
[题目链接](https://leetcode-cn.com/problems/n-repeated-element-in-size-2n-array/) 

### 思路

索引值数量

### go解法
<++>
```go
func repeatedNTimes(A []int) int {
	var mp [10001]int
	for _,value := range A {
		mp[value]++
		if mp[value] > 1 {
			return value
		}
	}
	return -1
}

```


