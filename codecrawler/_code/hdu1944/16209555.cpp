/* ***********************************************
Author :rabbit
Created Time :2014/7/4 12:00:18
File Name :3.cpp
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
int f[110],d[20010],g[110];
int SG(int p,int k){
    memset(g,0,sizeof(g));
    for(int i=0;i<k;i++){
        int t=p-f[i];
        if(t<0)break;
        if(d[t]==-1)d[t]=SG(t,k);
        g[d[t]]=1;
    }
    for(int i=0;;i++)
        if(!g[i])return i;
}
int main()
{
     //freopen("data.in","r",stdin);
     //freopen("data.out","w",stdout);
     int n;
     while(~scanf("%d",&n)){
         if(!n)break;
         for(int i=0;i<n;i++)scanf("%d",&f[i]);
         sort(f,f+n);
         memset(d,-1,sizeof(d));
         d[0]=0;
         for(int i=1;i<=10010;i++)
             d[i]=SG(i,n);
         int m;
         scanf("%d",&m);
         while(m--){
             int k;
             scanf("%d",&k);
             int sum=0,v;
             while(k--){
                 scanf("%d",&v);
                 sum^=d[v];
             }
             if(!sum)printf("L");
             else printf("W");
         }
         puts("");
     }
     return 0;
}
