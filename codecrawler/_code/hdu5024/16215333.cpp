#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<string>
#include<map>
#define N 111
#define LL long long
using namespace std;

int n,ans;
char g[N][N];
//å«ä¸ªdfså ä¸ºè¦ç¸äºè°ç¨ï¼æç¨ç±»åè£ã
class dfs
{
public:
    //x,y,såå«è¡¨ç¤ºåæ åè·¯é¿ï¼væ¯è®°å½åçè¿å æ¬¡è½¬åã
    void dfsl(int x,int y,int s,int v) //åå·¦ã
    {
        ans=max(ans,s);
        if(y-1>=0 && g[x][y-1]=='.') //è¿è½åå·¦
            dfsl(x,y-1,s+1,v);
        else
        {
            if(v<1)//å¦ååä¸æåä¸
            {
                if(x-1>=0 && g[x-1][y]=='.') dfsu(x-1,y,s+1,v+1);
                if(x+1<n && g[x+1][y]=='.') dfsd(x+1,y,s+1,v+1);
            }
            return ;
        }
    }
    void dfsr(int x,int y,int s,int v) //åå³ã
    {
        ans=max(ans,s);
        if(y+1<n && g[x][y+1]=='.')
            dfsr(x,y+1,s+1,v);
        else
        {
            if(v<1)
            {
                if(x-1>=0 && g[x-1][y]=='.') dfsu(x-1,y,s+1,v+1);
                if(x+1<n && g[x+1][y]=='.') dfsd(x+1,y,s+1,v+1);
            }
            return ;
        }
    }
    void dfsu(int x,int y,int s,int v) //åä¸ã
    {
        ans=max(ans,s);
        if(x-1>=0 && g[x-1][y]=='.')
            dfsu(x-1,y,s+1,v);
        else
        {
            if(v<1)
            {
                if(y-1>=0 && g[x][y-1]=='.') dfsl(x,y-1,s+1,v+1);
                if(y+1<n && g[x][y+1]=='.') dfsr(x,y+1,s+1,v+1);
            }
            return ;
        }
    }
    void dfsd(int x,int y,int s,int v) //åä¸ã
    {
        ans=max(ans,s);
        if(x+1<n && g[x+1][y]=='.')
            dfsd(x+1,y,s+1,v);
        else
        {
            if(v<1)
            {
                if(y-1>=0 && g[x][y-1]=='.') dfsl(x,y-1,s+1,v+1);
                if(y+1<n && g[x][y+1]=='.') dfsr(x,y+1,s+1,v+1);
            }
            return ;
        }
    }
    void dfslu(int x,int y,int s,int v) //åå·¦ä¸ã
    {
        ans=max(ans,s);
        if(x-1>=0 && y-1>=0 && g[x-1][y-1]=='.')
            dfslu(x-1,y-1,s+1,v);
        else
        {
            if(v<1)
            {
                if(x+1<n && y-1>=0 && g[x+1][y-1]=='.')
                    dfsld(x+1,y-1,s+1,v+1);
                if(x-1>=0 && y+1<n && g[x-1][y+1]=='.')
                    dfsru(x-1,y+1,s+1,v+1);
            }
            return ;
        }
    }
    void dfsrd(int x,int y,int s,int v) //åå³ä¸ã
    {
        ans=max(ans,s);
        if(x+1<n && y+1<n && g[x+1][y+1]=='.')
            dfsrd(x+1,y+1,s+1,v);
        else
        {
            if(v<1)
            {
                if(x+1<n && y-1>=0 && g[x+1][y-1]=='.')
                    dfsld(x+1,y-1,s+1,v+1);
                if(x-1>=0 && y+1<n && g[x-1][y+1]=='.')
                    dfsru(x-1,y+1,s+1,v+1);
            }
            return ;
        }
    }
    void dfsru(int x,int y,int s,int v) //åå³ä¸ã
    {
        ans=max(ans,s);
        if(x-1>=0 && y+1<n && g[x-1][y+1]=='.')
            dfsru(x-1,y+1,s+1,v);
        else
        {
            if(v<1)
            {
                if(x-1>=0 && y-1>=0 && g[x-1][y-1]=='.')
                    dfslu(x-1,y-1,s+1,v+1);
                if(x+1<n && y+1<n && g[x+1][y+1]=='.')
                    dfsrd(x+1,y+1,s+1,v+1);
            }
            return ;
        }
    }
    void dfsld(int x,int y,int s,int v) //åå·¦ä¸ã
    {
        ans=max(ans,s);
        if(x+1<n && y-1>=0 && g[x+1][y-1]=='.')
            dfsld(x+1,y-1,s+1,v);
        else
        {
            if(v<1)
            {
                if(x-1>=0 && y-1>=0 && g[x-1][y-1]=='.')
                    dfslu(x-1,y-1,s+1,v+1);
                if(x+1<n && y+1<n && g[x+1][y+1]=='.')
                    dfsrd(x+1,y+1,s+1,v+1);
            }
            return ;
        }
    }
};

int main()
{
    while(~scanf("%d",&n),n)
    {
        for(int i=0;i<n;i++)
            scanf("%s",g[i]);
        dfs q;
        ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(g[i][j]=='.')
                {
                    if(j-1>=0 && g[i][j-1]=='.')
                        q.dfsl(i,j-1,1,0);
                    if(j+1<n && g[i][j+1]=='.')
                        q.dfsr(i,j+1,1,0);
                    if(i-1>=0 && g[i-1][j]=='.')
                        q.dfsu(i-1,j,1,0);
                    if(i+1<n && g[i+1][j]=='.')
                        q.dfsd(i+1,j,1,0);
                    if(i-1>=0 && j-1>=0 && g[i-1][j-1]=='.')
                        q.dfslu(i-1,j-1,1,0);
                    if(i+1<n && i+1<n && g[i+1][j+1]=='.')
                        q.dfsrd(i+1,j+1,1,0);
                    if(i+1<n && j-1>=0 && g[i+1][j-1]=='.')
                        q.dfsld(i+1,j-1,1,0);
                    if(i-1>=0 && j+1<n && g[i-1][j+1]=='.')
                        q.dfsru(i-1,j+1,1,0);
                }
            }
        }
        printf("%d\n",ans+1); //ans+1.å ä¸ºææ²¡ç®èµ·å§ç¹ã
    }
    return 0;
}
