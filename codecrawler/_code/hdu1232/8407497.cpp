#include <stdio.h>
#define N 1000
int f[N];
int find(int x){return f[x]==x ? x:(f[x] = find(f[x]));}
void Union(int a, int b)
{
    int a_f = find(a);
    int b_f = find(b);
    if(a_f != b_f)
        f[a_f] = b_f;
}
int main()
{
    int n, m, ans, i, a, b;
    while(scanf("%d%d",&n,&m),n)
    {
        for(i=0; i<=n; f[i]=i,i++);
        for(i=0; i<m; i++)
        {
            scanf("%d%d",&a,&b);
            Union(a,b);
        }
        ans = 0;
        for(i=1; i<=n; i++)
            if(f[i]==i) ans++;
        printf("%d\n",ans-1);
    }
    return 0;
}
