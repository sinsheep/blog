---
title: interview-56
date: 2020-04-28 17:28:11
tags: [biteWise]
categories: [leetcode,interview]
---

## 数字中之出现一次的数字

[题目链接](https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/) 

### 题目思路

位运算 即可

### go解法

```go
func singleNumbers(nums []int) []int {
	numbers := make([]int, 2)
	var flag int

	for i := 0; i < len(nums); i++ {
		flag ^= nums[i]
	}

	div := 1

	for (div & flag) == 0 {
		div <<= 1
	}
	numbers[0] = 0
	numbers[1] = 0
	for i := 0; i < len(nums); i++ {
		if (div & nums[i]) == 0 {
			numbers[0] ^= nums[i]
		} else {
			numbers[1] ^= nums[i]
		}
	}

	return numbers
}
```


