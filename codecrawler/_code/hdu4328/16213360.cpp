/*
å¨æç¼éï¼æå¥½çç®æ³æ¨¡æ¿ä»£ç æ¥çå­¦ææ¯çé~
æ­¤é¢æ²¡ç¨åè°éå(ä¸çï¼ä¸ç¥å¦ä½ç¨æ¯å¥½)ï¼ç¨çæ¯æ¬çº¿æ³æ±æå¤§å­ç©éµ
å­¦ä¹ æ­¤æ³å¤§çä»¬é½æ¨èçç¥æçè®ºæï¼å°caiæä¹æ¨èä¸ï¼å¦å¤ä¹æ¨èå¤æå ä¸ªä»£ç ï¼æ¾ä¸ª

å¥½ççæ¨¡ä»¿æ¨¡ä»¿~
*/
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int NN=1002;

int n,m,ans;
bool g[NN][NN];

int l[NN][NN],r[NN][NN],h[NN][NN];
void dp(int c)//å¤ççº¯è²åçæåµ
{
    memset(l,0,sizeof(l));
    memset(h,0,sizeof(h));
    memset(r,0,sizeof(r));
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            if (g[i][j]==c)
            {
                h[i][j]=0;
                l[i][j]=0;
            }
            else
            {
                h[i][j]=h[i-1][j]+1;
                l[i][j]=l[i][j-1]+1;
            }
        }
        for (int j=m; j; j--)
        {
            if (g[i][j]==c) r[i][j]=0;
            else            r[i][j]=r[i][j+1]+1;
        }
    }
    int _left,_right;
    for (int j=1; j<=m; j++)//åä¼å
    {
        for (int i=1; i<=n; i++)
        {
            if (h[i][j]==1)
            {
                _left=l[i][j];//æé£ä¹ç¹å³ç­åè°æ§çæå³
                _right=r[i][j];
            }
            else
            {
                _left=min(_left,l[i][j]);
                _right=min(_right,r[i][j]);
            }
            ans=max(ans,(_right+_left-1)*2+h[i][j]*2);
        }
    }
}

void dp2()//å¤çäº¤åè²åçæåµ
{
    memset(l,0,sizeof(l));
    memset(h,0,sizeof(h));
    memset(r,0,sizeof(r));
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            if (g[i][j]==g[i-1][j]) h[i][j]=1;
            else                    h[i][j]=h[i-1][j]+1;
            if (g[i][j]==g[i][j-1]) l[i][j]=1;
            else                    l[i][j]=l[i][j-1]+1;
        }
        for (int j=m; j; j--)
        {
            if (g[i][j]==g[i][j+1]) r[i][j]=1;
            else                    r[i][j]=r[i][j+1]+1;
        }
    }
    int _left,_right;
    for (int j=1; j<=m; j++)
    {
        for (int i=1; i<=n; i++)
        {
            if (h[i][j]==1)
            {
                _left=l[i][j];
                _right=r[i][j];
            }
            else
            {
                _left=min(_left,l[i][j]);
                _right=min(_right,r[i][j]);
            }
            ans=max(ans,(_right+_left-1)*2+h[i][j]*2);
        }
    }
}

int main()
{
    int T,cas=0;
    char st[NN];
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&n,&m);
        for (int i=1; i<=n; i++)
        {
            scanf("%s",st);
            for (int j=0; j<m; j++)
                g[i][j+1]=(st[j]=='B');
        }
        ans=4;
        dp(0);
        dp(1);
        dp2();
        printf("Case #%d: %d\n",++cas,ans);
    }
    return 0;
}
