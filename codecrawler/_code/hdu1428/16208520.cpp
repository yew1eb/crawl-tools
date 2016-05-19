#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=50+10;
__int64 s[MAX][MAX],dist[MAX][MAX],sum[MAX][MAX];
bool mark[MAX][MAX];
int dir[4][2]={1,0,-1,0,0,1,0,-1};
int n;

void spfa(int x,int y){
    int a,b,oq;
    queue<int>q;
    q.push(x*n+y);
    mark[x][y]=true;
    while(!q.empty()){
        oq=q.front();
        q.pop();
        a=oq/n,b=oq%n;
        mark[a][b]=false;
        for(int i=0;i<4;++i){
            x=a+dir[i][0];
            y=b+dir[i][1];
            if(x<0 || y<0 || x>=n || y>=n)continue;
            if(dist[a][b]+s[x][y]<dist[x][y]){
                dist[x][y]=dist[a][b]+s[x][y];
                if(!mark[x][y])q.push(x*n+y);
                mark[x][y]=true;
            }
        }
    }
}

__int64 dfs(int a,int b){
    if(mark[a][b])return sum[a][b]; 
    int x,y;
    for(int i=0;i<4;++i){
        x=a+dir[i][0];
        y=b+dir[i][1];
        if(x<0 || y<0 || x>=n || y>=n)continue;
        if(dist[x][y]>=dist[a][b])continue;
        sum[a][b]+=dfs(x,y);
    }
    mark[a][b]=true;
    return sum[a][b];
}

void Init(int n){
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            dist[i][j]=INF;
            sum[i][j]=0;
            mark[i][j]=false;
        } 
    }
    dist[n-1][n-1]=s[n-1][n-1];
    sum[n-1][n-1]=1;
}

int main(){
    while(~scanf("%d",&n)){
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j)scanf("%d",&s[i][j]);
        }
        Init(n);
        spfa(n-1,n-1);
        mark[n-1][n-1]=true;
        printf("%I64d\n",dfs(0,0));
    }
    return 0;
}