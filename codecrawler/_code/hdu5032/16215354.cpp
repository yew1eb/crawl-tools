#include<iostream>
#include<algorithm>
#include<cassert>
#include<string>
#include<sstream>
#include<set>
#include<bitset>
#include<vector>
#include<stack>
#include<map>
#include<queue>
#include<deque>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cctype>
#include<complex>
#include<functional>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;

#define me(s)  memset(s,0,sizeof(s))
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair <int, int> P;

const int N=1000005;
int A,B,m;

struct Point
{
    int x,y;
    ll ans;
    double p;
}s[N],sc[N];

bool cmpp(Point a,Point b){return a.p<b.p;}
bool cmpid(Point a,Point b){return a.y<b.y;}

ll bit[1005]; //xè½´çæå¤§èå´åªæ1000
int lowbit(int x){return x&-x;}
void add(int x,ll v)
{
    while(x<=1000)
    {
        bit[x]+=v;
        x+=lowbit(x);
    }
}

ll query(int x)
{
    ll ans=0;
    while(x>0)
    {
        ans+=bit[x];
        x-=lowbit(x);
    }
    return ans;
}

int main()
{
    int T;
    int cnt=0;
    scanf("%d",&T);
    for(int i=1;i<=1000;i++)
        for(int j=1;j<=1000;j++)
            s[cnt++]=Point{i,j,0,1.0*j/i};
    sort(s,s+cnt,cmpp);
    for(int kase=1;kase<=T;kase++)
    {
        scanf("%d%d",&A,&B);
        scanf("%d",&m);
        int a,b,x;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            scanf("%d",&x);
            sc[i]=Point{x,i,0,1.0*b/a};
        }
        sort(sc,sc+m,cmpp);
        me(bit);
        int now=0;
        for(int i=0;i<m;i++)
        {
            while(s[now].p<=sc[i].p)//åªè¦æçå°äºå½åè¯¢é®ç¹çæçï¼å°±ç»§ç»­æ§è¡addæä½
            {
                add(s[now].x,(ll)(s[now].x+A)*(s[now].y+B));
                now++;
            }
            sc[i].ans=query(sc[i].x);
        }
        sort(sc,sc+m,cmpid);//ææè¯¢é®ç¹çç­æ¡é½å¾å°åï¼è¿æç§å®ä»¬çidæåº
        printf("Case #%d:\n",kase);
        for(int i=0;i<m;i++)
            printf("%I64d\n",sc[i].ans);
    }

}
