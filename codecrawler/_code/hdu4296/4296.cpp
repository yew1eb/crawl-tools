#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define LL long long
struct point
{
    int w,s;
}node[100005];
int n;
bool cmp(const point &a,const point &b)
{
    return a.w+a.s<b.w+b.s;
}
int main()
{
    for(;~scanf("%d",&n);)
    {
        for(int i=0;i<n;++i)
            scanf("%d%d",&node[i].w,&node[i].s);
        sort(node,node+n,cmp);
        LL summ=0,maxx=0;
        for(int i=0;i<n;++i)
        {
            maxx=max(maxx,summ-node[i].s);
            summ+=node[i].w;
        }
        printf("%I64d\n",maxx);
    }
    return 0;
}