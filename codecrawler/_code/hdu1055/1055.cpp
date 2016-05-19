#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Node
{
    int t;
    int prarent;
    int c;
    double w;
};
Node node[1001];
int n,r;
int find()
{
    double max=0;
    int i,t;
    for(i=1;i<=n;i++)
    {
        if(max<node[i].w && i!=r)
        {
            max=node[i].w;
            t=i;
        }
    }
    return t;
}
int main()
{
    while(scanf("%d%d",&n,&r),n||r)
    {
        int i,n1,n2,co,pos,ans=0;
        for(i=1;i<=n;i++)
        {
            node[i].t=1;
            scanf("%d",&node[i].c);
            node[i].w=node[i].c;
            ans+=node[i].c;
        }
        for(i=1;i<n;i++)
        {
            scanf("%d%d",&n1,&n2);
            node[n2].prarent=n1;
        }
        co=n;
        while(co>1)
        {
            pos=find();
            for(i=1;i<=n;i++)
            {
                if(node[i].prarent==pos)
                {
                    node[i].prarent=node[pos].prarent;
                }
            }
            node[pos].w=0;
            ans+=node[pos].c*node[node[pos].prarent].t;
            node[node[pos].prarent].t+=node[pos].t;
            node[node[pos].prarent].c+=node[pos].c;
            node[node[pos].prarent].w=(double)node[node[pos].prarent].c/node[node[pos].prarent].t;
            co--;
        }

        printf("%d\n",ans);
    }
    return 0;
}