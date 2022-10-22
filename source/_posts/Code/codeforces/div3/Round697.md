---
title: codeforces#697(div3)
date: 2021-01-26 21:12
tags: [codeforces]
categories: [codeforces] 
---
[比赛地址](https://codeforces.com/contest/1475) 
## A. Odd Divisor
### 题意

给一个数字然后看能否找出能整除它的奇数(1 除外)能就输出YES 不能就输出NO
### 思路
如果是奇数直接输出YES 如果是偶数就一直除以2看是否是奇知道数字小于1 其中有奇数就输出YES 没有就输出NO ### code
```cpp
#include<bits/stdc++.h>
#define ll long long 
#define fi first
#define se second
#define inf 0x3f3f3f3f;
#define Fep(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define Rep(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define see(x) cout << (x) << '\n'
typedef double db;
using namespace std;
typedef pair<int,int> pii;
void check(ll x){
    
    while(x>1){
        if(x%2){cout<<"YES"<<endl;return;}
        x>>=1;
    }
    cout<<"NO"<<endl;
}
int main(){
    ll t, n;
    cin>>t;
    while(t--){
        cin>>n;
        check(n);
    }
    return 0;
}

```
## B. New Year's Number

### 题意
给出一个数字看它是否有a个2020和b个2021组成 ($a,b>=0$)

### 思路
因为2020 和2021相差1 所以我们先把所有数字出以2020 然后看余数是否大于整除的结果如果是将没有足够的2020变成2021就输出NO,如果不是输出YES

```cpp
#include<bits/stdc++.h>
#define ll long long 
#define fi first
#define se second
#define inf 0x3f3f3f3f;
#define Fep(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define Rep(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define see(x) cout << (x) << '\n'
typedef double db;
using namespace std;
typedef pair<int,int> pii;
int main(){
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        int q=n/2020,s=n%2020;
        // cout<<q<<" "<<s<<endl;
        if(s<=q){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}

```

## C. Ball in Berland

### 题意
给出有两组人分别位a, b他们有k对组合, 我们要选出两队组合但是其中这两队组合的人员不能冲突，我们要求出符合条件的数量
###  思路
我们对每一个a, b组合人员进行遍历统计他们出现的次数存表, 然后我们在对k队组合进行遍历统计他们和k-a, b组这两个人出现次数再+1, 由于我们也对前面的进行了统计所以要将ans/2

```cpp
#include<bits/stdc++.h>
#define ll long long 
#define fi first
#define se second
#define inf 0x3f3f3f3f;
#define Fep(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define Rep(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define see(x) cout << (x) << '\n'
typedef double db;
using namespace std;
typedef pair<int,int> pii;
const int M=200005;
ll gn[M], bn[M],g[M],bo[M];
int main(){
    ll t, a, b, k;
    cin>>t;
    while(t--){
        cin>>a>>b>>k;
        memset(gn,0,sizeof(gn));
        memset(bn,0,sizeof(bn));
        for(int i=0;i<k;i++){
            cin>>bo[i];
            bn[bo[i]]++;
        }
        for(int i=0;i<k;i++){
            cin>>g[i];
            gn[g[i]]++;
        }
        ll ans=0;
        for(int i=0;i<k;i++){
            ll q=k-bn[bo[i]]-gn[g[i]]+1;
            // cout<<q<<endl;
            ans+=q;
        }
        cout<<ans/2<<endl;
    }
    return 0;
}


```

## D. Clean the Phone

### 题意
我们有n个应用和我们要释放最少m的内存，每一个应用有他的所占空间大小和他的重要性(1, 2), 我们要求得释放不少于m内存同时要求吧这个重要性减少的最小
### 思路

我们可以将1, 2 重要性的应用所占空间分别存储让后从大到小排序举一下当1重要性app被删除多少个同时，2重要性app需要删除多少个，同理对2这么操作就能得到最后答案

```cpp
#include<bits/stdc++.h>
#define ll long long 
#define fi first
#define se second
#define inf 0x3f3f3f3f;
#define Fep(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define Rep(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define see(x) cout << (x) << '\n'
typedef double db;
using namespace std;
typedef pair<int,int> pii;
const int MAXN=2e5+7;
int t, n, m, V[MAXN],tmp;
int main(){
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<ll> a,b;
        for(int i=0;i<n;i++)cin>>V[i];
        for(int i=0;i<n;i++){
            cin>>tmp;
            if(tmp&1)a.push_back(V[i]);
            else b.push_back(V[i]);
        }
        // cout<<a.size()<<" "<<b.size()<<endl;
        sort(a.begin(),a.end(),greater<int>());
        sort(b.begin(),b.end(),greater<int>());
        for(int i=1;i<a.size();i++)a[i]+=a[i-1];
        for(int i=1;i<b.size();i++)b[i]+=b[i-1];
        int ans=INT_MAX;
        auto iter =lower_bound(a.begin(), a.end(), m);
        if(iter!=a.end())ans=min(ans,(int)(iter-a.begin()+1));
        iter = lower_bound(b.begin(), b.end(), m);
        if(iter!=b.end())ans=min(ans,(int)(iter-b.begin()+1)*2);
        for(int i=0;i<a.size();i++){
            iter = lower_bound(b.begin(),b.end(),m-a[i]);
            if(iter!=b.end())ans=min(ans,i+1+(int)(iter-b.begin()+1)*2);
        }
        for(int i=0;i<b.size();i++){
            iter = lower_bound(a.begin(),a.end(),m-b[i]);
            if(iter!=a.end())ans=min(ans,( i+1 )*2+(int)(iter-a.begin()+1));
        }
        cout<<(ans==INT_MAX?-1:ans)<<endl;
    }
    return 0;
}

```

## E. Advertising Agency

### 题意
给你一组数据然后让你取k个出来使得和最大， 问有几种取法
### 思路

我们先对这组数据进行大到小排序 然后看第k个元素在数组中出现了几次记q，这个元素在第一个到第k个元素中出现了几次记m 然后我们需要求组合数从q个里面取m个元素有几种取法，犹豫数据范围很小所以我们可以打个表
```cpp
#include<bits/stdc++.h>
#define ll long long 
#define fi first
#define se second
#define inf 0x3f3f3f3f;
#define Fep(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define Rep(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define see(x) cout << (x) << '\n'
typedef double db;
using namespace std;
typedef pair<int,int> pii;
const int mod=1e9+7;
int dp[1005][1005];
ll solve(int n){
    ll ans=1;
    for(ll i=1;i<=n;i++){
        ans*=i;
        ans%=mod;
    }
    return ans;
}
inline void init(){
    dp[0][0]=1;
    for(int i=1;i<=1000;i++){
        dp[i][0]=dp[i][i]=1;
        for(int j=1;j<i;j++){
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
        }
    }
}
int main(){
    ll t,n,k,arr[10005];
    cin>>t;
    init();
    while(t--){
        cin>>n>>k;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        reverse(arr,arr+n);
        int m=0,s=0;
        for(int i=0;i<n;i++){
            if(arr[i]==arr[k-1]){
                m++;
                if(i<=k-1)s++;
            }
        }
        cout<<dp[m][s]<<endl;
    }
    return 0;
}

```

## F. Unusual Matrix

### 题意

给出两个n行n列的矩阵a，b。 a只能将他的某一列或者某一行异或1看能否变成b不能输出NO

### 思路先将两个数组对应位置异或看他们没两行异或的结果是否为1或者为0
```cpp
#include<bits/stdc++.h>
#define ll long long 
#define fi first
#define se second
#define inf 0x3f3f3f3f;
#define Fep(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define Rep(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define see(x) cout << (x) << '\n'
typedef double db;
using namespace std;
typedef pair<int,int> pii;
const int MAXN=2e5+7;
int t, n, m, V[MAXN],tmp;
int main(){
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<ll> a,b;
        for(int i=0;i<n;i++)cin>>V[i];
        for(int i=0;i<n;i++){
            cin>>tmp;
            if(tmp&1)a.push_back(V[i]);
            else b.push_back(V[i]);
        }
        // cout<<a.size()<<" "<<b.size()<<endl;
        sort(a.begin(),a.end(),greater<int>());
        sort(b.begin(),b.end(),greater<int>());
        for(int i=1;i<a.size();i++)a[i]+=a[i-1];
        for(int i=1;i<b.size();i++)b[i]+=b[i-1];
        int ans=INT_MAX;
        auto iter =lower_bound(a.begin(), a.end(), m);
        if(iter!=a.end())ans=min(ans,(int)(iter-a.begin()+1));
        iter = lower_bound(b.begin(), b.end(), m);
        if(iter!=b.end())ans=min(ans,(int)(iter-b.begin()+1)*2);
        for(int i=0;i<a.size();i++){
            iter = lower_bound(b.begin(),b.end(),m-a[i]);
            if(iter!=b.end())ans=min(ans,i+1+(int)(iter-b.begin()+1)*2);
        }
        for(int i=0;i<b.size();i++){
            iter = lower_bound(a.begin(),a.end(),m-b[i]);
            if(iter!=a.end())ans=min(ans,( i+1 )*2+(int)(iter-a.begin()+1));
        }
        cout<<(ans==INT_MAX?-1:ans)<<endl;
    }
    return 0;
}
 
```

