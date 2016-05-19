#include <cstdio>
#include <stack>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <functional>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <string>
#include <map>
#include <iomanip>
#include <cmath>
#define LL long long
#define ULL unsigned long long
#define SZ(x) (int)x.size()
#define Lowbit(x) ((x) & (-x))
#define MP(a, b) make_pair(a, b)
#define MS(arr, num) memset(arr, num, sizeof(arr))
#define PB push_back
#define F first
#define S second
#define ROP freopen("input.txt", "r", stdin);
#define MID(a, b) (a + ((b - a) >> 1))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lrt rt << 1
#define rrt rt << 1|1
#define root 1,n,1
#define BitCount(x) __builtin_popcount(x)
#define BitCountll(x) __builtin_popcountll(x)
#define LeftPos(x) 32 - __builtin_clz(x) - 1
#define LeftPosll(x) 64 - __builtin_clzll(x) - 1
const double PI = acos(-1.0);
const LL INF = (((LL)1)<<62)+1;
using namespace std;
const double eps = 1e-5;
const int MAXN = 300 + 10;
const int MOD = 1000007;
const double M=1e-8;
const int N=50100;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
const int d[4][2]={{0,1},{0,-1},{-1,0},{1,0}};
int n,m,st[N],lazy[N],a[N];
int p[16]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
LL ans,ip[N];
void init()
{
    int i,j;
    for(i=1;i<N;i++) ip[i]=i;           //初始化i最多有i个与其互质的数
    for(i=1;i<N;i++)
    {
          for(j=i;j<=N;j+=i) ip[j]--;    //i为j的因子，所以j与i不互质，第j个数的互质数减少1
          if(!ip[ip[i]]) ip[ip[i]]=i;     //此时ip[i]存的是不大于i的数与i互质的个数k=ip[i],
           //如果ip[k]=0,表示小于i的所有数中，没有刚好有k个互质数的数
           //故将ip[k]=i，表示刚好有k个与i互质的数个数最小为i
          ip[i]=0; //标记刚好有k个互质数的数没有(不大于i的数不可能存在某个数与其互质的数的个数等于i);
    }
}
void dfs(int k,LL num,LL sum,int limit)
{
    if (sum>n) return ;
    if (sum==n) ans=min(ans,num);
    for (int i=1;i<=limit;i++) {
        if (ans/p[k] <num || sum*(i+1)>n) break;
        num*=p[k];
        if (n%(sum*(i+1))==0)
            dfs(k+1,num,sum*(i+1),i);
    }
}
int main()
{
    int i,j,cnt=1;
    int t;
    init();
    cin>>t;
    while(t--)
    {
        int t;
        scanf("%d%d",&t,&n);
        if (t) {
            ans=ip[n];
        }
        else {
            ans=INF;
            dfs(0,1,1,62);
        }
        printf("Case %d: ",cnt++);
        if (ans==0) puts("Illegal");
        else if (ans>=INF) puts("INF");
        else printf("%lld\n",ans);
    }
}

















