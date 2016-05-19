#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int r[10][10],c[10][10],vis[10][10],tt;
char s[10][10];
int dir[4][2]={0,1,0,-1,1,0,-1,0};
int  flag;
pair<int,int>pp[20];
bool check()            //å¤æ­4ä¸ª2*2çå°åºååæ¯å¦é½ç¬¦åæ¡ä»¶ã
{
    if(((1<<s[1][1])|(1<<s[1][2])|(1<<s[2][1])|(1<<s[2][2]))!=30)return false;
    if(((1<<s[1][3])|(1<<s[1][4])|(1<<s[2][3])|(1<<s[2][4]))!=30)return false;
    if(((1<<s[3][1])|(1<<s[3][2])|(1<<s[4][1])|(1<<s[4][2]))!=30)return false;
    if(((1<<s[3][3])|(1<<s[3][4])|(1<<s[4][3])|(1<<s[4][4]))!=30)return false;
    return true;
}
void dfs(int cnt)
{
       if(flag)return;
    if(cnt>tt){
    if(check())
    {
         flag=1;
        for(int i=1;i<=4;i++)
        for(int j=1;j<=4;j++)
        s[i][j]=s[i][j]+'0';
        for(int i=1;i<=4;i++)
        {
        for(int j=1;j<=4;j++)
        cout<<(s[i][j]);
           printf("\n");    
    }
    }
    return;
    }

    int x=pp[cnt].first;
    int y=pp[cnt].second;
    for(int i=1;i<=4;i++)
    {
        if(!r[x][i]&&!c[y][i]){
            r[x][i]=c[y][i]=1;
            s[x][y]=i;
            dfs(cnt+1);
            r[x][i]=c[y][i]=0;
        }
    
    }
    if(flag)return;
}
int main()
{
    int T,i,j,k,icase=0;
    scanf("%d",&T);
    while(T--)
    {
        flag=0;
        icase++;
        tt=0;
        memset(r,0,sizeof(r));
        memset(c,0,sizeof(c));
        for(i=1;i<=4;i++)
        for(j=1;j<=4;j++)
        {
            cin>>s[i][j];
            if(s[i][j]=='*'){pp[++tt]=make_pair(i,j);
             s[i][j]=s[i][j]-'0';
            }
            else {
                s[i][j]=s[i][j]-'0';
                int num=s[i][j];
                r[i][num]=1;
                c[j][num]=1;
            }
        }
        printf("Case #%d:\n",icase);
        dfs(1);
        

    }
}
/*
*234
4*21
24*3
3***

2341
1*3*
4123
3*1*
*/