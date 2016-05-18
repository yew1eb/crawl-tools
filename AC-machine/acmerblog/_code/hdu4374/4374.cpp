#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <list>
using namespace std;

const int INF = 0x3f3f3f3f;
int map[110][10010];
int dp[110][10010];
int sum[10010];

struct node
{
    int x;
    int data;
};

inline int maxx(int a, int b)
{
    if(a > b)
        return a;
    return b;
}
int main()
{
    int n,m,x,t;
    struct node r;
    while(~scanf("%d %d %d %d",&n,&m,&x,&t))
    {
        list <node> q;

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                scanf("%d",&map[i][j]);

        for(int i = 1; i <= n; i++)
            for(int j =1; j <= m; j++)
                dp[i][j] = -INF;  //初始化为负无穷
        dp[1][x] = map[1][x];
        for(int j = x-1; j >= 1 && j >= x-t; j--)
            dp[1][j] = dp[1][j+1]+map[1][j];
        for(int j = x+1; j <= m && j <= x+t; j++)
            dp[1][j] = dp[1][j-1]+map[1][j];


        for(int i = 2; i <= n; i++)
        {
            sum[0] = 0;
            q.clear(); //清空
            for(int j = 1; j <= m; j++)
            {
                sum[j] = sum[j-1]+map[i][j];//1—j的和
                while(!q.empty() && q.front().x < j-t)
                    q.pop_front(); //把 小于 j-t的都删除，因为他们不可能到j
                int tmp = dp[i-1][j]-sum[j-1]; //要进队列
                while(!q.empty() && q.back().data <= tmp)
                    q.pop_back();//把小于tmp删除，因为他们是无意义的
                r.x = j;
                r.data = tmp;
                q.push_back(r);
                dp[i][j] = q.front().data + sum[j]; //取队首最大的
            }
            //同上，从右向左
            q.clear();
            sum[m+1] = 0;
            for(int j = m; j >= 1; j--)
            {
                sum[j] = sum[j+1]+map[i][j];
                while(!q.empty() && q.front().x > j+t)
                    q.pop_front();
                int tmp = dp[i-1][j]-sum[j+1];
                while(!q.empty() && q.back().data <= tmp)
                    q.pop_back();
                r.x = j;
                r.data = tmp;
                q.push_back(r);
                dp[i][j] = maxx(dp[i][j], q.front().data+sum[j]);
            }
        }

        int ans = dp[n][1];
        for(int i = 2; i <= m; i++)
            ans = maxx(ans,dp[n][i]);
        printf("%d\n",ans);
    }
    return 0;
}