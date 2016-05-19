#include <stdio.h>
#include <string.h>
int prime[31];
int mark[31];
int p[31];
void Init()
{
    int i, j;
    memset(prime,1,sizeof(prime));
    for(i=2; i<=6; i++)
        if(prime[i])
            for(j=i*i; j<=30; j+=i)
                prime[j] = 0;
}
void dfs(int n, int k)
{
    int i;
    if(k>n&& prime[ p[1] + p[n] ])
    {
        for(i=1; i<n; i++)
            printf("%d ",p[i]);
        printf("%d\n",p[i]);
    }
    for(i=2; i<=n; i++)
        if(!mark[i] && prime[p[k-1] + i])
        {
            mark[i] = 1;
            p[k] = i;
            dfs(n,k+1);
            mark[i] = 0;
        }
}
int main()
{
    int cases = 0, n;
    Init();
    while(~scanf("%d",&n))
    {
        printf("Case %d:\n",++cases);
        memset(mark,0,sizeof(mark));
        mark[1] = 1;
        p[1] = 1;
        dfs(n, 2);
        printf("\n");
    }
    return 0;
}


