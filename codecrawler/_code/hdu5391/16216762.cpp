#include<stdio.h>
#include<iostream>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<functional>
#include<string>
#include<algorithm>
#include<time.h>
#include<bitset>
void fre(){freopen("c://test//input.in","r",stdin);freopen("c://test//output.out","w",stdout);}
#define MS(x,y) memset(x,y,sizeof(x))
#define MC(x,y) memcpy(x,y,sizeof(x))
#define MP(x,y) make_pair(x,y)
#define ls o<<1
#define rs o<<1|1
typedef long long LL;
typedef unsigned long long UL;
typedef unsigned int UI;
typedef int Int;
template <class T> inline void gmax(T &a,T b){if(b>a)a=b;}
template <class T> inline void gmin(T &a,T b){if(b<a)a=b;}
using namespace std;
int casenum,casei;
int n,Z;
//åè½ï¼éè¿æ¦çå­¦ï¼å¿«éå¤å®ä¸ä¸ªLLçº§å«çæ°æ¯å¦ä¸ºç´ æ°
LL mul(LL x,LL y,LL Z)//å¤§æ°ç¸ä¹åæ¨¡
{
    LL tmp=x/(long double)Z*y+1e-3;
    return (x*y+Z-tmp*Z)%Z;
}
LL MUL(LL x,LL p,LL Z)
{
    LL y=1;
    while(p)
    {
        if(p&1)y=mul(y,x,Z);
        x=mul(x,x,Z);
        p>>=1;
    }
    return y;
}
bool miller_rabin(LL n)
{
    if(n<=1)return 0;
    if(n==2)return 1;
    if(n%2==0)return 0;
    LL p=n-1;
    srand(time(NULL));
    int TIMES=8;
    for(int i=1;i<=TIMES;i++)
    {
        LL x=rand()%(n-1)+1;
        if(MUL(x,p,n)!=1)return 0;
    }
    return 1;
}
void solve()
{
    scanf("%d",&n);
    if(n==4)printf("2\n");
    else
    {
        if(miller_rabin(n))printf("%d\n",n-1);
        else printf("%d\n",0);
    }
}
int main()
{
    scanf("%d",&casenum);
    for(casei=1;casei<=casenum;casei++)
    {
        solve();
    }
    return 0;
}
/*
ãé¢æã
æ±(n-1)! mod nï¼nå¯è¾¾1e9ã

ãç±»åã
å¨å°éå®ç
ç´ æ°å¤å®

ãåæã
ç´ æ°å¤å®ï¼è¿éæä¾ä¸ç§æ¹æ³ââè´¹é©¬ç±³åç´ æ°æ£éªæ³ã
å¯¹äºä¸ä¸ªç´ æ°ï¼å¿å®æ»¡è¶³ââ
x^(p-1)%p=1 å¯¹äºä»»æçxï¼x<pï¼é½æç«

ãæ¶é´å¤æåº¦&&ä¼åã

ãtrickã

ãæ°æ®ã
Sample Input
2
3
10

Sample Output
2
0

*/