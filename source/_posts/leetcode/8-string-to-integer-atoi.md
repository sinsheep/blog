---
title: 8-string-to-integer-atoi
date: 2020-04-20 22:11:41
tags: [strings]
categories: [leetcode]
---

## 字符串转数字

[题目链接](https://leetcode-cn.com/problems/string-to-integer-atoi) 

### 解体思路

这题先去空白符号,  然后在判断第一个字符是那个符号或者数字,是负数符号flag=-1, 然后在对字符串进行遍历,如果遇到非数字就退出，如果数字超过int32[-2^32, 2^32-1]的范围退出, 然后返回flag * 数字和， 这题的坑有+号出现

### go解法

```go
func myAtoi(str string) int {
	var num int
	flag:=1
	str = strings.TrimSpace(str)
	if len(str) == 0 {
		return num
	}
	if str[0] == '-' {
		flag = -1

	} else if str[0] == '+' {
		flag = 1
	} else if str[0] > '9' || str[0] < '0' {
		return num
	} else {
		num = int(str[0] - '0')
	}
	for i := 1; i < len(str); i++ {
		if str[i] > '9' || str[i] < '0' {
			break
		}
		num = num*10 + int(str[i]-'0')
		// fmt.Println(num)
		if num*flag > math.MaxInt32 {
			return math.MaxInt32 
		}
		if num *flag < math.MinInt32 {
			return math.MinInt32
		}
	}
	return num*flag
}

```

