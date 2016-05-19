#include <stdio.h>
#include <string.h>
#define MAXN 100000 + 5

int c[MAXN], n;
int lowbit(int x) {return (x&-x);}
void update(int i, int d) { for(;i<=n; i+=lowbit(i)) c[i]+=d; }
int getsum(int i) { int ret=0; for(;i>0; i-=lowbit(i)) ret+=c[i]; return ret;}

int main()
{
    int i, a, b;
    while(scanf("%d",&n),n)
    {
        memset(c, 0, sizeof c );
        for(i=0; i<n; ++i)
        {
            scanf("%d%d",&a,&b);
            update(a,1);
            update(b+1,-1);
        }
        for(i=1; i<=n; ++i) {
            int ans = getsum(i);
            printf("%d%c",ans," \n"[i==n]);
        }
    }
    return 0;
}
