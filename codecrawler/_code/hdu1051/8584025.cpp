#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 5000 + 5
using namespace std;
struct node
{
    int x, y;
    bool operator < (const node & t) const
    {
        return (x<t.x)||(x==t.x&&y<t.y);
    }
}f[N];
bool mark[N];
int main()
{
    int T, n, tw, ans, i, j;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=0; i<n; i++) scanf("%d%d",&f[i].x,&f[i].y);
        sort(f,f+n);
        memset(mark,false,sizeof(mark));
        ans = 0;
        for(i=0; i<n;i++)
        if(!mark[i])
        {
            tw = f[i].y;
            mark[i] = true;
            ans++;
            for(j=i+1; j<n; j++)
            if(!mark[j]&&f[j].y>=tw)
            {
                tw = f[j].y;
                mark[j] = true;
            }
        }
        printf("%d\n",ans);
    }
}
