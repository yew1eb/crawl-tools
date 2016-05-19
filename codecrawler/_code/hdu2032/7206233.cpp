#include<stdio.h>
int main()
{
    int n, i, j;
    int f[40][40]={0};
    f[0][1]=1;
    for(i=1;i<32;i++)
       for(j=1;j<=i;j++)
          f[i][j]=f[i-1][j]+f[i-1][j-1];
    while(scanf("%d",&n)!=EOF)
    {                    
         for(i=1;i<=n;i++)
         {
             for(j=1;j<i;j++)
                printf("%d ",f[i][j]);
             printf("%d\n",f[i][i]);
         }
         printf("\n");
    }
    return 0;
}
    
