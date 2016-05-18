#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <iterator>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <cctype>
using namespace std;

#define si1(a) scanf("%d",&a)
#define si2(a,b) scanf("%d%d",&a,&b)
#define sd1(a) scanf("%lf",&a)
#define sd2(a,b) scanf("%lf%lf",&a,&b)
#define ss1(s)  scanf("%s",s)
#define pi1(a)    printf("%d\n",a)
#define pi2(a,b)  printf("%d %d\n",a,b)
#define mset(a,b)   memset(a,b,sizeof(a))
#define forb(i,a,b)   for(int i=a;i<b;i++)
#define ford(i,a,b)   for(int i=a;i<=b;i++)

typedef long long LL;
const int N=3100100;
const int mod=1000007;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-7;

int pr[N];
int s[N];

void prime()
{
    mset(pr,0);
    forb(i,2,N)
    {
        if(pr[i]==0)
            for(int j=i+i;j<N;j+=i)
                pr[j]=1;
    }
}

int sn(int k)
{
    int t=3*k+7;
    if(pr[t]==0)//素数
        return 1;
    else
        return 0;
}

void suan()
{
    s[0]=0;
    s[1]=0;
    ford(i,2,1001100)
        s[i]=(s[i-1]+sn(i));
}

int main()
{
//    freopen("input.txt","r",stdin);
    int T;
    si1(T);
    prime();
    suan();
    while(T--)
    {
        int n;
        si1(n);
        pi1(s[n]);
    }

    return 0;
}