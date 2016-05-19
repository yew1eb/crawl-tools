#include<iostream>
using namespace std;
int c[2001][2001];
int main()
{
    int i,j;
    for(i=1;i<=2000;i++)
    {
        c[i][0]=1;
        c[i][1]=i%1007;
    }
    for(i=2;i<=2000;i++)
    {
        for(j=2;j<=i;j++)
        {
           c[i][j]=(c[i-1][j]%1007+c[i-1][j-1]%1007)%1007;
        }
    }
    int t,m,n;
    while(scanf("%d",&t)!=EOF)
    {
        while(t--&&scanf("%d%d",&m,&n))
        {
            if(m>n){printf("0\n");continue;}
            else printf("%d\n",c[n][m]);
        }
    }
    return 0;
}