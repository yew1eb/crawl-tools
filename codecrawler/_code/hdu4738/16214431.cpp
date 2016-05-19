//hdu 4738 tarjianæ±æ¡¥
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <vector>
#define inf 0x3f3f3f3f
#define lowbit(x) ((x)&(-x))
#define maxn 1000005
using namespace std;
int dfn[maxn],low[maxn],n,m,ans,head[maxn],cnt,cntt;
struct ee
{
    int next,to,w;
}eage[maxn*2];

void add(int a,int b,int c)
{
    eage[cntt].to=b;
    eage[cntt].w=c;
    eage[cntt].next=head[a];
    head[a]=cntt++;
}

void tarjian(int a,int b)
{
    dfn[a]=low[a]=++cnt;
    for(int i=head[a];i!=-1;i=eage[i].next)
    {
        int j=eage[i].to;
        if(i==(b^1))                                         //æ³¨æåç¹æéè¾¹
            continue;
        if(!dfn[j])
        {
            tarjian(j,i);
            if(low[j]<low[a])
                low[a]=low[j];
            if(low[j]>dfn[a])
               ans=min(ans,eage[i].w);
        }
        else
           low[a]=min(low[a],dfn[j]);
    }
}

int main () {
    //freopen("d:\\in.txt","r",stdin);
    while(scanf("%d%d",&n,&m)==2)
    {
        if(n==0&&m==0)
            break;
        memset(dfn,0,sizeof(dfn));
        memset(low,0,sizeof(low));
        memset(head,-1,sizeof(head));
        cnt=cntt=0;
        ans=inf;
        for(int i=1;i<=m;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            add(a,b,c);
            add(b,a,c);
        }
        int anss=0;
        for(int i=1;i<=n;i++)
        {
            if(!dfn[i])
            {
                anss++;
                tarjian(i,-1);
            }
        }
        if(anss>1)
            printf("0\n");
        else if(ans==inf)
            printf("-1\n");
        else if(ans==0)
            printf("1\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}
