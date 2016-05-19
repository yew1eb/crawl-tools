#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <list>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

#define PF(x) (scanf("%d",&x))
#define PT(x,y) (scanf("%d%d",&x,&y))
#define PR(x) (printf("%d\n",x))
#define PRT(x,y)(printf("%d %d\n",x,y))
#define PB(x)(scanf("%I64d",&x))
#define PRB(x)(printf("%I64d\n",(x)))
#define For(i,n) for(int i=0;i<(n);i++)
#define CLR(ar) (memset(ar,0,sizeof(ar)))
#define CLR1(ar) (memset(ar,-1,sizeof(ar)))
#define PBE(x) (scanf("%I64d",&x)!=EOF)
#define Max(x,y) (x)>(y)?(x):(y)
#define Min(x,y) (x)>(y)?(y):(x)
#define L(x) (x<<1)
#define R(x) ((x<<1)|1)
#define Mid(x,y) ((x+y)>>1)

typedef __int64 LL;
#define N 100005
#define M 105
#define Mod 1000
#define Inf 0x7fffffff

void init()
{
    LL n;
    while(PBE(n))
    {
        if(n==1) puts("0");
        else if(n==2) puts("16");
        else 
        {
            LL many = n*n*n;
            many = many*(many-1)/2;
            LL ans = 24+48*(n-2)+30*(n-2)*(n-2)+6*(n-2)*(n-2)*(n-2);
            PRB(many-ans/2);
        }
    }
    return ;
}

int main()
{
    init();
    return 0;
}


