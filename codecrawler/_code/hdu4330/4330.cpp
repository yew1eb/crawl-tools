#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

#define N 8
#define exp 1e-8
using namespace std;

int map[N][N];
int vis[N][N];
int x[]={0,1};
int y[]={1,0};
char str[20];


inline void balance(int mt[N][N]){
    int i,j,k;
    for (i=0;i<N;i++)
        for (j=N-1;j>=0;j--)
            if (mt[j][i]==-1){
                for (k=j-1;k>=0;k--)
                    if (mt[k][i]!=-1) break;
                if (k<0) break;
                swap(mt[k][i],mt[j][i]);
            }
}
inline int get(int mt[N][N]){
    memset(vis,0,sizeof(vis));
    int i,j,sum=0;
    for (i=0;i<N;i++)
        for (j=0;j<N;j++){
            if (j+2<N&&mt[i][j]==mt[i][j+1]&&mt[i][j]==mt[i][j+2])
                vis[i][j]=vis[i][j+1]=vis[i][j+2]=1;
            if (i+2<N&&mt[i][j]==mt[i+1][j]&&mt[i][j]==mt[i+2][j])
                vis[i][j]=vis[i+1][j]=vis[i+2][j]=1;
        }
    for (i=0;i<N;i++)
        for (j=0;j<N;j++)
            if (vis[i][j]) {mt[i][j]=-1;sum++;}
    if (sum>0) balance(mt);
    return sum;
}

double work(int mtp[N][N],int num){
    int i,j;
    int mt[N][N];
    for (i=0;i<N;i++)
        for (j=0;j<N;j++)
            mt[i][j]=mtp[i][j];
    int su=get(mt);
    if (su==0) return 0.0;
    if (num+su>=8) return 1.0;
    num=num+su;
    vector < pair <int,int> > pi;
    for (i=0;i<N;i++)
        for (j=0;j<N;j++)
            if (mt[i][j]==-1) pi.push_back( make_pair(i,j));
    int zz =1;
    for (i=0;i<pi.size();i++)   zz=zz*5;
    double fm=zz;
    double ans=0;
    for (int t=0;t<zz;t++){
        int p=t;
        for(int i=0;i<pi.size();i++){
            mt[pi[i].first][pi[i].second]=p%5;
            p/=5;
        }
        ans +=work(mt,num);
    }
    return ans/fm;
}

inline double dfs(){
    double ans=0,gs;
    int i,j,k,t,l;
    for (i=0;i<N;i++)
        for (j=0;j<N;j++)
            for (k=0;k<2;k++){
                if (i+x[k]<N&&j+y[k]<N){
                    swap(map[i][j],map[i+x[k]][j+y[k]]);
                    gs=work(map,0);
                    swap(map[i][j],map[i+x[k]][j+y[k]]);
                    ans=max(ans,gs);
                    if (1-ans<exp) goto end;
                }
            }
    end: return ans;
}
inline void init(){
    int i,j;
    for (i=0;i<N;i++){
        scanf("%s",str);
        for (j=0;j<N;j++)
            map[i][j]=str[j]-'0';
    }
}

int main(){
    int test;
    scanf("%d",&test);
    for (int cas=1;cas<=test;cas++){
        init();
        printf("Case #%d: %.3lf\n",cas,dfs());
    }
    return 0;
}