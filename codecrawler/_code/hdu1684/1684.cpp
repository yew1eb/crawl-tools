/*
Pro: 0

Sol:

date:
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <set>
#include <vector>
#define inf 1100000000
#define maxn 101
using namespace std;
int proj_num,peo_num,t,salary;
int p[maxn][maxn],punish[maxn],reward[maxn];
__int64 dp[maxn][maxn];
int main(){
    scanf("%d",&t);
    while(t --){
        memset(dp,0,sizeof(dp));
        scanf("%d%d%d",&proj_num, &peo_num,&salary);
        for(int i = 1; i <= proj_num; i ++){
            for(int j = 1; j <= peo_num; j ++){
                scanf("%d",&p[i][j]);
            }
            scanf("%d%d",&reward[i],&punish[i]);
        }
        //初始化
        dp[0][0] = 0;
        for(int pro = 1; pro <= proj_num; pro ++){
            dp[pro][0] = dp[pro - 1][0]- punish[pro] * 100;//这里下一个要加上上一个！！！
        }
        for(int peo = 1; peo <= peo_num; peo ++){
            dp[1][peo] = p[1][peo] * (reward[1] - salary * peo) - (100 - p[1][peo]) * punish[1];
        }
        //开始dp了
        for(int pro = 2; pro <= proj_num; pro ++){
            for(int tpeo = 0; tpeo <= peo_num; tpeo ++){
                dp[pro][tpeo] = -inf; //这里赋值为无穷小
                for(int npeo = 0; npeo <= tpeo; npeo ++){
                    dp[pro][tpeo] = max(dp[pro][tpeo], dp[pro - 1][tpeo - npeo] + p[pro][npeo] * (reward[pro] - salary * npeo) - punish[pro] * (100 - p[pro][npeo]));
                }
            }
        }
        __int64 Max = -inf;
        int sub = 0,ans[maxn];
        for(int peo = 0; peo <= peo_num; peo ++){
            if(Max < dp[proj_num][peo])
                Max = dp[proj_num][peo];
        }
        for(int peo = 0; peo <= peo_num; peo ++){
            if(dp[proj_num][peo] == Max){
                ans[sub ++] = peo;
            }
        }
        printf("%I64d\n",Max);
        for(int i = 0; i < sub - 1; i ++)
            printf("%d ",ans[i]);   printf("%d\n",ans[sub - 1]);
    }
	return 0;
}