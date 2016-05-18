#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef __int64 LL;
const int INF=1e9;
const int maxn=3000;
struct node{
    int x,y,r;
 }e[11],f[11];
int ans,map[55][55];
int get_sum(int a)
{
    int s=0;
    while(a)
    {
        if(a&1)s++;
        a=a>>1;
    }
    return s;
}
void find(int x,int n)
{

    int i=0,j,k,t=0,tt;
    tt=get_sum(x);
    if(tt>=ans)return;
    while(x)
    {
        if(x&1)
        {
            f[t++]=e[i];
        }
        x=x>>1;
        i++;
    }
    //cout<<t<<endl;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(map[i][j])continue;
            for(k=0;k<t;k++)
            {
                if(abs(f[k].x-i)+abs(f[k].y-j)<=f[k].r)break;
            }
            if(k>=t)return;
        }
    }
    ans=tt;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)break;
        int i,j,k,m,t,p,q;
        memset(map,0,sizeof(map));
        ans=INF;
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&e[i].x,&e[i].y);
            map[e[i].x][e[i].y]=1;
        }
        for(i=0;i<m;i++)
        scanf("%d",&e[i].r);
        find((1<<m)-1,n);
        //cout<<n<<endl;
        if(ans==INF){printf("-1\n");continue;}
        for(i=0;i<(1<<m);i++)
            find(i,n);
        printf("%d\n",ans);
    }
    return 0;
}