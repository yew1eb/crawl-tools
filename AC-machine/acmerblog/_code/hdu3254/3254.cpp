#include<cstdio>
#include<cstring>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int dp[20][1<<12];
vector<int> s;       //每一行所有可能的状态,即相邻位不全为1
int can[20];        //用来判断牛是否在1的位置上

void debug(int i)
{
    for(int f=0;f<s.size();f++)
    {
        printf("dp[%d][%d]=%d\n",i,f,dp[i][f]);
    }
}
int main()
{
    int n,m,a;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        s.clear();
        memset(dp,0,sizeof(dp));
        memset(can,0,sizeof(can));

        int tmp=1<<m;
        for(int i=0;i<tmp;i++)
        {
            if( (i&(i<<1))==0) s.push_back(i);
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                scanf("%d",&a);
                if(!a) can[i]+=(1<<(m-j));             //相当于对每一行的01串取反
            }
        }
        for(int i=0;i<s.size();i++) //计算dp的初始值，即第1行的第i种状态的值
        {
            if((s[i]&can[1])==0)      //can[1]的0位置才能够出现1，can[1]的1位置只能出现0
            {
                dp[1][i]=1;
            }
        }

        for(int i=2;i<=n;i++)           //从第二行开始递推
        {
            for(int j=0;j<s.size();j++) //第i行选择一个状态
            {
                if((s[j]&can[i])==0)
                {
                    for(int k=0;k<s.size();k++) //第i-1行选择一个状态
                    {
                        if( ((s[k]&can[i-1]) ==0)&& ((s[j]&s[k])==0) )  //i行和i-1行的状态没有上下相邻的1
                        {
                            dp[i][j]=(dp[i][j]+dp[i-1][k])%100000000;
                        }
                    }
                }
            }
         //   debug(i);
        }
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            ans=(ans+dp[n][i])%100000000;
        }
        printf("%d\n",ans);
    }
    return 0;
}