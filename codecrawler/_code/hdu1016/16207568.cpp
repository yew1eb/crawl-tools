#include <string.h>
#include <stdio.h>
#include <set>
#include <ctype.h>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;

const int maxn = 64 ;
int ans[maxn] ;
bool can[maxn][maxn] , vis[maxn] ;

inline bool get(int &t)
{
    bool flag = 0 ;
    char c;
    while(!isdigit(c = getchar())&&c!='-') if( c == -1 ) break ;
    if( c == -1 ) return 0 ;
    if(c=='-') flag = 1 , t = 0 ;
    else t = c ^ 48;
    while(isdigit(c = getchar()))    t = (t << 1) + (t << 3) + (c ^ 48) ;
    if(flag) t = -t ;
    return 1 ;
}

int n ;

void init()
{
    int i , j ;
    for( i = 2 ; i < maxn ; i++) if(!vis[i])
    {
        for( j = i*i ; j < maxn ; j += i ) vis[j] = 1 ;
    }
    for( i = 1 ; i <= 20 ; i++)
        for( j = i+1 ; j <= 20 ; j++)
            if(!vis[i+j])
                can[i][j] = can[j][i] = 1 ;
}

void dfs(int pos)
{
    int i ;
    if( pos == n )
    {
        if(!can[1][ans[n-1]]) return ;
        printf("1");
        for( i = 1 ; i < n ; i++) printf(" %d",ans[i]);
        puts("");
    }
    else
    {
        i = ( pos & 1 ) ? 2 : 3 ;
        for( ; i <= n ; i += 2 ) if(!vis[i]&&can[ans[pos-1]][i])
        {
            ans[pos] = i ;
            vis[i] = 1 ;
            dfs(pos+1);
            vis[i] = 0 ;
        }
    }
}

void solve()
{
    memset(ans,0,sizeof(ans));
    memset(vis,0,sizeof(vis));
    ans[0] = 1 ;
    vis[1] = 1 ;
    dfs(1);
}

int main()
{
    int i ; 
    init();
    for( i = 1 ; get(n) ; i++)
    {
        printf("Case %d:\n",i);
        solve();
        puts("");
    }    
}