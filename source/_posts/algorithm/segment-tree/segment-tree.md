---
title: segment-tree 
date: 2020-11-15 20:25
tags: [segment-tree]
categories: [algorithm] 
---

## 线段树
线段树是一种二叉搜索树,他将一个区间划分成为一些单元区间，每个单元区间对应线段树中的一个叶节点。可以使用线段树快速查询某一个节点在若干条线段出现的次数时间复杂度为O(log(n))

### 代码实现

```c++
#include <stdio.h>
#define MAXL 100005
void build_tree(int arr[], int tree[], int node, int start, int end)
{
  if (start == end) {
    tree[node] = arr[start];
    return;
  }
  int mid = (start + end) / 2;
  int left_node = node * 2 + 1;
  int right_node = node * 2 + 2;
  build_tree(arr, tree, left_node, start, mid);
  build_tree(arr, tree, right_node, mid + 1, end);
  tree[node] = tree[left_node] + tree[right_node];
}
void update_tree(int arr[], int tree[], int node, int start, int end, int index, int val)
{

  if (start == end) {
    arr[index] = val;
    tree[node] = val;
    return;
  }
  int mid = (start + end) / 2;
  int left_node = 2 * node + 1;
  int right_node = 2 * node + 2;
  if (index >= start && index <= mid) {
    update_tree(arr, tree, left_node, start, mid, index, val);
  } else {
    update_tree(arr, tree, right_node, mid + 1, end, index, val);
  }
  tree[node] = tree[left_node] + tree[right_node];
}
int query_tree(int arr[], int tree[], int node, int start, int end, int l, int r)
{
  if (r < start || l > end) {
    return 0;
  }else if(start == end || (start>=l&&end<=r)){
    return tree[node];
  }
  int mid = (start + end) / 2;
  int left_node = 2 * node + 1;
  int right_node = 2 * node + 2;
  int sum_left = query_tree(arr, tree, left_node, start, mid, l, r);
  int sum_right = query_tree(arr, tree, right_node, mid + 1, end, l, r);

  return sum_left + sum_right;
}
int main()
{

  int arr[] = { 1, 3, 5, 7, 9, 11 };
  int size = 6;
  int tree[MAXL] = { 0 };
  build_tree(arr, tree, 0, 0, size - 1);
  for (int i = 0; i < 15; i++) {
    printf("tree[%d]=%d\n", i, tree[i]);
  }
  puts("");
  update_tree(arr, tree, 0, 0, 5, 4, 6);
  for (int i = 0; i < 15; i++) {
    printf("tree[%d]=%d\n", i, tree[i]);
  }
  printf("%d",query_tree(arr, tree, 0, 0, 5, 2, 5));
  return 0;
}
```

