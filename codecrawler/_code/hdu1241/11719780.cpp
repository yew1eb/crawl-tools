#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#define for0(i,n) for(i=0;i<n;++i)
#define for1(i,n) for(i=1;i<=n;++i)
#define foru(i,l,r) for(i=l;i<=r;++i)
#define ford(i,r,l) for(i=r;i>=l;--i)
#define pb push_back

using namespace std;

typedef double db;
typedef long long ll;
const db eps = 1e-8;
const int inf = 1e9;

const int maxn =  100 + 5;
int n, m;
int dir[8][2] = {1,0, -1,0, 0,1, 0,-1,
                 1,1, 1,-1, -1,1, -1,-1};
char mp[maxn][maxn];

struct xy {int x, y; xy(int x=0,int y=0):x(x),y(y){} };

void bfs(int x, int y)
{
    int i;
    xy u, nt;
    queue<xy> q;
    u.x = x, u.y = y;
    q.push(u);
    while(!q.empty()){
        u = q.front(); q.pop();
        for0(i,8)
        {
            nt.x = u.x + dir[i][0];
            nt.y = u.y + dir[i][1];
            if(nt.x<0||nt.x>=n||nt.y<0||nt.y>=m||mp[nt.x][nt.y]!='@') continue;
            mp[nt.x][nt.y] = '*';
            q.push(nt);
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.cpp", "r", stdin);
    freopen("out.cpp","w", stdout);
#endif // ONLINE_JUDGE
    int i, j;
    while(cin>>n>>m)
    {
        if(n==0&&m==0) break;
        for0(i,n) cin>>mp[i];
        int cnt = 0;
        for0(i,n) for0(j,m)
        if(mp[i][j]=='@') bfs(i,j), cnt++;
        cout<<cnt<<endl;
    }
    return 0;
}










