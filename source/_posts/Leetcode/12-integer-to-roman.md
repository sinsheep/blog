---
title: 12-integer-to-roman
date: 2020-04-24 09:13:33
tags: 
categories: [leetcode]
---


## 数字转罗马数字

[题目链接](https://leetcode-cn.com/problems/integer-to-roman/) 

### 题目思路

从大到小判断如果value的值大于num就相减

### go解法

```go
func intToRoman(num int) string {
	sum := ""
	value := []int{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}
	key := []string{
		"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I",
	}
	for i := 0; i < 13; i++ {
		for num >= value[i] {
			sum += key[i]
			num -= value[i]
		}
	}

	return sum

}

```


