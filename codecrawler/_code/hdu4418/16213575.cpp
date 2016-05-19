#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
#include<queue>
#define inf 1<<28
#define M 6000005
#define N 205
#define maxn 300005
#define eps 1e-8
#define zero(a) fabs(a)<eps
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb(a) push_back(a)
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
#define lson step<<1
#define rson step<<1|1
using namespace std;
int n,m,y,x,s,d,e;
double p[N],a[N][N];
int cnt,id[N],g[N];
void debug(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=n;j++)
           printf("%.2f ",a[i][j]);
        printf("\n");
    }
}
bool bfs(){
    queue<int>que;
    que.push(s);
    cnt=0;mem(id,-1);
    id[s]=cnt++;
    bool flag=false;
    while(!que.empty()){
        int u=que.front();que.pop();
        for(int i=1;i<=m;i++){
            int v=(u+i)%(2*n-2);
            if(zero(p[i])) continue;
            if(id[v]!=-1) continue;
            id[v]=cnt++;
            if(g[v]==y) {flag=true;}
            que.push(v);
        }
    }
    return flag;
}
void Bulid(){
    mem(a,0);
    for(int i=0;i<(2*n-2);i++){
        if(id[i]==-1) continue;
        int u=id[i];
        a[u][u]=1;
        if(g[i]==y){a[u][cnt]=0;continue;}
        for(int j=1;j<=m;j++){
            int v=(i+j)%(2*n-2);
            if(id[v]==-1) continue;
            v=id[v];
            a[u][v]-=p[j];
            a[u][cnt]+=p[j]*j;
        }
    }
}
bool gauss(int n){
    int i,j;
    for(i=0,j=0;i<n&&j<n;j++){
        int k;
        for(k=i;k<n;k++)
            if(!zero(a[k][j]))
                break;
        if(k<n){
            if(i!=k)
            for(int r=j;r<=n;r++) swap(a[i][r],a[k][r]);
            double tt=1/a[i][j];
            for(int r=j;r<=n;r++)
                a[i][r]*=tt;
            for(int r=0;r<n;r++)
                if(r!=i){
                    for(int t=n;t>=j;t--)
                        a[r][t]-=a[r][j]*a[i][t];
                }
            i++;
        }
    }
    for(int r=i;r<n;r++)
        if(!zero(a[r][n]))
            return false;
    return true;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d%d",&n,&m,&y,&x,&d);
        for(int i=1;i<=m;i++){scanf("%lf",&p[i]);p[i]/=100.0;}
        if(x==y){printf("0.00\n");continue;}
        if(d==0)s=x;
        else if(d==1) s=n+(n-2-x);
        else s=x;
        for(int i=0;i<n;i++) g[i]=i;
        for(int i=n,j=n-2;j>=1;j--,i++) g[i]=j;
        if(!bfs()){puts("Impossible !");continue;}
        Bulid();
        if(!gauss(cnt)) puts("Impossible !");
        else{
            for(int i=0;i<cnt;i++)
                if(zero(a[i][0]-1)){
                    double ans=a[i][cnt];
                    if(zero(ans)) printf("0.00\n");
                    else  printf("%.2f\n",ans);
                    break;
                }
        }
    }
    return 0;
}