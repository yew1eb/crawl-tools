#include<stdio.h>
#include<string.h>
#define mx 1000
int c1[mx][100],c2[mx][100];
int a[5]={0,1,2,5};
int main()
{
    int cas,n,m,i,j,k,l;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d %d",&n,&m);//nä¸ªç¡¬å¸
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        for(i=0;i<=n;i++)
        {
            c1[i][i]=1;
        }
        for(i=2;i<=3;i++)
        {
            for(j=0;j<=m;j++)
            {
                for(k=0;k+j<=m;k+=a[i])
                     for(l=0;l+k/a[i]<=n;l++)
                       c2[j+k][l+k/a[i]]+=c1[j][l];

            }
            for(k=0;k<=m;k++)
                for(l=0;l<=n;l++)
                {
                    c1[k][l]=c2[k][l];
                    c2[k][l]=0;
                }
        }
        int ans=0;
        printf("%d\n",c1[m][n]);

    }
    return 0;
}
