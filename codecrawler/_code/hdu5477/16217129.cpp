#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#include<map>
#include<stack>
#include<vector>
#define LL long long
#define MAXN 1000010
using namespace std;
const  int N=20;
struct node{
    int l;
    int r;
    bool operator < (const node &b)const
    {
        return l<b.l;
    }
}road[MAXN];
LL ans,c;
int main()
{
//    freopen("D:\\in.txt","r",stdin);
    int T,i,j,cas,n,a,b,len,temp;
    scanf("%d",&T);
    for(cas=1;cas<=T;cas++)
    {
        scanf("%d%d%d%d",&n,&a,&b,&len);
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&road[i].l,&road[i].r);
        }
        ans=0;
        temp=0;
        c=0;
        for(i=1;i<=n;i++)
        {
            c+=b*(road[i].l-temp);
            if(c < (road[i].r-road[i].l)*a)
            {
                ans+=((road[i].r-road[i].l)*a-c);
                c=0;
            }
            else
            {
                c-=(road[i].r-road[i].l)*a;
            }
            temp=road[i].r;
        }
        printf("Case #%d: %I64d\n",cas,ans);
    }
      return 0;
}