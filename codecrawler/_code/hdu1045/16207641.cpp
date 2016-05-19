#include <stdio.h>
#include <string.h>

int n;
int map[10][10];//-1ä¸ºå¢ï¼1ä¸ºç®å°ï¼0å¯è¡
int to[4][2] = {1,0,-1,0,0,1,0,-1};
int cnt,l;

struct node
{
    int x,y;
}a[20];

int judge(int x,int y)
{
    if(x<0 || y<0 || x>=n || y>=n)
    return -1;
    return map[x][y];
}

int check(int k)
{
    int flag = 0;
    int x,y;
    for(int i = 0;i<4;i++)
    {
        if(flag)
        break;
        x = a[k].x+to[i][0];
        y = a[k].y+to[i][1];
        while(x>=0 && y>=0 && x<n && y<n)//ä¸ç´æ¾å°ä¸´çç¹
        {
            int t = judge(x,y);
            if(t == -1)
            break;
            if(t == 1)//æ¾å°æ­¤è¡ææ­¤åå·²ç»æç®å°å³éåº
            {
                flag =1;
                break;
            }
            x+=to[i][0];
            y+=to[i][1];
        }
    }
    return flag;
}

void dfs(int x,int turn)
{
    int i,j;
    if(turn>cnt) cnt = turn;
    if(x==l)
    return;
    dfs(x+1,turn);
    if(!check(x))
    {
        map[a[x].x][a[x].y] = 1;
        dfs(x+1,turn+1);
        map[a[x].x][a[x].y] = 0;
    }

}

int main()
{
    int i,j;
    while(scanf("%d",&n),n)
    {
        char s[10];
        l = 0;
        for(i = 0; i<n; i++)
        {
            scanf("%s",s);
            for(j = 0; s[j]; j++)
            {
                if(s[j] == '.')
                {
                    map[i][j] = 0;
                    a[l].x = i;
                    a[l].y = j;
                    l++;
                }
                else
                    map[i][j] = -1;
            }
        }
        cnt = 0;
        dfs(0,0);
        printf("%d\n",cnt);
    }

    return 0;
}
