#include<cstdio>
int hash[32][201];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int i,k,po;
        bool f=1;
        hash[1][0]=1;
        for(i=2;i<=n;i++)
        {
            hash[i][0]=1;
            for(po=0;po<=n*(n-1)/2;po++)
                for(k=1;k<=i;k++)
                    if(hash[k][po])
                        hash[i][(i-k)*k+po]=1;
        }
        for(i=0;i<=n*(n-1)/2;i++)
            if(hash[n][i])
            {
                if(f)
                {
                    printf("%d",i);
                    f=0;
                }
                else
                    printf(" %d",i);
            }
        printf("\n");
    }
    return 0;
}