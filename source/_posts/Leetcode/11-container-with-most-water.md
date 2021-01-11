---
title: 11-container-with-most-water
date: 2020-04-18 12:50:43
tags: 
categories: [leetcode]
---

## 存水最多的容器

[题目链接](https://leetcode-cn.com/problems/container-with-most-water/) 

### 解体思路
这题想法式我们给两个索引先分别指向开头和末尾, 再去计算两个索引间的最大的存水量与最大存水量判断, 然后再去判断下索引位置的高度，低的那一面往对方靠近,以此类推直到两方索引相等


### go解法

```go
func maxArea(height []int) int {

	secondIndex, firstIndex := len(height)-1, 0
	maxValue := 0
	for {

		if secondIndex <= firstIndex {
			break
		}
		var num int
		lens := secondIndex - firstIndex
		if height[secondIndex] > height[firstIndex] {
			num = height[firstIndex]
			firstIndex++
		} else {
			num = height[secondIndex]
			secondIndex--
		}
		if maxValue < lens*num {
			maxValue = lens * num
		}
	}
	return maxValue
}
```

