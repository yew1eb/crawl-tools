#include<stdio.h>
main()
{
    int t,n,m,i,j,k,s;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        s=0;
        for(i=0;i<=m;i++)
            for(j=0;j<=m/2;j++)
            {
                k=n-i-j;
                if(k>=0)
                    if(i+j*2+k*5==m)++s;
            }
        printf("%d\n",s);
    }
}