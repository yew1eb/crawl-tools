#include<stdio.h>
#include<string.h>
#define MS(x,y) memset(x,y,sizeof(x))
int casenum,casei;
int n;
char s[10][10];
bool line[4][4];
bool list[4][4];
bool sqr[4][4];
int bl[4][4];
bool dfs(int y,int x)
{
    while(s[y][x]!='*')
    {
        if(++x==4)
        {
            x=0;
            if(++y==4)
            {
                for(int i=0;i<4;i++)puts(s[i]);
                return 1;
            }
        }
    }
    for(int i=0;i<4;i++)if(line[y][i]&&list[x][i]&&sqr[bl[y][x]][i])
    {
        s[y][x]='1'+i;
        line[y][i]=list[x][i]=sqr[bl[y][x]][i]=0;
        if(dfs(y,x))return 1;
        s[y][x]='*';
        line[y][i]=list[x][i]=sqr[bl[y][x]][i]=1;
    }
    return 0;
}
int main()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(i<=1&&j<=1)bl[i][j]=0;
            else if(i>=2&&j>=2)bl[i][j]=3;
            else if(j>=2)bl[i][j]=1;
            else if(i>=2)bl[i][j]=2;
        }
    }
    scanf("%d",&casenum);
    for(casei=1;casei<=casenum;casei++)
    {
        MS(line,1);
        MS(list,1);
        MS(sqr,1);
        for(int i=0;i<4;i++)
        {
            scanf("%s",s[i]);
            for(int j=0;j<4;j++)
            {
                if(s[i][j]!='*')
                {
                    int x=s[i][j]-'1';
                    line[i][x]=0;
                    list[j][x]=0;
                    sqr[bl[i][j]][x]=0;
                }
            }
        }
        printf("Case #%d:\n",casei);
        dfs(0,0);
    }
}
/*
ãé¢æã
ç»ä½ ä¸ä¸ª4*4çå¾å½¢ã
æ¯ä¸ªæ ¼å­å¡«ä¸1ï¼2ï¼3ï¼4
è¦æ±åè¡ååååºåæ²¡æéå¤æ°å­ã
ç»å®ä¸ä¸ªç©å½¢ï¼æäºæ ¼å­æ²¡å¡«ï¼ç¨'*'æ¿ä»£ã
åªæå¯ä¸å¡«åæ¹æ¡ï¼è®©ä½ å¡«å¥½è¿ä¸ªç©å½¢ã

ãç±»åã
dfs

ãåæã
è¿é¢æ¬æ¥å°±ä¸çä¾¿æ¯dfsï¼æ¬æ¥ä¸è¿æ4^16
æ´å ä¸ºè¯´äºåªæä¸ç§æ¹æ¡ãæä»¥æ´åä¸äºå³å¯ã

ãæ¶é´å¤æåº¦&&ä¼åã
O(4^w)

ãæ°æ®ã

*/