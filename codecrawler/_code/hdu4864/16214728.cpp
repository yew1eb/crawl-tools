#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

#define LL __int64
const int maxn=1e5+10;
struct node{
    int x,y;
}e[maxn],f[maxn];
int c[101];
int cmp(node a,node b)
{
    if(a.x==b.x)return a.y>b.y;
    return a.x>b.x;
}
int main()
{
    //freopen("C:\\Documents and Settings\\Administrator\\ÃÃÃÃ¦\\in.txt","r",stdin);
    //freopen("C:\\Documents and Settings\\Administrator\\ÃÃÃÃ¦\\out.txt","w",stdout);
    //double a = clock();
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int i,j,k,num=0;
        LL ans=0;
        for(i=0;i<n;i++)
            scanf("%d%d",&e[i].x,&e[i].y);
        for(i=0;i<m;i++)
            scanf("%d%d",&f[i].x,&f[i].y);
        sort(e,e+n,cmp);
        sort(f,f+m,cmp);
        memset(c,0,sizeof(c));
        for(i=0,j=0;i<m;i++)
        {
            while(j<n&&e[j].x>=f[i].x)
            {
                c[e[j].y]++;
                j++;
            }
            for(k=f[i].y;k<=100;k++)
            {
                if(c[k])
                {
                    num++;
                    c[k]--;
                    ans=ans+500*f[i].x+2*f[i].y;
                    break;
                }
            }
        }
        printf("%d %I64d\n",num,ans);
    }
    //double b = clock();
    //printf("%lf\n", (b - a) / CLOCKS_PER_SEC);
    return 0;
}
