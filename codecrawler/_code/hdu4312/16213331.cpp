#include <stdio.h>
#include <algorithm>

using namespace std;
#define N 100000
#define ENU 2
#define MAXA 1LL << 62
int sx,sy;
struct Point
{
    int x,y;
    void input()
    {
        scanf("%d%d",&x,&y);
        sx += x;
        sy += y;
    }
}pt[N],p;

bool cmp(Point a,Point b)
{
    return max(abs(a.x - p.x),abs(a.y - p.y)) < max(abs(b.x - p.x),abs(b.y - p.y));
}
int main()
{
    int n,i,j,t;
    __int64 ans,tmp;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        sx = sy = 0;
        for(i = 0; i < n; ++i)
            pt[i].input();
        p.x = sx/n;
        p.y = sy/n;
        sort(pt,pt + n,cmp);
        int k = n > ENU ? ENU : n;
        ans = MAXA;
        for(i = 0;i < k ; ++i)
        {
            tmp = 0;
            for(j = 0; j < n; ++j)
                tmp += 1LL * max(abs(pt[i].x - pt[j].x),abs(pt[i].y - pt[j].y));
            if(tmp < ans)
                ans = tmp;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
