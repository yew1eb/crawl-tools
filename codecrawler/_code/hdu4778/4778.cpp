#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int dp[(1<<21)+10][9];
int g,b,s;
int v[25][10];
int a[10];

int max(int a,int b)
{
    return a>b?a:b;
}

int main()
{
    while (scanf("%d%d%d",&g,&b,&s)&&g+b+s)
    {
        memset(v,0,sizeof(v));
        memset(a,0,sizeof(a));
        int sum=0;
        for (int i=0;i<b;i++)
        {
            int n;
            scanf("%d",&n);
            while (n--)
            {
                int a1;
                scanf("%d",&a1);
                v[i][a1]++;
                a[a1]++;
                sum+=a[a1]/s;
                a[a1]%=s;
            }
        }
        int mm=(1<<b)-1;
        for (int i=1;i<=g;i++)
            dp[0][i]=a[i];      //全部取完炉子的状态
        dp[0][0]=0;
        for (int i=1;i<=mm;i++)
            dp[i][0]=-1000000;
        for (int i=0;i<=mm;i++)
        {
            for (int j=0;j<b;j++)
            {
                int x=(1<<j);
                if ((i&x)==0)   //如果j取过了
                {
                    int gs=0;
                    for (int k=1;k<=g;k++)  //从没取j到取j总过得到多少宝石
                    {
                        a[k]=dp[i][k]-v[j][k];
                        while (a[k]<0)  //说明取的时候获得了宝石
                        {
                            gs++;
                            a[k]+=s;
                        }
                        dp[i^x][k]=a[k];
                    }
                    if (gs>0)   //如果大于0，不换手，先手+gs-后手=gs+dp[i][0]
                        dp[i^x][0]=max(dp[i^x][0],gs+dp[i][0]);
                    else    //换手，新得到的分数等于0，原来的先手-后手变成后手-先手，取负即可
                        dp[i^x][0]=max(dp[i^x][0],-dp[i][0]);
                }
            }
        }
        printf("%d\n",dp[mm][0]);
    }
}
