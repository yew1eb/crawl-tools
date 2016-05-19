#include<stdio.h>
int map[30][30][30];
int main()
{
    int a,b,c,i,j,k;
    for(i=0;i<=20;++i)
        for(j=0;j<=20;++j)
            for(k=0;k<=20;++k)
                if(i==0 || j==0 || k==0)
                    map[i][j][k]=1;
                else if(i<j && j<k)
                    map[i][j][k]=map[i][j][k-1]+map[i][j-1][k-1]-map[i][j-1][k-1];
                else
                    map[i][j][k]=map[i-1][j][k]+map[i-1][j-1][k]+map[i-1][j][k-1]-map[i-1][j-1][k-1];
    while(scanf("%d%d%d",&a,&b,&c),a!=-1 || b!=-1 || c!=-1)
    {
        if(a<=0 || b<=0 || c<=0)
            i=1;
        else if(a>20 || b>20 || c>20)
            i=map[20][20][20];
        else
            i=map[a][b][c];
        printf("w(%d, %d, %d) = %d\n",a,b,c,i);
    }
    return 0;
}