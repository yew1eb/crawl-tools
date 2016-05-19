/*****************************************************************************
                    ççsphinxçå¼å¤´ ~ï¼
*****************************************************************************/
#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<utility>
#include<complex>
#include<cstdlib>
#include<cassert>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cctype>
#include<limits>
#include<cmath>
#include<queue>
#include<stack>
#include<deque>
#include<cmath>
#include<ctime>
#include<list>
#include<map>
#include<set>
using namespace std;
#define MID(x,y) ( ( x + y ) >> 1 )
#define L(x) ( x << 1 )
#define R(x) ( x << 1 | 1 )
#define BUG puts("here!!!")
#define STOP system("pause")
#define LOWBIT(x) ( (x) & ( (x) ^ ( (x) - 1 ) ) )
#define CLR(x, k) memset((x), (k), sizeof(x))
#define CPY(t, s) memcpy((t), (s), sizeof(s))
#define SC(t, s) static_cast<t>(s)
#define LEN(s) static_cast<int>( strlen((s)) )
#define SZ(s) static_cast<int>( (s).size() )
typedef double LF;
//typedef long long LL;     //GNU C++
//typedef unsigned long long ULL;
typedef __int64 LL;     //Visual C++ 2010
typedef unsigned __int64 ULL;

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<double, double> PDD;

typedef map<int, int>::iterator MI;
typedef vector<int>::iterator VI;
typedef list<int>::iterator LI;
typedef set<int>::iterator SI;

const int INF_INT = 0x3f3f3f3f;
const LL INF_LL = 0x7fffffffffffffffLL;     //15f
const double oo = 10e9;
const double eps = 10e-7;
const double PI = acos(-1.0);
const int inf=0x7fffffff;

const int maxn=111;
const int maxin=222;     //ä»22æ¹æ222
// f**k!!æ¬æ¥æä»¥ä¸º22å·²ç»è¶³å¤å¤§äºï¼å ä¸ºspfaæ¯ä¸ªç¹é½æ¯å¹³åè¿åºä¸¤æ¬¡çï¼å°¼çhduçæµè¯æ°æ®è½è®©å®è¿åºå ç¾æ¬¡åï¼ï¼ææ¨æ....
vector<int>g[maxn];
queue<int>Q;
bool vis[maxn];
bool see[maxn];
bool did[maxn];
int num[maxn];
int power[maxn];
int e[maxn];
int n,m,tv,now,tp,start,end;

inline void init()
{
    memset(num,0,sizeof(num));
    memset(vis,false,sizeof(vis));
    memset(see,false,sizeof(see));
    memset(power,-1,sizeof(power));
    memset(did,false,sizeof(did));
    for(int i=1;i<=n;i++)
    {
        g[i].clear();
    }
    return ;
}

bool spfa()
{
    while(!Q.empty())
    {
        Q.pop();
    }
    Q.push(1);
    power[1]= 100 + e[1];
    num[1]++;
    vis[1]= true;
    while (!Q.empty())
    {
        now = Q.front();
        Q.pop();
        for (int i=0; i < g[now].size(); i++)
        {
            tv = g[now][i];
            tp = power[now] + e[tv];
            if ( tv == n )
            {
                return true;
            }
            if ( tp <= 0 )
            {
                continue;
            }
            if ( tp > power[tv] )
            {
                power[tv] = tp;
                if ( !vis[tv] && !did[tv])
                {
                    if ( num[tv] <= maxin )
                    {
                        Q.push(tv);
                        num[tv]++;
                        vis[tv]=true;
                    }
                    else
                    {
                        if(!did[tv])
                        {
                            power[tv]=inf;
                            Q.push(tv);
                            memset(num,0,sizeof(num));
                            num[tv]=inf;
                            vis[tv]=true;
                            did[tv]=true;
                        }
                    }
                }
            }
        }
        vis[now]=false;
    }
    return false;
}

int main()
{
    while(cin>>n)
    {
        init();
        if(n==-1) break;
        for(int i=1;i<=n;i++)
        {
            cin>>e[i]>>m;
            for(int j=1;j<=m;j++)
            {
                cin>>tv;
                g[i].push_back(tv);
            }
        }
        if( spfa() )
        {
            cout<<"winnable"<<endl;
        }
        else
        {
            cout<<"hopeless"<<endl;
        }
    }
    return 0;
}