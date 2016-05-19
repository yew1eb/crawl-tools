#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
#include <stack>

#pragma comment(linker, "/STACK:1024000000");
#define EPS (1e-6)
#define LL long long
#define ULL unsigned long long int
#define _LL __int64
#define _INF 0x3f3f3f3f
#define INF (1<<62)
#define Mod 1000000007

using namespace std;

char Map[51][51];

int hurt[51][51][5];

bool mark[51][51][33];

void Init_Hurt(int n,int m)
{
    int i,j,k,l;

    memset(hurt,0,sizeof(hurt));

    for(i =1;i <= n; ++i)
    {
        for(j = 1;j <= m ; ++j)
        {
            if(Map[i][j] == 'A')
            {
                for(k = i-2;k <= i+2; ++k)
                {
                    for(l = j-2;l <= j+2; ++l)
                    {
                        if(1 <= k && k <= n && 1 <= l && l <= m && abs(k-i)+ abs(l-j) <= 2)
                        {
                            hurt[k][l][0] = 1;
                        }
                    }
                }
            }
            else if(Map[i][j] == 'B')
            {
                for(k = i-3;k <= i+3; ++k)
                {
                    for(l = j-3;l <= j+3; ++l)
                    {
                        if(1 <= k && k <= n && 1 <= l && l <= m && abs(k-i)+ abs(l-j) <= 3)
                        {
                            hurt[k][l][1] = 2;
                        }
                    }
                }
            }
            else if(Map[i][j] == 'C')
            {
                hurt[i][j][2] = 3;
            }
            else if(Map[i][j] == 'D')
            {
                for(k = i-2;k <= i+2; ++k)
                {
                    for(l = j-2;l <= j+2; ++l)
                    {
                        if(1 <= k && k <= n && 1 <= l && l <= m && abs(k-i)+ abs(l-j) <= 2)
                        {
                            hurt[k][l][3] = 4;
                        }
                    }
                }
            }
            else if(Map[i][j] == 'E')
            {
                for(k = i-1;k <= i+1; ++k)
                {
                    for(l = j-1;l <= j+1; ++l)
                    {
                        if(1 <= k && k <= n && 1 <= l && l <= m && abs(k-i)+ abs(l-j) <= 1)
                        {
                            hurt[k][l][4] = 5;
                        }
                    }
                }
            }
        }
    }
}

struct N
{
    int x,y,sta,ans;
    bool operator < (const N &a) const
    {
        return a.ans < ans;
    }
};

int jx[] = {-1, 0, 1, 0};
int jy[] = { 0, 1, 0,-1};

bool Judge(char c)
{
    if(c == '$' || c == 'C' || c == '!' || c == '.')
        return true;
    return false;
}

void bfs(int n,int m,int s,int e)
{
    priority_queue<N> q;

    N f,t;

    f.x = s,f.y = e,f.sta = 0,f.ans = 0;

    memset(mark,false,sizeof(mark));

    mark[s][e][0] = true;

    q.push(f);

    while(q.empty() == false)
    {
        f = q.top();
        q.pop();

        if(f.x != s || f.y != e)
        {
            for(int k = 0;k < 5; ++k)
            {
                if((f.sta&(1<<k)) == 0 && hurt[f.x][f.y][k])
                {
                    f.ans += hurt[f.x][f.y][k];
                    f.sta += (1<<k);
                }
            }
        }

        if(Map[f.x][f.y] == '!')
        {
            printf("%d\n",f.ans);
            return ;
        }

        for(int i = 0;i < 4; ++i)
        {
            t.ans = f.ans;
            t.sta = f.sta;
            t.x = f.x + jx[i];
            t.y = f.y + jy[i];

            if(1 <= t.x && t.x <= n && 1 <= t.y && t.y <= m && mark[t.x][t.y][t.sta] == false && Judge(Map[t.x][t.y]) )
            {
                q.push(t);
                mark[t.x][t.y][t.sta] = true;
            }
        }
    }
    printf("-1\n");
}

void Solve(int n,int m)
{
    int i,j;

    for(i = 1; i <= n; ++i)
    {
        for(j = 1;j <= m; ++j)
        {
            if(Map[i][j] == '$')
            {
                bfs(n,m,i,j);
                return ;
            }
        }
    }
}

int main()
{
    int T,icase = 0;

    int i,j,k,n,m;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d %d",&n,&m);

        for(i = 1;i <= n ; ++i)
        {
            scanf("%*c%s",Map[i]+1);
        }

        Init_Hurt(n,m);

        printf("Case %d: ",++icase);

        Solve(n,m);

    }
    return 0;
}