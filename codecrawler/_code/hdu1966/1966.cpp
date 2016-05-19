#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

const double INF = 1e11;

const int MAXN = 55;

int n;

struct Point
{
    int x,y;
    void read()
    {
        scanf("%d%d",&x,&y);
    }
} p[MAXN];

inline double Cross(Point &a, Point &b, Point &c) {                    // 叉积
    return (b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);
}

int check(int a,int b,int c)
{
    int tt = fabs(Cross(p[a],p[b],p[c]));
    for(int i = 0;i<n;i++)
    {
        if(i == a || i == b ||i == c) continue;
        int tmp = fabs(Cross(p[a],p[b],p[i])) + fabs(Cross(p[a],p[c],p[i])) + fabs(Cross(p[b],p[c],p[i]));
        if(tmp == tt) return 0;
    }
    return 1;
}

double d[MAXN][MAXN];

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        for(int i = 0;i<n;i++)
        {
            p[i].read();
        }
        for(int len = 1;len<=2;len++)
            for(int i = 0;i<n;i++)
                d[i][(i+len-1)%n] = 0;
        for(int i = 0;i<n;i++)
        {
            d[i][(i+2)%n] = fabs(Cross(p[i],p[(i+1)%n],p[(i+2)%n]))/2.0;
        }
        for(int len = 4;len<=n;len++)
        {
            for(int i = 0;i<n;i++)
            {
                int j = (i + len - 1)%n;
                d[i][j] = INF;
                for(int k = (i+1)%n; k!= j; k = (k+1)%n)
                {
                    if(check(i,k,j)) d[i][j] = min(d[i][j],max(max(d[i][k],d[k][j]),fabs(Cross(p[i],p[k],p[j]))/2.0));
                }
                //printf("i = %d,j = %d,d = %f\n",i,j,d[i][j]);
            }
        }
        double ans = INF;
        for(int i = 0;i<n;i++)
            ans = min(d[i][(i+n-1)%n],ans);
        printf("%.1f\n",ans);
    }
    return 0;
}

/*

6
1 1
0 3
3 5
9 5
6 2
7 0

*/