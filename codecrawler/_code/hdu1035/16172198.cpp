/*
    HDU1035
    ï¿½ï¿½ï¿½â£º
    ï¿½ï¿½ï¿½ï¿½Ò»ï¿½ï¿½ï¿½Ö·ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½N S W Eï¿½Ö±ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ï£ï¿½ï¿½Â£ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ç°ï¿½ï¿½ 
    Ä£ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ð¶Ï£ï¿½
    ï¿½ï¿½ï¿½ï¿½ï¿½ß³ï¿½ï¿½Ö·ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Yesï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ 
    ï¿½ï¿½ï¿½ß²ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ã´ï¿½Ø¶ï¿½ï¿½ï¿½È¦ï¿½ï¿½ï¿½Ú£ï¿½ï¿½Ø¶ï¿½ï¿½Ú¾ï¿½ï¿½ï¿½ï¿½Ð´ï¿½ï¿½ï¿½Ò»ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ÊµÚ¶ï¿½ï¿½ï¿½
*/
 
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <set>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;

#define input freopen("input.txt","r",stdin)
#define output freopen("output.txt","w",stdout)
#define For1(i,a,b) for (i=a;i<b;i++)
#define For2(i,a,b) for (i=a;i<=b;i++)
#define Dec(i,a,b) for (i=a;i>b;i--)
#define Dec2(i,a,b) for (i=a;i>=b;i--)
#define Sca_d(x) scanf("%d",&x)
#define Sca_s(x) scanf("%s",x)
#define Sca_c(x) scanf("%c",&x)
#define Sca_f(x) scanf("%f",&x)
#define Sca_lf(x) scanf("%lf",&x)
#define Fill(x,a) memset(x,a,sizeof(x))
#define MAXN 1110
#define MAXM 1110
#define MAXINT 111111

template <typename T>
T gcd(T a,T b)
{
    return b==0?a:gcd(b,a%b);  
}

template <typename T>  
T lcm(T a,T b)  
{  
    return a/gcd(a,b)*b;  
}

char dir_ch[5]={' ','W','S','E','N'};
int dir_x[5]={0,0,1,0,-1};
int dir_y[5]={0,-1,0,1,0};
//ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ä£ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Òµï¿½ï¿½ï¿½Ä¸ï¿½Ð¶ï¿½

char map[MAXN][MAXM];
int dist[MAXN][MAXM];
char ch[MAXM];
int m,n,enter;

void dfs(int x,int y)
{
    int newx,newy,k;
    For2(k,1,4)
        if (map[x][y]==dir_ch[k])//ï¿½ï¿½ï¿½ï¿½ï¿½Ä¸ï¿½ï¿½ï¿½ï¿½ò£¬¾ï¿½ï¿½ï¿½ï¿½Ç¸ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ 
        {
            newx=x+dir_x[k];
            newy=y+dir_y[k];
            if (newx<1||newx>n||newy>m||newy<1)//ï¿½ï¿½ï¿½ï¿½ï¿½Ü³ï¿½ï¿½Ëµï¿½Í¼Ö®ï¿½â£¬ï¿½ï¿½ï¿½Ñ¾ï¿½ï¿½ï¿½ï¿½Ë¾ï¿½ï¿½ï¿½ 
            {
                printf("%d step(s) to exit\n",dist[x][y]);
                return;
            }
            if (!dist[newx][newy])
            {
                dist[newx][newy]=dist[x][y]+1;//Ã»ï¿½ï¿½Ä¿ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ 
                dfs(newx,newy);
            }
            else
            {
                printf("%d step(s) before a loop of %d step(s)\n",
                    dist[newx][newy]-1,dist[x][y]+1-dist[newx][newy]);
                //ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ç°ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ó½Úµï¿½Ö®Ç°ï¿½Ñ¾ï¿½ï¿½ï¿½ï¿½Ê¹ï¿½
                //ï¿½ï¿½Ã´ï¿½ï¿½ï¿½Ø¶ï¿½ï¿½ï¿½Ô­Í¼Ö®ï¿½Ð²ï¿½ï¿½ï¿½ï¿½Ë»ï¿½ï¿½ï¿½
                //ï¿½ï¿½ï¿½Ð£ï¿½ï¿½ï¿½ï¿½Ä³ï¿½ï¿½ï¿½Îª dist[x][y]+1-dist[newx][newy]
                //ï¿½ï¿½ dist[newx][newy]-1 ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ê¼ï¿½ï¿½ï¿½Ö»ï¿½ 
                return;
            }
        }
    return;
}

int main()
{
    //input; 
    int i,j,k;
    while(cin>>n>>m>>enter)
    {
        if (!n&&!m) break;
        Fill(dist,0);
        For2(i,1,n) 
        {
            Sca_s(ch);
            For2(j,1,m)
                map[i][j]=ch[j-1];
        }
        dist[1][enter]=1;
        dfs(1,enter);
    }
    return 0;
}
/*
ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Input 
3 6 5
NEESWE
WWWESS
SNWWWW
4 5 1
SESWE
EESNW
NWEEN
EWSEN
0 0
*/ 