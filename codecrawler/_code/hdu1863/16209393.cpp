/*Kruskalçå­*/

#include<stdio.h>
#include<algorithm>
using namespace std;
struct all
{
    int u,v,w;//u,vä¸ºè¾¹eçèµ·ç¹ç»ç¹ï¼wä¸ºæå¼
}e[2000];
int p[2000],sum,n,m;
int cmp(all x,all y)
{
    return x.w<y.w;
}
int find(int x)
{
    return p[x]==x?p[x]:find(p[x]);
}
void kruskal()
{
    int i,ans=0;
    for(i=1;i<=m;i++)   p[i]=i;
   
    sort(e+1,e+n+1,cmp);
    for(i=1;i<=n;i++)
    {
        int x=find(e[i].u);
        int y=find(e[i].v);
        if(x!=y)
        {
            sum++;
            ans+=e[i].w;
            p[x]=y;
        }
    }
    if(sum==m)//ä¸è½åçº¯å°ä»¥ææç¹æ¯å¦åºç°æ¥å¤æ­æ¯å¦è½è¿éï¼è¦çç¹ä¸ç¹ä¹é´æ¯å¦è¿éï¼
    printf("%d\n",ans);
    else
    printf("?\n");
}
int main()
{
    while(scanf("%d%d",&n,&m)&&n)
    {
        int i;
        sum=1;
        for(i=1;i<=n;i++)
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
        kruskal();
    }
    return 0;
}
