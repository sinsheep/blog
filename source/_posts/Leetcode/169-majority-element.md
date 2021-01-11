---
title: 169-majority-element
date: 2020-04-12 20:04:15
tags: [code math]
categories: [leetcode]
---

## 多组元素

[题目链接](https://leetcode-cn.com/problems/majority-element/) 
### 想法
这个题目必有人有半数人以上得票, 所以可以用摩尔投票法进行操作。对每两个不同的元素相消, 最后可以得到一个数即为数组中多于半数的数值, 这题还有个投机取巧的方法就是快排后在取数组前半部分的任意值
#### 摩尔投票法
摩尔投票算法是一种使用线性时间和常数空间查找大部分元素序列的算法。它以1981年出版的Robert S. Boyer和J Strother Moore的名字命名，并且是流式算法的典型例子。

最简单的形式就是，查找输入中重复出现超过一半以上(n/2)的元素。如果序列中没有这种元素，算法不能检测到正确结果，将输出其中的一个元素之一。如果不能保证输入数据中有占有一半以上的元素，需要再遍历一下验证。

### go语言实现

```go
func majorityElement(nums []int) int {
	var maxNum, count int
	for i := 0; i < len(nums); i++ {
		if count == 0 {
			maxNum = nums[i]
		}
		if maxNum == nums[i] {
			count++
		} else {
			count--
		}
	}
	return maxNum
}
```
#### 投机取巧方法

```go
func majorityElementEasy(nums []int) int {

	sort.Ints(nums)
	return nums[0] //0--len(nums)/2 都可以
}
```
