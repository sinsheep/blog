---
title: 13-roman-to-integer
date: 2020-04-19 09:12:12
tags: 
categories: [leetcode]
---


## 罗马数字转数字

[题目链接](https://leetcode-cn.com/problems/roman-to-integer/) 

### 解题思路
倒序遍历判断下就好了，只要前面的数比后面的小，就减去

### go代码

```golang

func romanToInt(s string) int {
	num := 0
	value := map[byte]int{
		'I': 1,
		'V': 5,
		'X': 10,
		'L': 50,
		'C': 100,
		'D': 500,
		'M': 1000,
	}
	num = value[s[len(s)-1]]
	for i := len(s) - 2; i >= 0; i-- {
		if value[s[i]] < value[s[i+1]] {
			num -= value[s[i]]
		} else {
			num += value[s[i]]
		}
	}
	return num
}

```
