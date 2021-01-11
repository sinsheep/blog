---
title: merge-sort 
date: 2020-11-15 19:03
tags: [merge-sort]
categories: [algorithm] 
---

## 并归排序

并归排序是将两个有序的子序列和并得到一个完整的有序子序列,通过分治法将序列分成多个子序列进行并归排序 ，速度仅仅次与快速排序，为稳定排序算法，一般对总体无序，但是各个子项相对有序的数列

### 时间复杂度

>平均时间复杂度O(nlogn)  
 最佳时间复杂度O(n)

### 基本思想

- 分解: 将n个元素分解成含n/2个元素的子序列
- 合并: 用合并排序法对两个子序列进行排序


### 动图演示

![merge-sort](https://pic4.zhimg.com/v2-a29c0dd0186d1f8cef3c5ebdedf3e5a3_b.webp) 


### 代码实现

```c++
#include<bits/stdc++.h>
using namespace std;
void merge(int arr[],int L,int M,int R){
    int leftSize=M-L;
    int rightSize=R-M+1;
    int left[leftSize];
    int right[rightSize];
    for(int i=L;i<M;i++){
        left[i-L]=arr[i];
    }
    for(int i=M;i<=R;i++){
        right[i-M]=arr[i];
    }
    int i=0,j=0,k=L;
    while(i<leftSize&&j<rightSize){
        if(left[i]>right[j]){
            arr[k]=right[j];
            k++;
            j++;
        }else{
            arr[k]=left[i];
            k++;
            i++;
        }
    }
    while(i<leftSize){
        arr[k]=left[i];
        k++;
        i++;
    }
    while(j<rightSize){
        arr[k]=right[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[],int L,int R){
    if(L==R){
        return ;
    }else{
        int M=(L+R)/2;
        mergeSort(arr,L,M);
        mergeSort(arr,M+1,R);
        merge(arr,L,M+1,R);
    }
}
int main(){

    int arr[]={8,2,5,3,6,1,7,4};
    int arr2[]={2,5,6,8,1,3,4,7};
    mergeSort(arr,0,7);
    // merge(arr2,0,4,7);
    for(int i=0;i<8;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}
```


