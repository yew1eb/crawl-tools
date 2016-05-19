#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#define N 505
#define Max 4
using namespace std;
int num[N],next[N][4],fail[N];
int cnt,root;
int newnode()
{
    fail[cnt] = 0;
    num[cnt] = 0;
    return cnt++;
}
int hash(char s)
{
    if(s == 'A')return 0;
    if(s == 'C')return 1;
    if(s == 'G')return 2;
    if(s == 'T')return 3;
}
void insert(char *str)
{
    int i=0,s;
    int t = root;
    while(str[i])
    {
        s = hash(str[i]);
        if(next[t][s]==0)
            next[t][s]=newnode();
        t = next[t][s];
        i++;
    }
    num[t]++;
}
void build_ac_automation()
{
    queue<int>q;
    int tmp = root;
    q.push(tmp);
    while(!q.empty())
    {
        tmp=q.front();
        q.pop();
        for(int i=0; i<Max; i++)
            if(next[tmp][i]==NULL)
            {
                if(tmp==root)next[tmp][i] = root;
                else next[tmp][i] = next[fail[tmp]][i];
            }
            else
            {
                if(tmp==root)fail[next[tmp][i]] = root;
                else
                {
                    fail[next[tmp][i]] = next[fail[tmp]][i];
                    num[next[tmp][i]]+=num[next[fail[tmp]][i]];
                }
                q.push(next[tmp][i]);
            }
    }
}
char s[50];
int dp[505][11*11*11*11+5];
int sum[4],bit[4];
int main()
{
    int n,i,j,cas = 1;
    while(scanf("%d",&n)&&n)
    {
        cnt = 0;
        root = newnode();
        memset(sum,0,sizeof(sum));
        memset(dp,-1,sizeof(dp));
        memset(next,0,sizeof(next));
        for(i = 1;i<=n;i++)
        {
            scanf("%s",s);
            insert(s);
        }
        build_ac_automation();
        scanf("%s",s);
        int l = strlen(s);
        for(i = 0;i<l;i++)
            sum[hash(s[i])]++;
        bit[0] = (sum[1]+1)*(sum[2]+1)*(sum[3]+1);
        bit[1] = (sum[2]+1)*(sum[3]+1);
        bit[2] = (sum[3]+1);
        bit[3] = 1;
        memset(dp,-1,sizeof(dp));
        dp[root][0] = 0;
        for(int A = 0;A <= sum[0];A++)
            for(int B = 0;B <= sum[1];B++)
                for(int C = 0;C <= sum[2];C++)
                    for(int D = 0;D <= sum[3];D++)
                    {
                        int st = A*bit[0] + B*bit[1] + C*bit[2] + D*bit[3];
                        for(int i = 0;i < cnt;i++)
                            if(dp[i][st] >= 0)
                            {
                                for(int k = 0;k < 4;k++)
                                {
                                    if(k == 0 && A == sum[0])continue;
                                    if(k == 1 && B == sum[1])continue;
                                    if(k == 2 && C == sum[2])continue;
                                    if(k == 3 && D == sum[3])continue;
                                    dp[next[i][k]][st+bit[k]] = max(dp[next[i][k]][st+bit[k]],dp[i][st]+num[next[i][k]]);
                                }
                            }
                    }
        int ans = 0;
        int status = sum[0]*bit[0] + sum[1]*bit[1] + sum[2]*bit[2] + sum[3]*bit[3];
        for(int i = 0;i < cnt;i++)
            ans = max(ans,dp[i][status]);
        printf("Case %d: %d\n",cas++,ans);
    }
    return 0;
}