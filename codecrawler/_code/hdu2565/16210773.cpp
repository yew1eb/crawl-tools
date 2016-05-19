#include<stdio.h>
#include<string.h>
int main()
{
    int cas,n,i,j;
    int map[100][100];
    int a[100];
    scanf("%d",&cas);
    //int cnt=0;
    while(cas--)
    {
        //if(cnt!=0) printf("\n");
        //cnt++;
        memset(map,0,sizeof(map));
        scanf("%d",&n);
        for(i=1;i<=n;i++) 
               map[i][n+1-i]=1;
        for(i=1;i<=n;i++) map[i][i]=1;

        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(map[i][j]==1) a[i]=j;     
            }
        }

        for(i=1;i<=n;i++)
        {
            for(j=1;j<=a[i];j++)
            {
                if(map[i][j]==1) printf("X");
                else printf(" ");
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}