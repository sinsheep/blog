---
title: 78-subsets
date: 2020-04-21 11:47:33
tags: [violent]
categories: [leetcode]
---

## 子集

[题目链接](https://leetcode-cn.com/problems/subsets) 

### 题目思路

循环遍历，然后遇到对已经的到的子集加上但前数字即可

### go解法

```go

func subsets(nums []int) [][]int {
	var numSubset [][]int
	numSubset = append(numSubset, []int{})
	for i := 0; i < len(nums); i++ {
		m := len(numSubset)
		for j := 0; j < m; j++ {
			tmp := make([]int, len(numSubset[j]))
			copy(tmp, numSubset[j])
			tmp = append(tmp, nums[i])
			// fmt.Println(tmp, nums[i], i)
			// fmt.Println(tmp, j)
			numSubset = append(numSubset, tmp)
			// fmt.Println(j)
		}
	}
	return numSubset
}


```

