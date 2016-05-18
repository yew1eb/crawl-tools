#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cctype>
#include <stack>
#include <deque>
using namespace std;
typedef  __int64 LL;
#define eps 10e-9
#define inf 0x3f3f3f3f
const int maxn = 100+20;
const int mod  = 1000000000+7;
char ma[maxn][maxn];
bool vis[maxn][maxn][2][2];
struct node{
    int x,y,step;
    int f1,f2;
}s_pos,d_pos,e_pos;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int n,m,t;
void cheak(node &a,node b){
     if(a.x==b.x){
         int start=min(a.y,b.y),end=max(a.y,b.y),find=0;
         for(int i=start+1;i<end;i++){
             if(ma[a.x][i]!='.') {
               find=1; break;
             }
         }
         if(!find){
              a.f1=1;
         }
     }
     if(a.y==b.y){
         int start=min(a.x,b.x),end=max(a.x,b.x),find=0;
         for(int i=start+1;i<end;i++){
             if(ma[i][a.y]!='.') {
                find=1; break;
             }
         }
         if(!find){
              a.f1=1;
         }
     }

}
void cheak2(node &a,node b){
     if(a.x==b.x){
         int start=min(a.y,b.y),end=max(a.y,b.y),find=0;
         for(int i=start+1;i<end;i++){
             if(ma[a.x][i]!='.') {
               find=1; break;
             }
         }
         if(!find){
              a.f2=1;
         }
     }
     if(a.y==b.y){
         int start=min(a.x,b.x),end=max(a.x,b.x),find=0;
         for(int i=start+1;i<end;i++){
             if(ma[i][a.y]!='.') {
                find=1; break;
             }
         }
         if(!find){
              a.f2=1;
         }
     }

}
int bfs(){
    memset(vis,false,sizeof(vis));
    queue<node> q;
    cheak(s_pos,d_pos);
    cheak2(s_pos,e_pos);
    vis[s_pos.x][s_pos.y][s_pos.f1][s_pos.f2]=true;

    q.push(s_pos);
    while(!q.empty()){
        node now = q.front();q.pop();
        if(now.f1>0&&now.f2>0){
           return now.step;
        }
        for(int i=0;i<4;i++){
            node next=now;
            next.x+=dx[i];next.y+=dy[i];
            if(next.x>=0&&next.x<n&&next.y>=0&&next.y<m&&!vis[next.x][next.y][next.f1][next.f2]
               &&ma[next.x][next.y]=='.'){
                  vis[next.x][next.y][next.f1][next.f2]=true;
                  next.step++;
                  if(!next.f1)
                  cheak(next,d_pos);

                  if(!next.f2)
                  cheak2(next,e_pos);
                  if(next.step<=t)
                  q.push(next);

            }
        }
    }
    return 10000;
}
int main(){
    int  T,ca=1;
    cin>>T;
    while(T--){
       scanf("%d %d %d",&n,&m,&t);
       for(int i=0;i<n;i++)
            scanf("%s",ma[i]);

       for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
             if(ma[i][j]=='S'){
                  s_pos.x=i;s_pos.y=j;
                  s_pos.step=0;
                  s_pos.f1=s_pos.f2=0;
             }
             if(ma[i][j]=='D'){
                 d_pos.x=i;d_pos.y=j;
             }
             if(ma[i][j]=='E'){
                 e_pos.x=i;e_pos.y=j;
             }
          }
       }
       int now=bfs();
       printf("Case %d:\n",ca++);
       if(now<=t) printf("%d\n",now);
       else       printf("-1\n");

    }
    return 0;
}


