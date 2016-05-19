#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
char s[15][15];
int vis[15][15],mp[15][15],dir[4][2]={0,1,0,-1,1,0,-1,0};
int ok=0,v[100],tt,cnt;
pair<int,int>pp[100];
void dfs(int x,int y)
{
    if(cnt>=2){   //å¦æç©ºè¶è¿ä¸¤ä¸ªï¼å°±ä¸è¡äºã
    ok=1;
    return;}
    if(ok)return;
    for(int i=0;i<4;i++)
    {
        int fx,fy;
        fx=x+dir[i][0];
        fy=y+dir[i][1];
        if(vis[fx][fy]||mp[fx][fy]==-1)continue;
        if(!vis[fx][fy]){
            vis[fx][fy]=1;
            if(mp[fx][fy]==0){cnt++;}
            if(mp[fx][fy]==1){
            for(int j=1;j<=tt;j++)
            {
                if(!v[j]){
                    if(pp[j].first==fx&&pp[j].second==fy){
                        v[j]=1;
                        break;
                    }
                }
            }
            dfs(fx,fy);
            }
         //   vis[fx][fy]=0;             æ³¨æè¿éï¼æè¿å°±ä¸è¦åèµ°åå»äºï¼å¦åä¼åºç°éå¤è®¡æ°çæåµ
        }
    }
    if(cnt>=2){
        ok=1;
        return;
    }
}
int main()
{
    int T,i,j,k,icase=0;
    scanf("%d",&T);
    while(T--)
    {
        icase++;
        tt=0;
        memset(vis,0,sizeof(vis));
        memset(v,0,sizeof(v));
        memset(mp,-1,sizeof(mp));
        for(i=1;i<=9;i++)
        for(j=1;j<=9;j++)
        {
            cin>>s[i][j];
            if(s[i][j]=='x')mp[i][j]=-1;
            if(s[i][j]=='o'){
            mp[i][j]=1;
            pp[++tt]=make_pair(i,j);
            }
            if(s[i][j]=='.')mp[i][j]=0;
        }
    int flag=0;
    for(i=1;i<=tt;i++)
    {
        ok=0;
        cnt=0;
        if(!v[i]){
            memset(vis,0,sizeof(vis));
            vis[pp[i].first][pp[i].second]=1;
            dfs(pp[i].first,pp[i].second);
            if(ok==0){
                flag=1;break;
            }
            v[i]=1;
        }
    }
    
    printf("Case #%d: ",icase);
  if(flag)printf("Can kill in one move!!!\n");
  else printf("Can not kill in one move!!!\n");
    }
}
/*
2
o.o...ox.
x......o.
o.xo.....
..oxo....
...o.....
.........
.......o.
o........
oox......

ooooooooo
xx.xxxxx.
xxxo.....
.........
.........
.........
.........
.........
.........

.........
...xx....
..xoox...
..xox....
....xx...
..xooo...
...xxx...
.........
.........


..x.x....
.xo.ox...
.xooox...
..xxx....
.........
.........
.........
.........
.........


*/