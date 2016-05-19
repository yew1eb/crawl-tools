#include<stdio.h>
int main()
{
    int a[10][10],i,j,m,n,z;
    scanf("%d",&n);
    for(z=1;z<=n;z++)
    {
        scanf("%d",&m);
        for(i=1;i<=m;i++)
            for(j=1;j<=m;j++)
            {
                a[i][j]=i*j;
            }
            for(i=1;i<=m;i++)
              for(j=1;j<=m;j++)
              {
                  if(j<m)
                      printf("%d ",a[i][j]);
                  else
                      printf("%d\n",a[i][j]);
              }
    }
    return 0;
}
