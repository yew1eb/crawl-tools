#include<stdio.h>
#include<string.h>
#define N 21
int map[N][N];
int main()
{
    int n;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        int x=n+1;
        int y=x/2;
        memset(map,0,sizeof(map));
        map[1][y]=1;
        map[n][y]=n*n;
        int temp=n+2;
        int i,j;
        i=y-1;
        j=y+1;
        int tempx,tempy;
        tempx=n*n-1;
        tempy=1+temp;
        while(i>=1&&j<=n)
        {
            map[1][i]=tempx;
            i--;
            tempx-=temp;
            map[1][j]=tempy;
            j++;
            tempy+=temp;
        }
        temp=1+n*n;
        for(i=1; i<=n; i++)
            map[n][i]=temp-map[1][n+1-i];
        int start,end;
        int l,k;
        for(j=1; j<n; j++)
        {
            start=map[1][j]/n*n+1;
            end=(map[1][j]+n)/n*n;
            for(l=2,k=j-1; l<=n&&k>0; l++,k--)
            {
                if(map[l-1][k+1]!=start)
                    map[l][k]=map[l-1][k+1]-1;
                else
                    map[l][k]=end;
            }
            for(l=n-1,k=j+2; l>=1&&k<=n; l--,k++)
            {
                if(map[l+1][k-1]!=end)
                    map[l][k]=map[l+1][k-1]+1;
                else
                    map[l][k]=start;
            }

        }
        for(l=2,k=n-1; l<=n&&k>=1; l++,k--)
        {
             map[l][k]=map[l-1][k+1]-1;
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
                printf("%4d",map[i][j]);
            printf("\n");
        }
    }
    return 0;
}