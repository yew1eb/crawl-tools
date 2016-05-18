#include<stdio.h>
int main()
{
    int n,i,j,x,m,dp[1005];
    while(scanf("%d",&n)!=EOF&&n)
    {
        dp[1]=0;m=0;  //m代表最长递减序列个数   
		//dp[i]代表第i个最长递减序列中当前状态的所含元素最小值 
        for(i=1;i<=n;i++)
        {    
            scanf("%d",&x);
			//将当前状态值与之前阶段值对比
            for(j=1;j<=m;j++) 
            {
            	//如果比某个历史阶段的值小，则覆盖，读取下一状态值 
            	if(x<=dp[j])
				{
					dp[j]=x;
					break;
				}
            }  
			//如果当前状态值比之前阶段值都大，则新增序列
			//新增的序列最小元素值为当前状态值   
            if(j>m)
				dp[++m]=x;
        }
        printf("%d\n",m);
    }
    return 0;
}