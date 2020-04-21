---
title: 14-longest-common-prefix
date: 2020-04-21 10:32:15
tags: [strings]
categories: [leetcode]
---


## 最大公共前缀

[题目链接](https://leetcode-cn.com/problems/longest-common-prefix) 

### 题目思路

这题直接暴力算就好了，先找最少的单词数， 然后进行遍历所有字符串数组, 不同直接返回当前最长前缀，相同加上前缀

### go解题思路

```go
func longestCommonPrefix(strs []string) string {
	str := ""
	m := len(strs)
	if m == 0 {
		return str
	}
	min := math.MaxInt32
	for i := 0; i < m; i++ {
		if len(strs[i]) < min {
			min = len(strs[i])
			// fmt.Println(min)
		}
	}
	for i := 0; i < min; i++ {
		for j := 0; j < m; j++ {
			if strs[j][i] != strs[0][i] {
				// fmt.Printf("%c %c", strs[j][i], strs[0][i])
				return str
			}
		}
		str += string(strs[0][i])
	}
	return str
}

```


