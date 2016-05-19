#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int p[10000005];
int vis[10000005];
int maxx;
inline void make_set(int n)
{
    p[n]=n;
}
int find_set(int i)
{
    int j=i;
    while(j!=p[j])
    {
        j=p[j];
    }
    return p[i]=j;
}
int Union(int a,int b)
{
    a=find_set(a);
    b=find_set(b);
    if(a==b)
    {
        //vis[a]++;
        //if(vis[a]>maxx)
           // maxx=vis[a];
        return 0;
    }
    else
    {
        p[a]=b;
        vis[b]+=vis[a];
        if(vis[b]>maxx)
            maxx=vis[b];
        return 1;
    }
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int i;
        maxx=0;
        if(n==0)
        {
            printf("1\n");
            continue;
        }
        memset(vis,0,sizeof(vis));
        memset(p,0,sizeof(p));

        for(i=0;i<n;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            if(!vis[a])
            {
                vis[a]=1;
                make_set(a);
            }
            if(!vis[b])
            {
                vis[b]=1;
                make_set(b);
            }
            Union(a,b);

        }
        printf("%d\n",maxx);
    }
    return 0;
}
