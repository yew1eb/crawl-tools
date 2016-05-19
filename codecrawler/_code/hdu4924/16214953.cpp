#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<cmath>
#include<vector>
#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define eps 1e-8
#define pi acos(-1.0)
using namespace std;
typedef long long ll;
const int maxn=25;
const int mod=100000;
struct Player
{
    int id,flag[4],CA[4],PA[4],Cmax;
    void clear()
    {
        id=0;
        memset(flag,0,sizeof(flag));
    }
}player[maxn];
int g[110][110],lineup[4],n,m,ans1,ans2;
char str[55];
bool cmp(Player a, Player b)
{
    return a.Cmax > b.Cmax;
}
int getpos()
{
    if(str[0] == 'D') return 0;
    if(str[0] == 'M') return 1;
    if(str[0] == 'S') return 2;
    return 3;
}
int getsign()
{
    if(str[0] == 'L') return 1;
    return -1;
}
void SWAP(int x,int y)
{
    for(int i = 0; i < n;++i)
    {
        swap(player[i].flag[x],player[i].flag[y]);
        swap(player[i].CA[x],player[i].CA[y]);
        swap(player[i].PA[x],player[i].PA[y]);
    }
    swap(lineup[x],lineup[y]);
}
void getlineup()
{
    scanf("%d-%d-%d",&lineup[0],&lineup[1],&lineup[2]);
    if(lineup[0] > lineup[1]) SWAP(0,1);
    if(lineup[1] > lineup[2]) SWAP(1,2);
}
int select[maxn],dp[15][11][11][2],dp2[15][11][11][2];
bool isFind;
inline void Update(int i,int a,int b,int c,int ca,int pa)
{
    if(ca > dp[i][a][b][c])
    {
        dp[i][a][b][c] = ca;
        dp2[i][a][b][c] = pa;
    }
    else if(ca == dp[i][a][b][c] && pa > dp2[i][a][b][c])
        dp2[i][a][b][c] = pa;
}
void cal()
{
    int a = 0,b = 0;
    int cnt[4] = {0};
    for(int i = 0;i < 11;++i)
    {
        for(int j = i;j < 11;++j)
        {
            int u = player[select[i]].id;
            int v = player[select[j]].id;
            a += g[u][v];
            if(i != j) a += g[v][u];
        }
        b += player[select[i]].Cmax;
        for(int j = 0 ;j < 4 ;++j)
            if(player[select[i]].flag[j]) cnt[j]++;
    }
    for(int i =0;i < 4 ;++i)
        if(cnt[i] < lineup[i]) return ;
    if(a + b < ans1) return ;
    b = 0;
    for(int i = 0;i <= 11;++i)
        for(int j = 0;j <= lineup[0];++j)
            for(int k = 0;k <= lineup[1] ;++k)
                for(int l =0 ;l < 2;++l)
                    dp[i][j][k][l] = dp2[i][j][k][l]= -inf;
    dp[0][0][0][0] = 0;
    dp2[0][0][0][0] = 0;
    int ca , pa;
    for(int i = 0;i < 11;++i)
    {
        int t = select[i];
        for(int DF = 0;DF <= lineup[0];++DF)
            for(int MF = 0;MF <= lineup[1];++MF)
                for(int GK = 0;GK < 2; ++GK)
                {
                    if(dp[i][DF][MF][GK] == -inf) continue;
                    int ST=i-GK-DF-MF;
                    ca = dp[i][DF][MF][GK];
                    pa = dp2[i][DF][MF][GK];
                    if(player[t].flag[3] && GK < 1)
                        Update(i+1,DF,MF,GK+1,ca +player[t].CA[3],pa +player[t].PA[3]);
                    if(player[t].flag[0] && DF < lineup[0])
                        Update(i+1,DF+1,MF,GK,ca+player[t].CA[0],pa+player[t].PA[0]);
                    if(player[t].flag[1] && MF < lineup[1])
                        Update(i+1,DF,MF+1,GK,ca+player[t].CA[1],pa+player[t].PA[1]);
                    if(player[t].flag[2] && ST < lineup[2])
                        Update(i+1,DF,MF,GK,ca+player[t].CA[2],pa+player[t].PA[2]);
                }
    }
    if(dp[11][lineup[0]][lineup[1]][1] == -inf) return ;
    a += dp[11][lineup[0]][lineup[1]][1];
    b += dp2[11][lineup[0]][lineup[1]][1];
    if(a > ans1)
    {
        isFind = true;
        ans1 = a;
        ans2 = b;
    }
    else if(a == ans1)
        ans2=max(ans2,b);
}
void dfs(int pos, int now)
{
    if(now == 11)
    {
        cal();
        return ;
    }
    if(pos >= n) return ;
    select[now] = pos;
    dfs(pos + 1,now +1);
    if(n - pos + now < 11) return ;
    dfs(pos + 1,now);
}
int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w ",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(g,0,sizeof(g));
        int num,pos;
        for(int i = 0;i < n ;++i)
        {
            player[i].clear();
            scanf("%d",&player[i].id);
            scanf("%d",&num);
            player[i].Cmax = -inf;
            for(int j = 0;j < num ;++j)
            {
                scanf("%s",str);
                pos = getpos();
                player[i].flag[pos]=1;
                scanf("%d%d",&player[i].CA[pos],&player[i].PA[pos]);
                player[i].Cmax=max(player[i].Cmax,player[i].CA[pos]);
            }
        }
        sort(player , player + n ,cmp);
        scanf("%d",&m);
        int u,v,w;
        for(int i = 0;i < m;++i)
        {
            scanf("%d%d",&u,&v);
            scanf("%s", str);
            scanf("%d",&w);
            g[u][v] = getsign() * w;
        }
        getlineup();
        ans1 = ans2 = -inf;
        isFind = false;
        dfs(0,0);
        if(isFind) printf("%d %d\n",ans1,ans2);
        else printf("Poor Manager!\n");
    }
    return 0;
}
