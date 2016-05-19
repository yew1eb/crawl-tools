#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <iomanip>
#define INF 99999999
typedef long long LL;
using namespace std;

const int MAX=10+6;
int n,m,size,temp;
int dp[1<<MAX][MAX],dist[MAX][MAX];
int dir[4][2]={0,1,0,-1,1,0,-1,0};
int mp[MAX][MAX],d[MAX][MAX];
char s[MAX][MAX];
bool mark[MAX][MAX],w[MAX];

int BFS(int ii,int jj,int a,int b){//æ±æç­è·¯ 
    queue<int>xx,yy;
    if(ii == a && jj == b)return 0;
    xx.push(ii);
    yy.push(jj);
    int x,y,nx,ny;
    memset(mark,false,sizeof mark);
    mark[ii][jj]=true;
    d[ii][jj]=0;
    while(!xx.empty()){
        x=xx.front();
        y=yy.front();
        xx.pop();
        yy.pop();
        for(int i=0;i<4;++i){
            nx=x+dir[i][0];
            ny=y+dir[i][1];
            if(nx<0 || ny<0 || nx>=n || ny>=m || s[nx][ny] == 'D')continue;
            if(mark[nx][ny])continue;
            mark[nx][ny]=true;
            d[nx][ny]=d[x][y]+1;
            if(nx == a && ny == b)return d[nx][ny];
            xx.push(nx);
            yy.push(ny);
        } 
    }
    return INF; 
}

void Init(){//éå»ºå¾æ±æç­è·¯ 
    memset(mp,-1,sizeof mp);
    memset(w,false,sizeof w);
    size=temp=1;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(s[i][j] == 'D' || s[i][j] == 'S')continue;
            for(int a=i;a<n;++a){
                for(int b=(a == i?j:0);b<m;++b){
                    if(s[a][b] == 'D' || s[a][b] == 'S')continue;
                    if(mp[a][b] == -1){
                        if(s[a][b] == 'F')mp[a][b]=0;
                        else mp[a][b]=size++;
                    }
                    if(s[a][b] == 'G')w[mp[a][b]]=true;
                    else temp=(temp|(1<<mp[a][b]));
                    dist[mp[a][b]][mp[i][j]]=dist[mp[i][j]][mp[a][b]]=BFS(i,j,a,b);
                }
            }
        }
    }
}

bool DP(int mid){//TSP
    int bit=1<<size;
    memset(dp,-1,sizeof dp);
    dp[1][0]=mid;
    for(int i=1;i<bit;++i){
        for(int j=0;j<size;++j){
            if(dp[i][j] == -1)continue;
            if((i&temp) == temp)return true;
            for(int k=0;k<size;++k){
                int p=1<<k;
                if(i&p)continue;
                dp[i|p][k]=max(dp[i|p][k],dp[i][j]-dist[j][k]);
                if(dp[i|p][k]>=0 && w[k])dp[i|p][k]=mid;
            }
        }
    }
    return false;
}

int main(){
    while(~scanf("%d%d",&n,&m),n+m){
        for(int i=0;i<n;++i)scanf("%s",s[i]);
        Init();//åå§åæç­è·¯
        int l=0,r=0;
        for(int i=0;i<size;++i){
            for(int j=i+1;j<size;++j){
                if(dist[i][j] == INF)continue;
                r=max(r,dist[i][j]*(size-1));
            }
        }
        int minn=INF;
        while(l<=r){
            int mid=l+r>>1;
            if(DP(mid))r=mid-1,minn=min(minn,mid);
            else l=mid+1;
        }
        if(minn == INF)printf("-1\n");
        else printf("%d\n",minn);
    }
    return 0;
}