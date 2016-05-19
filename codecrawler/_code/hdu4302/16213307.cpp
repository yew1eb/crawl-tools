//MJRT
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
//////////////////////
#include<iostream>
#include<algorithm>
#include<string>
#include <iterator>
#include<sstream>
#include<functional>
#include<numeric>
///////////////////////
#include<vector>
#include<map>
#include <stack>
#include<queue>
#include<set>
#include <bitset>
#include <list>
///////////////////////
//#include<ext/pb_ds/priority_queue.hpp> //pd_bsåº,hdu&&pojä¸æ¯æ
using namespace std;
#define lowbit(x) ((x)&(-x))
static int INDEX = 0,BUGs = 0;
#define BUG() cout << "There is BUG No." << BUGs++ <<endl
#define Whats(x) cout << "{ "<< #x << " }" << " is " << "*** "<< x << " ***" << "  index:" << INDEX++ <<endl
#define Show(x,s,l)         cout << #x << ": "; for(int i = s ; i < s+l ; i++) cout << x[i] << " ";  cout << "\n"
typedef  long long int LL;
const int INF = ~0U>>1;

const int N = 5 + 100000;
LL a[N];
LL T1[N<<2],T2[N<<2];
LL dir,now,cnt,M,n,m;

void pushup(int x)
{
    T1[x] = max(T1[x<<1] ,T1[x<<1|1]);
    T2[x] = min(T2[x<<1] ,T2[x<<1|1]);
}

void updata(int x,int v1,int v2)
{

    x += M;
    T1[x] = v1;
    T2[x] = v2;
    for(x>>=1 ; x ; x>>=1)
        pushup(x);

}

void build()
{
    int t;
    scanf("%d",&t);
    if(++a[++t] == 1)
        updata(t,t,t);
}

LL query1(int l , int r)
{
    LL ans = -INF;
    for(l+=M-1, r+=M+1 ; l^r^1 ; l>>=1 ,r>>=1)
    {
        if(~l&1)    ans = max(ans,T1[l^1]);
        if(r&1)     ans = max(ans,T1[r^1]);
    }
    return ans;
}

LL query2(int l , int r)
{
    LL ans = INF;
    for(l+=M-1, r+=M+1 ; l^r^1 ; l>>=1 ,r>>=1)
    {
        if(~l&1)    ans = min(ans,T2[l^1]);
        if(r&1)     ans = min(ans,T2[r^1]);
    }
    return ans;
}

void eat(int x)
{
    if(--a[x]==0)
        updata(x,0,INF);
}

void go(int pos,int d)
{

    cnt += abs(now-pos);
    now = pos;
    dir = d;
    eat(now);
}

int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    //freopen("in.in", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

    int Case,tot = 1;
    scanf("%d",&Case);
    while(Case--)
    {
        cnt = 0;dir = now = 1;
        scanf("%d%d",&n,&m);
        n+=2;
        memset(T1,0,sizeof(T1));
        fill(T2,T2+(N<<2),INF);
        memset(a,0,sizeof(a));
        for(M=1 ; M<n+2; M<<=1)
            ;

        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d",&x);
            if (x==0)
            {
                build();
            }
            else
            {
                int lans = query1(1,now);
                int rans = query2(now,n+1);

                if (lans==0&&rans==INF) continue;
                else if (lans==0) go(rans,1);
                else if (rans==INF) go(lans,-1);
                else if (abs(now-lans)<abs(rans-now)) go(lans,-1);
                else if (abs(now-lans)>abs(rans-now)) go(rans,1);
                else if (now==lans || now == rans) eat(now);
                else if(dir == -1)  go(lans,-1);
                else if(dir ==  1)  go(rans,1);

            }
        }
        printf("Case %d: %lld\n",tot++,cnt);
    }
    return 0;
}

