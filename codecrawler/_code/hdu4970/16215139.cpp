#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <cctype>
using namespace std;

#define LL __int64
const int maxn=1e5+10;
int e[maxn];
LL sum[maxn];
inline int readint()
{
    int x=0;
    char ch;
    ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x;
}
inline LL readint2()
{
    LL x=0;
    char ch;
    ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x;
}
int main()
{
    int n;
    while(n=readint())
    {
        memset(e,0,sizeof(e));
        int i,j,k,m,a,b,c;
        //scanf("%d",&m);
        m=readint();
        for(i=0;i<m;i++)
        {
            //scanf("%d%d%d",&a,&b,&c);
            a=readint();
            b=readint();
            c=readint();
            e[a-1]-=c;
            e[b]+=c;
        }
        sum[n+1]=0;
        LL x=0;
        for(i=n;i>=1;i--)
        {
            x+=e[i];
            sum[i]=sum[i+1]+x;
        }
        //for(i=1;i<=n;i++)printf("%I64d\n",sum[i]);
        int q,y,ans=0;
        //scanf("%d",&q);
        q=readint();
        while(q--)
        {
            //scanf("%I64d%d",&x,&y);
            x=readint2();
            y=readint();
            if(x>sum[y])ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
