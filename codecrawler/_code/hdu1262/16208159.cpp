#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
#define LL __int64
const int maxn=1e4+10;
int prime[maxn],t,vis[maxn];
struct node{
    int a,b;
    node(){a=0;b=10000;}
}e[maxn];
void init()
{
    int i,j,k;
    memset(vis,0,sizeof(vis));
    t=0;
    prime[t++]=1;
    for(i=2;i<maxn;i++)//æ¾åºå°äº10000çææç´ æ°ã
    {
        if(!vis[i])
        {
            for(j=i*i;j<maxn;j+=i)
            vis[j]=1;
            prime[t++]=i;
        }
    }
    for(i=0;i<t;i++)
    {
        for(j=i;j<t;j++)
        {
            int temp=prime[i]+prime[j];
            if(temp>10000)break;
            if(prime[j]-prime[i]<e[temp].b-e[temp].a)
            {
                e[temp].a=prime[i];
                e[temp].b=prime[j];
            }
        }
    }
}
int main()
{
    init();
    int n;
    while(cin>>n)
    {
        cout<<e[n].a<<" "<<e[n].b<<endl;
    }
    return 0;
}
