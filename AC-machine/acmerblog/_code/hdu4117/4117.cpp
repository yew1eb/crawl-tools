/*************************************************************************
    > File Name: hdu4117.cpp
    > Author: X__X
    > Mail: [email protected]/* <![CDATA[ */!function(t,e,r,n,c,a,p){try{t=document.currentScript||function(){for(t=document.getElementsByTagName('script'),e=t.length;e--;)if(t[e].getAttribute('data-cfhash'))return t[e]}();if(t&&(c=t.previousSibling)){p=t.parentNode;if(a=c.getAttribute('data-cfemail')){for(e='',r='0x'+a.substr(0,2)|0,n=2;a.length-n;n+=2)e+='%'+('0'+('0x'+a.substr(n,2)^r).toString(16)).slice(-2);p.replaceChild(document.createTextNode(decodeURIComponent(e)),c)}p.removeChild(t)}}catch(u){}}()/* ]]> */ 
    > Created Time: 2012/10/10 14:55:19
 ************************************************************************/

#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iostream>
#include<ctime>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<utility>
using namespace std;
 
#define MP make_pair
#define PB push_back
#define IT iterator
#define B begin() 
#define E end()
#define X first
#define Y second
#define foreach(it, container) \
    for(typeof((container).begin()) it = (container).begin();it!=(container).end();++it)
#define CLR(a, x) memset(a, x, sizeof (a))
typedef vector<int> VI;
typedef pair<int,int> PII;
VI::IT it;
void op(int n){cout << n << ' ';}

const int inf = 0x3f3f3f3f;
const int maxn = 1e6+10;
const int maxz = 26;
const char _base = 'a';

char g_in[maxn];
int trie[maxn][maxz], fail[maxn], word[maxn];
int dp[maxn], belong[maxn];
int pos[30000];
int npos, n, ans;

void _insert(int s)
{
    int k, p = 0;
    while(g_in[s])
    {
        k = g_in[s] - _base;
        if(trie[p][k] == 0)
        {
            trie[p][k] = ++npos;
            CLR(trie[npos], 0);
            word[npos] = 0;
        }
        p = trie[p][k];
        s++;
    }
}

int q[maxn];
void build_ac()
{
    int t, qe, qs, cur, nt;
    qe = qs = 0;
    for(int i = 0; i < maxz; i++)
        if(t = trie[0][i])
            fail[t] = 0, q[qe++] = t;
    while(qs < qe)
    {
        cur = q[qs++];
        for(int i = 0; i < maxz; i++)
        {
            if(nt = trie[cur][i])
            {
                fail[nt] = trie[fail[cur]][i];
                q[qe++] = nt;
            }
            else
                trie[cur][i] = trie[fail[cur]][i];
        }
    }
}

void cal(int x)
{
    int r, p, t, cur;
    r = p = 0;
    for(int i = pos[x]; i < pos[x+1]; i++)
    {
        cur = g_in[i] - _base;
        p = t = trie[p][cur];
        while(t)
        {
            if(word[t])
                r = max(r, dp[belong[word[t]]]);
            t = fail[t];
        }
    }
    word[p] = p;
    belong[p] = x;
    dp[x] += r;
}

void solve()
{
    scanf("%d", &n);
    npos = pos[0] = 0;
    CLR(trie[0], 0);
    int temp;
    for(int i = 0; i < n; i++)
    {
        scanf("%s%d", g_in + pos[i], &temp);
        pos[i+1] = pos[i] + strlen(g_in + pos[i]);
        _insert(pos[i]);
        dp[i] = temp;
    }
    build_ac();
    ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(dp[i] > 0)
            cal(i);
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
}

int main() 
{
    //freopen("in.txt", "r", stdin); 
    int times;
    scanf("%d", &times);
    for(int i = 0; i < times; i++)
    {
        printf("Case #%d: ", i+1);
        solve();
    }
    return 0;
}