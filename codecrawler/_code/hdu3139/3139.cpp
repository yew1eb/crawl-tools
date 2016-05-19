#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <map>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <stack>
using namespace std;
struct node
{
    int p,d;
} s[10010];
int dis[10030];//保存每种价格的最短距离
int ff[10010];
int f[10010][20];
bool cmp(node a,node b)
{
    if(a.p==b.p)return a.d<b.d;
    return a.p<b.p;
}
void RMQ()
{
    for(int i=1; i<=10010; i++)
        f[i][0]=dis[i];
    int t=floor(log((double)10010)/log(2.0));
    for(int j=1; j<=t; j++)
    {
        for(int i=1; i+(1<<j)-1 <= 10010; i++)
        {
            int s1=f[i][j-1];
            int s2=f[i+(1<<(j-1))][j-1];
            f[i][j]=s1<s2?s1:s2;
        }
    }
}
int query(int s,int e)
{
    int k=0;
    while((1<<(k+1))< e-s+1)
        k++;
    int s1=f[s][k];
 