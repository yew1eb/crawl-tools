#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
#define LL long long
#define maxn 1<<16
#define mod 1000000007
#define INF 1<<30
int d[maxn],n,m,K;
int ro[maxn][3],p[maxn],vis[maxn];
queue<int>q;
int spfa()
{
    int i,j,st,v,tmp;
    for(i=0;i<(1<<n);i++)d[i]=INF,vis[i]=0;
    q.push(1);d[1]=0;vis[1]=1;
    while(!q.empty())
    {
        st=q.front();q.pop();vis[st]=0;
        for(i=0;i<m;i++)
        {
            if((st&(1<<ro[i][0]))&&(st&(1<<ro[i][1]))) continue;
            if(st&(1<<ro[i][0]))
            {
                tmp=st|(1<<ro[i][1]);
                if(d[tmp]>d[st]+ro[i][2])
                {
                    d[tmp]=d[st]+ro[i][2];
                    if(!vis[tmp]&&d[tmp]<=K)
                    {
                        vis[tmp]=1;
                        q.push(tmp);
                    }
                }
            }
            else if(st&(1<<ro[i][1]))
            {
                tmp=st|(1<<ro[i][0]);
                if(d[tmp]>d[st]+ro[i][2])
                {
                    d[tmp]=d[st]+ro[i][2];
                    if(!vis[tmp]&&d[tmp]<=K)
                    {
                        vis[tmp]=1;
                        q.push(tmp);
                    }
                }
            }
        }
    }
    int ans=0;
    for(i=0;i<(1<<n);i++)if(d[i]<=K)
    {
        int tmp=0;
        for(j=0;j<n;j++)if(i&(1<<j))
            tmp+=p[j];
        ans=max(ans,tmp);
    }
    return ans;
}
int main()
{
    int ncase,i;scanf("%d",&ncase);
    while(ncase--)
    {
        scanf("%d %d %d",&n,&m,&K);
        for(i=0;i<n;i++)scanf("%d",&p[i]);
        for(i=0;i<m;i++)scanf("%d %d %d",&ro[i][0],&ro[i][1],&ro[i][2]);
        for(i=0;i<m;++i)ro[i][0]--,ro[i][1]--;
        printf("%d\n",spfa());
    }
}