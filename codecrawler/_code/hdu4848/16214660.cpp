/******************************************************
* @author:xiefubao
*******************************************************/
#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <string.h>
//freopen ("in.txt" , "r" , stdin);
using namespace std;

#define eps 1e-8
#define zero(_) (abs(_)<=eps)
const double pi=acos(-1.0);
typedef long long LL;
const int Max=40;
const LL INF=0x3FFFFFFF;
int dist[49][49];
int num[Max];
int n;
int ans=0;
int bit[31];
void dfs(int state,int sum,int before,int remind,int have)
{
    if(state==0)
    {
        ans=min(ans,sum);
        return ;
    }
    if(sum>=ans)
        return ;
    for(int i=1; i<n; i++)
    {
        if((state&bit[i])&&have+dist[before][i]>num[i])
            return ;
    }
    for(int i=1; i<n; i++)
    {
        if((state&bit[i])&&have+dist[before][i]<=num[i])
        {
            dfs(state-bit[i],sum+dist[before][i]*remind,i,remind-1,have+dist[before][i]);
        }
    }
}
int main()
{
    for(int i=0; i<=30; i++)
        bit[i]=1<<i;
    while(scanf("%d",&n)==1)
    {
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                scanf("%d",dist[i]+j);
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                for(int k=0; k<n; k++)
                {
                    dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k]);
                }
        for(int i=1; i<n; i++)
            scanf("%d",num+i);
        ans=0x3FFFFFFF;
        dfs(bit[n]-2,0,0,n-1,0);
        if(ans==0x3FFFFFFF)
            ans=-1;
        printf("%d\n",ans);
    }
    return 0;
}
