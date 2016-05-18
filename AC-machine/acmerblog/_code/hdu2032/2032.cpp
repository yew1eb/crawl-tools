#include<stdio.h>
#include<string.h>
#define MAX 35
int num[MAX][MAX];
int func(int row,int col)
{
    if(col==0||col==row) num[row][col]=1;
    if(num[row][col]==-1)
        num[row][col]=func(row-1,col-1)+func(row-1,col);
    return num[row][col];
}
int main()
{
    int n;
    memset(num,-1,sizeof(num));
    while(~scanf("%d",&n))
    {
        int i,j;
        for(i=0;i<n;i++)
        {
            for(j=0;j<i;j++)
                printf("%d ",func(i,j));
            printf("%d",func(i,i));
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}