---
title: 9-palindrome-number
date: 2020-04-12 18:04:23
tags: [string handling]
categories: [leetcode]
---

[题目链接](https://leetcode-cn.com/problems/palindrome-number/) 

## 回文数字

这题比较简单，直接转成字符串然后判断对应回文位置的正确即可


### go 解法
```go
func isPalindrome(x int) bool {
	if x < 0 {
		return false
	}
	var s string = strconv.Itoa(x)
	slen := len(s)
	for i := 0; i < slen/2; i++ {
		if s[i] != s[slen-i-1] {
			return false
		}
	}
	return true
}
```



