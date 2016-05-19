#include<cstdio>
#include<cstring>
const int maxn = 217;
char mp[maxn][maxn];
int vis[maxn];
int n,m;
int ok(int a,int b)
{
    int i, j;
    for(i = b; i <= m; i++)
    {
        if(mp[a][i]!=mp[a][b])
            break;
    }
    i--;
    for(j = a+1; j <= n; j++) //è¡
    {
        for(int k = b; k <= i; k++)//å
        {
            if(k==b||k==i)//è¾¹ç¼ä¸ç¸å
            {
                if(mp[j][k]!=mp[a][b])
                    return 0;
            }
            else if(mp[j][k]!='.')//åºè¾¹
            {
                for(int l = b; l <= i; l++)
                {
                    if(mp[j][l]!=mp[a][b])
                        return 0;
                }
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    int i,j;
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0 && m == 0)
            break;
        memset(vis,0,sizeof vis);
        for(int i = 0; i < n; i++)
        {
            scanf("%s",mp[i]);
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(mp[i][j]!='.'&&vis[mp[i][j]-'A']==0)
                {
                    vis[mp[i][j]-'A']=1;
                    if(ok(i,j))
                        vis[mp[i][j]-'A']=2;
                }
            }
        }
        int flag=1;
        for(int i = 0; i < 26; i++)
        {
            if(vis[i] == 2)
            {
                if(flag)
                    printf("%c",i+'A');
                else
                    printf(" %c",i+'A');
            }
        }
        puts("");
    }

}
