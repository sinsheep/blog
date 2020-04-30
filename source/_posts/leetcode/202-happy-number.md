---
title: 202-happy-number 
date: 2020-04-30 06:05:03
tags: 
categories: [leetcode]
---

## 快乐数字

[题目链接](https://leetcode-cn.com/problems/happy-number/) 

### 解体思路

这题这要判断下这个快乐数循环中是否出现重复的值即可，有重复的值他就会无线循环就不是快乐数字

### go解体思路

```go
func isHappy(n int) bool {

	var num map[int]int
	num = make(map[int]int)
	num[n] = 1
	for n != 1 {
		if num[n] > 1 {
			return false
		}
		tmp := 0
		for n != 0 {
			tmp += (n % 10) * (n % 10)
			n /= 10
		}
		n = tmp
		_, ok := num[n]
		if ok != false {
			return false
		} else {
			num[n] = 1
		}
	}
	return true
}
```


