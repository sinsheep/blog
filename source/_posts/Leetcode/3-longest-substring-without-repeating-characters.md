---
title: 3-longest-substring-without-repeating-characters
date: 2020-05-02 11:19:27
tags: [slide window]
categories: [leetcode]
---

## 无重复字符的字符串

[题目链接](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/) 

### 解题思路
滑动窗口

### go代码

```golang

func lengthOfLongestSubstring(s string) int {

	str := make(map[byte]int)
	n := len(s)

	rk, ans := -1, 0
	for i := 0; i < n; i++ {

		if i != 0 {
			delete(str, s[i-1])
		}

		for rk+1 < n && str[s[rk+1]] == 0 {
			str[s[rk+1]]++
			rk++
		}
		if ans < rk+1-i {
			ans = rk + 1 - i
		}
	}
	return ans
}

```
