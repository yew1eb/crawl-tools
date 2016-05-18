#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m;
char map[25][25];
bool vis[25][25][25][25];
bool mark[25][25][25][25];
int dir[4][2]=  {{1,0},{0,1},{-1,0},{0,-1}};
int flag,ans;
struct node
{
    int len;
    int x[2],y[2];
    int holex,holey;
    int step;int find;

} s_pos;
bool cheack(int x,int y){   return x>=0&&x<=n+1&&y>=0&y<=m+1;     }
void bfs()
{
    queue<node > q;
    q.push(s_pos);
    memset(vis,0,sizeof(vis));
    memset(mark,0,sizeof(mark));
    vis[s_pos.x[0]][s_pos.y[0]][s_pos.x[1]][s_pos.y[1]]=true;

    while(!q.empty())
    {
        node now = q.front();
        q.pop();

      if(now.find){
        if(map[now.x[0]][now.y[0]]=='H'&&(now.x[0]!=now.holex||now.y[0]!=now.holey))
          {
            flag=1;   ans=now.step;
            return ;
          }
      }
      else{
          if(map[now.x[0]][now.y[0]]=='H'&&map[now.x[1]][now.y[1]]=='H'&&(now.x[0]!=now.x[1]||now.y[0]!=now.y[1]))
          {
            flag=1;   ans=now.step;
            return ;
          }
        if(map[now.x[0]][now.y[0]]=='H')
        {

            now.holex=now.x[0];  now.holey=now.y[0];
            now.x[0]=now.x[1];   now.y[0]=now.y[1];

            mark[now.holex][now.holey][now.x[0]][now.y[0]]=true;
            now.find=1;  now.len--;
        }
        if(map[now.x[1]][now.y[1]]=='H')
        {
            now.holex=now.x[1];  now.holey=now.y[1];
            mark[now.holex][now.holey][now.x[0]][now.y[0]]=true;
            now.find=1;  now.len--;
        }
      }

        for(int i=0; i<4; i++)
        {
            node next=now;
            next.step+=1;
            for(int j=0; j<next.len; j++)
                next.x[j]+=dir[i][0],  next.y[j]+=dir[i][1];

            if(next.len==2)
            {
                if(cheack(next.x[0],next.y[0])&&cheack(next.x[1],next.y[1]))
                {
                    if(map[next.x[0]][next.y[0]]=='*'&&map[next.x[1]][next.y[1]]=='*')            continue;
                    if(map[next.x[0]][next.y[0]]=='*'&&next.x[1]==now.x[0]&&next.y[1]==now.y[0])  continue;
                    if(map[next.x[1]][next.y[1]]=='*'&&next.x[0]==now.x[1]&&next.y[0]==now.y[1])  continue;

                    if(map[next.x[0]][next.y[0]]=='*'){
                       next.x[0]=now.x[0],   next.y[0]=now.y[0];
                    }
                    if(map[next.x[1]][next.y[1]]=='*'){
                       next.x[1]=now.x[1],   next.y[1]=now.y[1];
                    }


                    if(!vis[next.x[0]][next.y[0]][next.x[1]][next.y[1]])
                    {
                        vis[next.x[0]][next.y[0]][next.x[1]][next.y[1]]=true;
                        q.push(next);
                    }
                }
            }
            else
            {

                if(cheack(next.x[0],next.y[0])&&!mark[next.holex][next.holey][next.x[0]][next.y[0]])
                {

                    mark[next.holex][next.holey][next.x[0]][next.y[0]]=true;
                    if(map[next.x[0]][next.y[0]]=='*')            continue;
                        q.push(next);

                }
            }
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;

        for(int i=0;i<=n+1;i++) for(int j=0;j<=m+1;j++) map[i][j]='*';

        for(int i=1; i<=n; i++) cin>>map[i]+1;

        s_pos.len=0;  s_pos.holex=100;s_pos.holey=100;  s_pos.step=0;  s_pos.find=0;

        for(int i=0;i<=n+1;i++)
        map[i][m+1]='*';

        for(int i=1; i<=n; i++) for(int j=1; j<=m; j++)
                if(map[i][j]=='B')
                {
                    s_pos.x[s_pos.len]=i,s_pos.y[s_pos.len]=j;
                    s_pos.len++;
                }
        flag=0;  ans=0x7fffffff;
        bfs();
        if(flag)
            cout<<ans<<endl;
        else
            cout<<"Sorry , sir , my poor program fails to get an answer."<<endl;

    }
    return 0;

}