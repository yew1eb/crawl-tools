#include<iostream>
#include<cstring>
#include<cstdio>
#include<ostream>
#include<istream>
#include<algorithm>
#include<queue>
#include<string>
#include<cmath>
#include<set>
#include<map>
#include<stack>
#include<vector>
#define fi first
#define se second
#define ll long long
#define pii pair<int,int>
#define inf (1<<30)
#define eps 1e-8
#define pb push_back
using namespace std;
const int maxn=1100005;
int n,m,k;
int d[maxn];
int p[maxn];
int sz;
map<int,int>mp[maxn];
map<int,int>::iterator it;
int fail[maxn];
int val[maxn];
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
struct AC
{
    void init()
    {
        sz=1;
        mp[0].clear();
    }
    void insert()
    {
        int u=0;
        for(int i=0; i<k-1; i++)
        {
            int g=gcd(p[i],p[i+1]);
            int o=p[i]/g*10001+p[i+1]/g;
            if(!mp[u].count(o))
            {
                mp[u][o]=sz;
                val[sz]=0;
                mp[sz].clear();
                u=sz++;
            }
            else
            {
                u=mp[u][o];
            }
        }
        val[u]++;
    }
    void getFail()
    {
        queue<int>que;
        for(it=mp[0].begin(); it!=mp[0].end(); it++)
        {
            fail[it->se]=0;
            que.push(it->se);
        }
        while(!que.empty())
        {
            int now=que.front();
            val[now]+=val[fail[now]];
            que.pop();
            for(it=mp[now].begin(); it!=mp[now].end(); it++)
            {
                int x = fail[now] , flag = 0 ;
                while ( x != 0 )
                {
                    if ( mp[x].count ( it->first ) )
                    {
                        fail[it->second] = mp[x][it->first] ;
                        flag = 1 ;
                        break ;
                    }
                    x = fail[x] ;
                }
                if ( x == 0 && mp[x].count ( it->first ) )
                {
                    fail[it->second] = mp[x][it->first] ;
                    flag = 1 ;
                }
                if ( !flag ) fail[it->second] = 0 ;
                que.push(it->se);
            }
        }
    }
    ll query ()
    {
        ll ans=0;
        int now = 0 ;
        for(int i=0; i<n-1; i++)
        {
            int g = gcd ( d[i] , d[i + 1] ) ;
            int t = d[i] / g * 10001 + d[i + 1] / g ;
            int x = now , flag = 0 ;
            while ( x != 0 )
            {
                if ( mp[x].count ( t ) )
                {
                    now = mp[x][t] ;
                    flag = 1 ;
                    break ;
                }
                x = fail[x] ;
            }
            if ( x == 0 && mp[x].count ( t ) )
            {
                now = mp[x][t] ;
                flag = 1 ;
            }
            if ( !flag ) now = 0 ;
            ans += val[now] ;
        }
        return ans;
    }
} ac;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        ac.init();
        ll ans=0;
        for(int i=0; i<n; i++) scanf("%d",&d[i]);
        for(int i=0; i<m; i++)
        {
            scanf("%d",&k);
            for(int j=0; j<k; j++)
                scanf("%d",&p[j]);
            if(k==1)
            {
                ans+=n;
                continue;
            }
            ac.insert();
        }
        ac.getFail();
        ans+=ac.query();
        printf("%I64d\n",ans);
    }
    return 0;
}