#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#define inf 1<<28
#define M 100005
#define N 55
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb(a) push_back(a)
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
#define MOD 1000000007
using namespace std;
struct Point{
    int x,y;
}p[20];
int n,m,val[20],path[20][20];
int dp[16][1<<16],state[1<<16],tot;
int best[1<<16],ok[1<<16];
int dist(Point p1,Point p2){
    return ceil(sqrt((double)(p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)));
}
void Get_dist(){
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) path[i][j]=dist(p[i],p[j]);
}
void Init(){
    for(int i=0;i<n;i++)
        for(int j=0;j<(1<<n);j++)
            dp[i][j]=inf;
    for(int i=0;i<(1<<n);i++)
        best[i]=inf;
    dp[0][1]=0;
}
int check(int state){
    int sum=0;
    for(int i=0;i<n;i++)
        if(state&(1<<i))
            sum+=val[i];
    return sum<=m;
}
bool cmp(int a,int b){return a>b;}
int slove(){
    int dp[1<<16];
    for(int i=0;i<(1<<n);i++) dp[i]=inf;
    dp[0]=0;
    for(int i=0;i<tot;i++){
        for(int j=(1<<n)-1;j>=0;j--){    
            if(dp[j]==inf) continue;
            if(state[i]&j) continue;
            dp[state[i]+j]=min(dp[state[i]+j],dp[j]+1);
        }
    }
    return dp[(1<<n)-1]==inf?-1:dp[(1<<n)-1];
}
int TSP(){
    for(int i=0;i<(1<<n);i++){
        if(ok[i])
            for(int j=0;j<n;j++)
                if(i&(1<<j)){
                    best[i]=min(best[i],dp[j][i]+path[j][0]);
                    for(int k=0;k<n;k++)
                        if(!(i&(1<<k)))
                            dp[k][i|(1<<k)]=min(dp[k][i|(1<<k)],dp[j][i]+path[j][k]);
                }
    }
    for(int i=0;i<(1<<n);i++)
        if(i&1)
            for(int j=i&(i-1);j;j=i&(j-1))
                best[i]=min(best[i],best[j]+best[(i-j)|1]);
    return best[(1<<n)-1];
}

int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        tot=0;
        for(int i=0;i<n;i++) scanf("%d%d",&p[i].x,&p[i].y);
        for(int i=0;i<n;i++) scanf("%d",&val[i]);
        for(int i=0;i<(1<<n);i++) {
            ok[i]=check(i);
            if(ok[i])
                state[tot++]=i;
        }
        Get_dist();
        Init();
        int ans1=slove();
        if(ans1==-1) {printf("-1 -1\n");continue;}
        printf("%d %d\n",ans1,TSP());
    }
    return 0;
}