#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <cctype>
using namespace std;

const int maxn=1e3+10;
struct node{
    int pre,c,t;
    double w;//æå¼
}e[maxn];
int find_where(int n,int r)
{
    int i,j,k,p;
    double maxv=-1;
    for(i=1;i<=n;i++)
    {
        if(i==r)continue;
        if(e[i].w>maxv)
        {
            maxv=e[i].w;
            p=i;
        }
    }
    return p;
}
int main()
{
    int n,r;
    while(scanf("%d%d",&n,&r)!=EOF)
    {
        if(n==0&&r==0)break;
        int i,j,k,a,b,m,p,ans=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&e[i].c);
            e[i].w=e[i].c;
            e[i].t=1;
            ans+=e[i].c;
        }
        for(i=1;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            e[b].pre=a;

        }
        for(i=1;i<n;i++)
        {
            m=find_where(n,r);
            e[m].w=0;
            p=e[m].pre;
            ans+=e[m].c*e[p].t;
            for(j=1;j<=n;j++)
                if(e[j].pre==m)
                e[j].pre=p;
            e[p].c+=e[m].c;
            e[p].t+=e[m].t;
            e[p].w=1.0*e[p].c/e[p].t;
        }
        printf("%d\n",ans);
    }
    return 0;
}
