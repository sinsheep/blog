---
title: 17-letter-combinations-of-a-phone-number
date: 2020-04-26 16:00:22
tags: [dfs]
categories: [leetcode]
---

[题目链接](https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/) 

## 电话号码的字母组合

### 题目思路

对数字进行dfs搜索即可

### go题目解法

```go

var dic = []string{
	"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz",
}

func dfs(nums *[]string, num, tmp string) {
	if len(num) == 0 {
		*nums = append(*nums, tmp)
		return
	}
	l := num[0] - '0'
	for i := 0; i < len(dic[l]); i++ {
		dfs(nums, num[1:], tmp+string(dic[l][i]))
	}
}

func letterCombinations(digits string) []string {
	var nums []string
	if len(digits) != 0 {

		dfs(&nums, digits, "")
	}
	return nums
}

```


