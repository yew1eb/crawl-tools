#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
    int m;
    int v;
}a[101];
int cmp(node x,node y)
{
    if(y.m<x.m)
        return 1;
    else
        return 0;
}
int main()
{
    int n,m,i,sum;
    while (scanf("%d",&m),m)
    {
        sum=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d%d",&a[i].m,&a[i].v);
        sort(a,a+n,cmp);
        for(i=0;i<n;i++)
        {
            if(m-a[i].v>0)
            {
                sum+=(a[i].v*a[i].m);
                m=m-a[i].v;
            }
            else
            {
                sum+=m*a[i].m;
                break;
            }
        }
        printf("%d\n",sum);
    }
}
