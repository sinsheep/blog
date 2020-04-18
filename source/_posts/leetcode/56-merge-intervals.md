---
title: 56-merge-intervals
date: 2020-04-16 09:53:36
tags: [sort]
categories:[leetcode]
---

## 合并区间

[题目链接](https://leetcode-cn.com/problems/merge-intervals/) 
### 解题目思路

这题先排序,然后再去判断区间是否有交集，有交集就合并

### go语言思路

```go
func merge(intervals [][]int) [][]int {

	if len(intervals) == 0 {
		return intervals
	}
	sort.Slice(intervals, func(i, j int) bool {
		return intervals[i][0] < intervals[j][0]
	})
	start := 0
	for i := 1; i < len(intervals); i++ {
		fmt.Println(intervals[start][1] >= intervals[i][0])
		if intervals[start][1] < intervals[i][0] {
			if start != i {
				start++
				copy(intervals[start], intervals[i])
			}
			continue
		}
		if intervals[start][1] < intervals[i][1] {
			intervals[start][1] = intervals[i][1]
		}
	}
	return intervals[:start+1]
}
```


