---
title: 28-implement-strstr
date: 2020-04-21 16:42:32
tags: [strings]
categories: [leetcode]
---

## 需找第一次出现字符串的下表

[题目链接](https://leetcode-cn.com/problems/implement-strstr/submissions/) 

### 解体思路
直接用切片判断下就好了

### go解法

```go
func strStr(haystack string, needle string) int {
	n := len(needle)
	m := len(haystack) - n
    if n==0{
        return 0
    }
	for i := 0; i < m+1; i++ {
		if haystack[i:i+n] == needle {
			return i
		}
	}
	return -1
}


```


