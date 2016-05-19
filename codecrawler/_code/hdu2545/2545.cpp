/*
    hdu 2545
    并查集

    求出点到根节点距离
*/
#include <cstdio>
#define maxn 100005
using namespace std;
int dis[maxn],father[maxn];
int m,n;
int find(int x)
{
    if(x == father[x])  return x;
    int temp=father[x];
    father[x]=find(father[x]);
    dis[x]+=dis[temp];
    return father[x];
}
int main()
{
    while(scanf("%d%d",&n,&m))
    {
        if(n==0 && m==0)    break;
        for(int i=1; i<=n; i++)
        {
            father[i]=i;
            dis[i]=0;
        }

        int a,b;
        for(int i=0; i<n-1; i++)
        {
            scanf("%d%d",&a,&b);
            father[b]=a;
            dis[b]=1;
        }

        for(int i=0; i<m; i++)
        {
            scanf("%d%d",&a,&b);
            find(a);
            find(b);
            //printf("father:%d %d\n",father[a],father[b]);
            //printf("dis:%d %d\n",dis[a],dis[b]);
            if(dis[a] <= dis[b])    printf("lxh\n");
            else    printf("pfz\n");
        }
    }
}