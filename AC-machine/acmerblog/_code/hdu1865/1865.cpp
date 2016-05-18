#include<stdio.h>
#include<string.h>
int dp[10000005];
bool mark[35];
int n,i,j,m,pp,tmp,total;
double tt,p;
char c;
struct P
{
    int p[3],all;
}price[35];
int max(int a,int b)
{
    return a>b?a:b;
}
void init()
{
    int i;
    memset(mark,0,sizeof(mark));
    total=tt*100.0;
    for (i=0;i<=total;++i) dp[i]=0;
    for (i=1;i<=n;++i)
    {
        memset(price[i].p,0,sizeof(price[n].p));
        price[i].all=0;
    }
}
int main()
{
    while (scanf("%lf%d",&tt,&n))
    {
        if (n==0) break;
        init();
        for (i=1;i<=n;++i)
        {
            scanf("%d",&m);
            for (j=1;j<=m;++j)
            {
                scanf(" %c:%lf",&c,&p);
                pp=p*100.0;
                if (c=='A' || c=='B' ||c=='C')
                {
                    price[i].p[c-'A']+=pp;
                    if (price[i].p[c-'A']>60000) mark[i]=1;
                }
                else mark[i]=1;
            }
            price[i].all=price[i].p[0]+price[i].p[1]+price[i].p[2];
            if (price[i].all>100000) mark[i]=1;
        }
        for (i=1;i<=n;++i)
        {
            if (!mark[i])
            {
                for (j=total;j>=price[i].all;--j)
                {
                    dp[j]=max(dp[j],dp[j-price[i].all]+price[i].all);
                }
            }
        }
        printf("%.2lf/n",double(dp[total])/100);
    }
    return 0;
}