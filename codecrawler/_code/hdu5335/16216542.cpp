#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
#include<string>
#pragma comment(linker, "/STACK:102400000,102400000")
typedef long long ll;
using namespace std;
const ll maxn=1005;
int T,n,m,f[maxn][maxn],c[maxn][maxn],tot;
char s[maxn][maxn];

void dfs(int x,int y)
{
    if (c[x][y]) return ;
    c[x][y]=1;
    if (s[x][y]=='1') return;
    f[x][y]=1;
    if(x+y>tot) tot=x+y;
    if (x>1) dfs(x-1,y);
    if (x<n) dfs(x+1,y);
    if (y>1) dfs(x,y-1);
    if (y<m) dfs(x,y+1);
}

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        memset(f,0,sizeof(f));
        memset(c,0,sizeof(c));
        scanf("%d%d",&n,&m);
        tot=1;
        for (int i=1;i<=n;i++)
        {
            scanf("%s",s[i]+1);
        }
        dfs(1,1);
        if(tot==n+m)
        {printf("0\n");continue;}
        if(tot==1)
        {
            tot=2;
            f[1][1]=1;
            printf("%d",1);
        }
        for (int i=tot;i<n+m;i++)
        {
            int flag=1;
            for (int j=max(1,i-m);j<=min(n,i-1);j++)
            if (f[j][i-j])
            {
                int x=j<n?s[j+1][i-j]-'0':1;
                int y=i-j<m?s[j][i-j+1]-'0':1;
                flag=min(flag,min(x,y));
            }
            for (int j=max(1,i-m);j<=min(n,i-1);j++)
            if (f[j][i-j])
            {
                int x=j<n?s[j+1][i-j]-'0':1;
                int y=i-j<m?s[j][i-j+1]-'0':1;
                if (x==flag) f[j+1][i-j]=1;
                if (y==flag) f[j][i-j+1]=1;
            }
            printf("%d",flag);
        }
        printf("\n");
    }
    return 0;
}