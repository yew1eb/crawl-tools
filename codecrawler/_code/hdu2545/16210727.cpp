#include"stdio.h"
#include"string.h"
#define N 100011
int n,m;
int pre[N];
int dis[N];
void build()
{
    int i;
    for(i=1;i<=n;i++)    {pre[i]=i;dis[i]=0;}
}
int find(int k)
{
    int temp;
    if(pre[k]==k)    return k;
    temp=pre[k];
    pre[k]=find(temp);
    dis[k]+=dis[temp];
    return pre[k];
}
void Union(int a,int b)
{
    pre[a]=b;
    dis[a]=1;
}
int main()
{
    int i,l;
    int a,b;
    int t;
    while(scanf("%d%d",&n,&m),n||m)
    {
        build();
        for(i=1;i<n;i++)    {scanf("%d%d",&a,&b);Union(b,a);}
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            t=find(a);
            t=find(b);
            if(dis[a]<=dis[b])    printf("lxh\n");
            else                printf("pfz\n");
        }
    }
    return 0;
}