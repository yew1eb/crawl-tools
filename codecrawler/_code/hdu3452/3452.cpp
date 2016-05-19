/* ***********************************************
Author :rabbit
Created Time :2014/3/9 21:30:26
File Name :A.cpp
************************************************ */
#pragma comment(linker, "/STACK:102400000,102400000")
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <string>
#include <time.h>
#include <math.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
#define INF 0x3f3f3f3f
#define eps 1e-8
#define pi acos(-1.0)
typedef long long ll;
const int maxn=2020;
int head[maxn],tol;
struct Edge{
    int next,to,val;
}edge[10*maxn];
void add(int u,int v,int w){
    edge[tol].to=v;
    edge[tol].next=head[u];
    edge[tol].val=w;
    head[u]=tol++;
}
int dp[maxn];
void dfs(int u,int fa){
    int d=0;
    for(int i=head[u];i!=-1;i=edge[i].next){
        int v=edge[i].to;
        if(v==fa)continue;
        dfs(v,u);
        d+=min(dp[v],edge[i].val);
    }
    if(d)dp[u]=d;
}
int main()
{
     //freopen("data.in","r",stdin);
     //freopen("data.out","w",stdout);
     int n,r;
     while(~scanf("%d%d",&n,&r)&&(n||r)){
         memset(head,-1,sizeof(head));tol=0;
         for(int i=1;i<n;i++){
             int j,k,m;
             scanf("%d%d%d",&j,&k,&m);
             add(j,k,m);
             add(k,j,m);
         }
         memset(dp,0x3f,sizeof(dp));
         dfs(r,-1);
         if(n==1)puts("0");
         else cout<<dp[r]<<endl;
     }
     return 0;
}