---
title: frogThroughRiver 
date: 2020-12-23 22:55
tags: [dp]
categories: [algorithm, dp] 
---

## 青蛙过河
### description
在河上有一座独木桥，一只青蛙想沿着独木桥从河的一侧跳到另一侧。在桥上有一些石子，青蛙很讨厌踩在这些石子上。由于桥的长度和青蛙一次跳过的距离都是正整数，我们可以把独木桥上青蛙可能到达的点看成数轴上的一串整点：0，1，……，L（其中L是桥的长度）。坐标为0的点表示桥的起点，坐标为L的点表示桥的终点。青蛙从桥的起点开始，不停的向终点方向跳跃。一次跳跃的距离是S到T之间的任意正整数（包括S,T）。当青蛙跳到或跳过坐标为L的点时，就算青蛙已经跳出了独木桥。
题目给出独木桥的长度L，青蛙跳跃的距离范围S,T，桥上石子的位置。你的任务是确定青蛙要想过河，最少需要踩到的石子数。
### input
包含多组测试数据，每组测试数据第一行有一个正整数L（1 <= L <= 1000000000），表示独木桥的长度。第二行有三个正整数S，T，M，分别表示青蛙一次跳跃的最小距离，最大距离，及桥上石子的个数，其中1 <= S <= T <= 10，1 <= M <= 100。第三行有M个不同的正整数分别表示这M个石子在数轴上的位置（数据保证桥的起点和终点处没有石子）。所有相邻的整数之间用一个空格隔开。
### output
每组数据输出一个整数，表示青蛙过河最少需要踩到的石子数。

### solution
本题的数据过大有10^9，所以要将数据离散化处理，对于两个石头之间的距离d超过最大距离t的可以从d%t的位置跳过来所以只要将大于t的数据处理乘d%t+t就可以了，这样数据就会小很多,最多离只有2000，就可以直接dp写了

```c++
#include <bits/stdc++.h>
#define doub(x) (x)*(x)
#define ll long long
using namespace std;
int main(){
  int l,s,m,t,stone[105],vis[4000],dp[2005];
  while(scanf("%d",&l)!=EOF){
    cin>>s>>t>>m;
    memset(vis,0,sizeof(vis));
    memset(dp,0x3f3f3f3f,sizeof(dp));
    stone[0]=0;
    for(int i=1;i<=m;i++){
      cin>>stone[i];
    }
    stone[m+1]=l;
    sort(stone,stone+m+2);
    int cnt=0;
    for(int i=1;i<=m+1;i++){
      if(stone[i]-stone[i-1]>=t) cnt+=(stone[i]-stone[i-1])%t+t;
      else cnt+=(stone[i]-stone[i-1]);
      vis[cnt]=1;
    }
    vis[cnt]=0,dp[0]=0,vis[0]=0;
    for(int i=1;i<=cnt+t-1;i++){
      for(int j=s;j<=t;j++){
        if(i-j>=0){
          dp[i]=min(dp[i],dp[i-j]+vis[i]);
        }
      }
    }
    int ms=0x3f3f3f3f;
    for(int i=cnt;i<=cnt+t-1;i++){
        ms=min(ms,dp[i]);
    }
    cout<<ms<<endl;
  }
  return 0;
}


```


