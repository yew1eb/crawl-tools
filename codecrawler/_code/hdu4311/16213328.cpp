#include <stdio.h>
#include <algorithm>
using namespace std;

#define N 100005

struct Num
{
    int x,y,id;
}A[N];

__int64 sumx[N],sumy[N];

__int64 Sx,Sy;

int numx[N],numy[N];

int n,x[N],y[N];

bool cmp1(Num s1,Num s2)
{
    return s1.x < s2.x;
}

bool cmp2(Num s1,Num s2)
{
    return s1.y < s2.y;
}

__int64 resx(int k)
{
    return (__int64)x[k]*(2*numx[k]-n) + Sx - 2*sumx[k];
}
__int64 resy(int k)
{
    return (__int64)y[k]*(2*numy[k]-n) + Sy - 2*sumy[k];
}

int main()
{
    //freopen("in.ads","r",stdin);
    int z;
    scanf("%d",&z);
    while(z--)
    {
        Sx = Sy = 0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&x[i],&y[i]);
            A[i].id = i;
            A[i].x = x[i];
            A[i].y = y[i];
            Sx += x[i];
            Sy += y[i];
        }
        sort(A+1,A+1+n,cmp1);
        for(int i=1;i<=n;i++)
        {
            sumx[ A[i].id ] = sumx[ A[i-1].id ] + A[i].x;
            numx[ A[i].id ] = i;
        }
        sort(A+1,A+1+n,cmp2);
        for(int i=1;i<=n;i++)
        {
            sumy[ A[i].id ] = sumy[ A[i-1].id ] + A[i].y;
            numy[ A[i].id ] = i;
        }
        __int64 ans = resx(1) + resy(1);
        for(int k=2;k<=n;k++)
            ans = min(ans,resx(k)+resy(k));
        printf("%I64d\n",ans);
    }
    return 0;
}
