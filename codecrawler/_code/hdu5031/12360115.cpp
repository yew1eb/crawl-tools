#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<map>
#include<time.h>
#include<set>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#define inf 0x7fffffff
#define lc l,m,index<<1
#define rc m+1,r,index<<1|1
#define max_n 10005
#define mod 10000007
#define FOR(i,s,t) for(int i=(s);i<=(t);++i)
#define LL __int64
int A[max_n][max_n];
int n,m;
struct node
{
    int num;
    int x[100];
    int y[100];
}kep[max_n];
int ans;
void solve()
{

    while(1)
    {
        int mx=-inf;
        int mind;
        int sum=0;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(!A[i][j]) continue;
                for(int dx=0;dx<=n;dx++)
                {
                    for(int dy=0;dy<=m;dy++)
                    {
                        if(i==dx && j==dy) continue;
                        if(!A[dx][dy])  continue;
                        int x=dx-i;
                        int y=dy-j;
                        int x1=dx,y1=dy;
                        kep[sum].num=1;
                        kep[sum].x[0]=i;
                        kep[sum].y[0]=j;
                        while(x1>=0 && x1<=n && y1>=0 && y1<=m)
                        {
                            if(!A[x1][y1]) break;
                            kep[sum].x[kep[sum].num]=x1;
                            kep[sum].y[kep[sum].num]=y1;
                            kep[sum].num++;
                            x1+=x;
                            y1+=y;
                            if(kep[sum].num>mx)
                            {
                                mx=kep[sum].num;
                                mind=sum;
                            }
                        }
                        sum++;
                    }
                }
            }
        }
        if(mx==-inf) break;
       // printf("asdfasdf\n");
        for(int i=0;i<kep[mind].num;i++)
        {
          //  printf("%d %d\n",kep[mind].x[i],kep[mind].y[i]);
            A[kep[mind].x[i]][kep[mind].y[i]]--;
        }
        ans++;
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        ans=0;
        scanf("%d%d",&n,&m);
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            scanf("%d",&A[i][j]);
        }
        solve();
        printf("%d\n",ans);
    }
    return 0;
}