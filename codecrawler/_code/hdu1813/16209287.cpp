#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#define inf 1<<30
using namespace std;
int n,minval[10][10];
char str[10][10];
int depth;
bool flag;
int ans[1000];
int pre[4]={3,2,1,0};
int way[4][2]={{0,1},{-1,0},{1,0},{0,-1}};
struct Node{
    int x,y;
    bool check(){
        if(x>=0&&x<n&&y>=0&&y<n)
            return true;
        return false;
    }
}tmp,u,v;
int x[100],y[100],cnt;
bool isok(int x,int y){
    if(x==0||x==n-1||y==0||y==n-1)
        return true;
    return false;
}
void bfs(Node s){
    queue<Node>que;
    while(!que.empty())
        que.pop();
    que.push(s);
    minval[s.x][s.y]=0;
    while(!que.empty()){
        u=que.front();
        que.pop();
        for(int i=0;i<4;i++){
            v=u;
            v.x+=way[i][0];
            v.y+=way[i][1];
            if(v.check()&&str[v.x][v.y]=='0'){
                if(minval[v.x][v.y]<=minval[u.x][u.y]

+1)
                    continue;            

    
                minval[v.x][v.y]=minval[u.x][u.y]+1;    
                que.push(v);
            }
        }
    }
}
int get_h(int *t_x,int *t_y){
    int res=0;
    for(int i=0;i<cnt;i++)
        res=max(res,minval[t_x[i]][t_y[i]]);
    return res;
}
void IDAstar(int *t_x,int *t_y,int tmp_depth){
    if(flag)
        return;
    if(get_h(t_x,t_y)>tmp_depth)
        return;
    if(tmp_depth==0){
        flag=true;
        return;
    }
    for(int i=0;i<4;i++){    
        if(flag)
            return;
        int X[100],Y[100];
        for(int j=0;j<cnt;j++){
            X[j]=t_x[j];Y[j]=t_y[j];
            if(isok(X[j],Y[j]))
                continue;
            if(str[X[j]+way[i][0]][Y[j]+way[i][1]]=='0'){
                X[j]+=way[i][0];
                Y[j]+=way[i][1];
            }
        }
        ans[tmp_depth]=i;    
        IDAstar(X,Y,tmp_depth-1);
    }
}
int main(){
    int cas=0;
    while(scanf("%d",&n)!=EOF){
        if(cas++)
            printf("\n");
        for(int i=0;i<n;i++) 
            scanf("%s",&str[i]);
        cnt=0;
        flag=false;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                minval[i][j]=inf;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(str[i][j]=='0'){
                    tmp.x=i;
                    tmp.y=j;
                    if(!isok(i,j)){
                        x[cnt]=i;
                        y[cnt++]=j;
                    }
                    else
                        bfs(tmp);
                }
            }
        }
        if(cnt==0)
            continue;
        for(depth=get_h(x,y);;depth++){
            IDAstar(x,y,depth);
            if(flag){
                for(int i=depth;i>0;i--)
                    switch(ans[i]){
                    case 0:printf("east\n");break;
                    case 3:printf("west\n");break;
                    case 2:printf("south\n");break;
                    case 1:printf("north\n");break;
                }
                break;
            }
        }
    }
    return 0;
}