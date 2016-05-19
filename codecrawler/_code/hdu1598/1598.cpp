#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int max_s = 1007;
int f[207];
struct node
{
    int a,b,w;
}p[max_s];
int n;
int cmp(const void *a,const void *b)
{
    return (*(node*)b).w-(*(node*)a).w;
}
void init()
{
    for(int i=0;i<=n;i++)
    f[i]=i;
}
int find(int a)
{
    if(f[a]!=a)
    f[a]=find(f[a]);
    return f[a];
}
void Union(int a,int b)
{
    int x=find(a);
    int y=find(b);
    if(x!=y)
    f[y]=x;
}

int main()
{
    //freopen("d.txt","r",stdin);
    int m,i,j,op;
    while(~scanf("%d%d",&n,&m))
    {
        for(i=0;i<m;i++)
        scanf("%d%d%d",&p[i].a,&p[i].b,&p[i].w);
        qsort(p,m,sizeof(p[0]),cmp);
        scanf("%d",&op);
        while(op--)
        {
            int s,e;
            scanf("%d%d",&s,&e);
            int min=9999999;
            for(i=0;i<m;i++)
            {
                init();
                for(j=i;j<m;j++)
                {
                    Union(p[j].a,p[j].b);
                    if(find(s)==find(e))
                    {
                        if(min>p[i].w-p[j].w)
                        min=p[i].w-p[j].w;
                        break;
                    }
                }
            }
            if(min!=9999999)
            printf("%d\n",min);
            else
            printf("-1\n");
        }
    }
    return 0;
}