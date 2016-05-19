#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#pragma comment(linker, "/STACK:102400000,102400000")//æå¨æ©æ 
typedef long long ll;
using namespace std;
const int maxn= 5e5 + 5;
const ll INF = 1000000000000000000;
int p[maxn];
vector<int>q[maxn];
int num[maxn];


void dfs(int u)
{
    num[u]++;
    int len = q[u].size();
    for(int i = 0;i < len;i++)
    {
        int son = q[u][i];
        if(!num[son])
            dfs(son);
        num[u]+=num[son];
    }
}

int main()
{
    int n;
    //freopen("10.txt","r",stdin);
    while(scanf("%d",&n) != EOF)
    {
        for(int i = 1;i <= n;i++)
            scanf("%d",&p[i]);

        int a,b;
        for(int i = 1;i <= n;i++)
            q[i].clear();
        for(int i = 1;i < n;i++)
        {
            scanf("%d%d",&a,&b);
            if(p[a] < p[b])
                q[a].push_back(b);
            else
                q[b].push_back(a);
        }
        int ans = 0;
        memset(num,0,sizeof(num));
        for(int i = 1;i <= n;i++)
        {
            if(!num[i])
                dfs(i);
            ans= max(ans,num[i]);
        }

        printf("%d\n",ans);
    }
}
