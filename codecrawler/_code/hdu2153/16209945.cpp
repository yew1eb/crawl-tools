#include<iostream>
using namespace std;
int main()
{
    int n,i,j;
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        for(i=1;i<=n;i++)
          printf("%3d",i);
        printf("\n");
        for(i=2;i<=n-1;i++)
        {
            printf("%3d",4*n-2-i);
            for(j=1;j<=n*3-6;j++)
                printf(" ");
            printf("%3d",n+i-1);
            printf("\n");
        }
        if(n>1)
        {
        for(i=3*n-2;i>=2*n-1;i--)
            printf("%3d",i);
        printf("\n");
        }
    }
    return 0;
}