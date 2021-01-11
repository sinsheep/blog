---
title: 22-generate-parentheses
date: 2020-04-13 18:18:06
tags: [enumerate]
categories: [leetcode]
---

## 匹配括号

[题目链接](https://leetcode-cn.com/problems/generate-parentheses/) 
### 思路

这题这届枚举一下就好了，但是生成时候前括号的数一定要大于后括号

### go解体犯法

```go
func generateParenthesis(n int) []string {
	var par []string
	pair(n, n, "", &par)
	return par
}

func pair(pre, end int, sum string, par *[]string) {

	if pre == 0 && end == 0 {
		*par = append(*par, sum)
		return
	}
	if pre <= end {
		if pre >= 0 {
			pair(pre-1, end, sum+"(", par)
		}

		if pre < end {
			pair(pre, end-1, sum+")", par)
		}
	}
}

```


