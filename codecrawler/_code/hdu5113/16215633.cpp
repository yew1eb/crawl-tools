#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<queue>
#include<cmath>
#include<map>
#include<stack>
#include<set>
using namespace std;
#define REPF( i , a , b ) for ( int i = a ; i <= b ; ++ i )
#define REP( i , n ) for ( int i = 0 ; i < n ; ++ i )
#define CLEAR( a , x ) memset ( a , x , sizeof a )
const int INF=0x3f3f3f3f;
typedef long long LL;
typedef pair<int,int>pil;
const int maxn=220;
int mp[10][10];
int a[30];
int t,n,m,k;
bool flag;
bool dfs(int x,int y,int res)
{
    if(!res)
    {
        flag=true;
        return true;
    }
    for(int i=1;i<=k;i++)
        if(a[i]>(res+1)/2) return false;
    for(int i=1;i<=k;i++)
    {
        if(a[i]>0)
        {
            if(x&&mp[x-1][y]==i) continue;
            if(y&&mp[x][y-1]==i) continue;
            a[i]--;
            mp[x][y]=i;
            if(y<m-1) dfs(x,y+1,res-1);
            else      dfs(x+1,0,res-1);
            if(flag)
                return true;
            a[i]++;
        }
    }
    return false;
}
int main()
{
    int cas=1;
    scanf("%d",&t);
    while(t--)
    {
        CLEAR(mp,0);
        flag=false;
        scanf("%d%d%d",&n,&m,&k);
        REPF(i,1,k)
           scanf("%d",&a[i]);
        printf("Case #%d:\n",cas++);
        if(!dfs(0,0,n*m))
        {
            puts("NO");
            continue;
        }
        puts("YES");
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                printf(j==m-1?"%d\n":"%d ",mp[i][j]);
        }
    }
    return 0;
}
/*
4
2 2 2
2 2 2
*/
