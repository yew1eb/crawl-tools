#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <string>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <list>
#include <map>
#include <set>
#define sss(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define mem1(a) memset(a,-1,sizeof(a))
#define mem(a) memset(a,0,sizeof(a))
#define ss(a,b) scanf("%d%d",&a,&b)
#define s(a) scanf("%d",&a)
#define p(a) printf("%d\n", a)
#define INF 0x3f3f3f3f
#define w(a) while(a)
#define PI acos(-1.0)
#define LL long long
#define eps 10E-9
#define N 1000000+20
#define mod 1000000007
#define _min(x, y) ((x)<(y)?(x):(y))
using namespace std;
void mys(int& res)
{
    int flag=0;
    char ch;
    while(!(((ch=getchar())>='0'&&ch<='9')||ch=='-'))
        if(ch==EOF)  res=INF;
    if(ch=='-')  flag=1;
    else if(ch>='0'&&ch<='9')  res=ch-'0';
    while((ch=getchar())>='0'&&ch<='9')  res=res*10+ch-'0';
    res=flag?-res:res;
}
void myp(int a)
{
    if(a>9)
        myp(a/10);
    putchar(a%10+'0');
}
/*************************THE END OF TEMPLATE************************/
int n, p[N];
int s[N];
int str[N];
void kp()
{
    int i;
    int mx = 0;
    int id;
 //   for(i=n; str[i]!=0; i++)
 //       str[i] = 0;
    for(i=1; i<n; i++)
    {
        if( mx > i )
            p[i] = _min( p[2*id-i], p[id]+id-i );
        else
            p[i] = 1;
        for(; str[i+p[i]] == str[i-p[i]]; p[i]++)
            ;
        if( p[i] + i > mx )
        {
            mx = p[i] + i;
            id = i;
        }
    }
}
void init()
{
    int i, j, k;
    str[0] = -1;
    str[1] = -2;
    for(i=0; i<n; i++)
    {
        str[i*2+2] = s[i];
        str[i*2+3] = -2;
    }
    n = n*2+2;
    s[n] = 0;
}
int main()
{
    int t;
    int time=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)  s(s[i]);
        init();//manacheræ¨¡æ¿
        kp();//manacheræ¨¡æ¿
        int top = 0;
        for(int i=1; i<n; i+=2){//æä¸¾å ä¼å
              if((p[i]-1)>1 && !((p[i]-1)%2)){//åæä¸²é¿åº¦å¿ç¶è¦å¤§äºä¸å¹¶ä¸ä¸ºå¶æ°
                    for(int j=p[i]-1; j>top; j-=2){//å½ç®åè§£å°äºtopæ¶å°±æ²¡å¿è¦è¿è¡äºï¼ç»§ç»­èµ°ä¼è¶æ¶
                         if(p[j+i]-1 >= j) {
                                top = (j);
                                break;
                         }
                    }
              }
        }
        printf("Case #%d: ",time++);
        printf("%d\n",top/2*3);
    }
    return 0;
}
/*
1
13
1 2 2 1 1 2 3 3 2 1 1 2 3

1
11
1 1 2 1 1 2 1 1 2 1 1
*/
