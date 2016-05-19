#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"algorithm"
#define inf 999999999
using namespace std;
int set[1001];
int find(int x)
{
    if(set[x]==x)return x;
    set[x]=find(set[x]);
    return set[x];
}
struct node
{
    int a,b,c;
}A[10001];
int cmp(node a,node b)
{
    return a.c<b.c;
}
int main()
{
    int n,m;
    int i,j;
    int x,y;
    while(scanf("%d%d",&n,&m)!=-1)
    {
        for(i=0;i<n;i++)
            set[i]=i;
        for(i=0;i<m;i++)
            scanf("%d%d%d",&A[i].a,&A[i].b,&A[i].c);
        sort(A,A+m,cmp);
        int ans,t;
        t=0;
        ans=0;
        for(i=0;i<m;i++)
        {
            x=find(A[i].a);
            y=find(A[i].b);
            if(x!=y)
            {
                t++;
                ans+=A[i].c;
                set[x]=y;
            }
        }
        if(t!=n-1)printf("impossible\n");
        else 
            printf("%d\n",ans);
        printf("\n");
    }
    return 0;
}
