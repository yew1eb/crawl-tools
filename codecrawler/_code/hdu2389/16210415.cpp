#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<vector>
#include<cstdlib>
#define lson (rt<<1),L,M
#define rson (rt<<1|1),M+1,R
#define M ((L+R)>>1)
#define cl(a,b) memset(a,b,sizeof(a));
#define LL long long
#define P pair<int,int>
#define X first
#define Y second
#define pb push_back
#define fread(zcc)  freopen(zcc,"r",stdin)
#define fwrite(zcc) freopen(zcc,"w",stdout)
using namespace std;
/*è¿ä¸ªç®æ³æ¯åçå©ç®æ³çæ¶é´å¤æåº¦è¦å°ï¼å¤§æ°æ®å¯ä»¥éç¨è¿ä¸ªç®æ³
äºåå¾å¹éï¼Hopcroft-Carpçç®æ³ï¼ã
åå§åï¼g[][]é»æ¥ç©éµ
è°ç¨ï¼res=MaxMatch();  Nx,Nyè¦åå§åï¼ï¼ï¼
æ¶é´å¤æå¤§ä¸º O(V^0.5 E)
éç¨äºæ°æ®è¾å¤§çäºåå¹é*/
const int MAXN=3005;
const int INF=1<<28;
int g[MAXN][MAXN],Mx[MAXN],My[MAXN],Nx,Ny;
int dx[MAXN],dy[MAXN],dis;
bool vst[MAXN];
struct people{
    int x,y,t;
}p[MAXN];
struct umbrella{
    int x,y;
}um[MAXN];

int inline abs(int x){return x<0?-x:x;}
int inline distance(people a,umbrella b){
    return abs(a.x-b.x)+abs(a.y-b.y);
}
bool searchP(){
    queue<int> Q;
    dis=INF;
    memset(dx,-1,sizeof(dx));
    memset(dy,-1,sizeof(dy));
    for(int i=0;i<Nx;i++)
        if(Mx[i]==-1){
            Q.push(i);
            dx[i]=0;
        }
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        if(dx[u]>dis)break;
        for(int v=0;v<Ny;v++)
            if(g[u][v]&&dy[v]==-1){
                dy[v]=dx[u]+1;
                if(My[v]==-1)
                    dis=dy[v];
                else{
                    dx[My[v]]=dy[v]+1;
                    Q.push(My[v]);
                }
            }
    }
    return dis!=INF;
}

bool DFS(int u){
    for(int v=0;v<Ny;v++)
       if(!vst[v]&&g[u][v]&&dy[v]==dx[u]+1){
           vst[v]=1;
           if(My[v]!=-1&&dy[v]==dis) continue;
           if(My[v]==-1||DFS(My[v])){
               My[v]=u;
               Mx[u]=v;
               return 1;
           }
       }
    return 0;
}
int MaxMatch(){
    int res=0;
    memset(Mx,-1,sizeof(Mx));
    memset(My,-1,sizeof(My));
    while(searchP()){
        memset(vst,0,sizeof(vst));
        for(int i=0;i<Nx;i++)
            if(Mx[i]==-1&&DFS(i)) res++;
    }
    return res;
}
int main(){
    int T;
    scanf("%d",&T);
    int cas=1;
    while(T--){
        int t,n,m;
        scanf("%d%d",&t,&n);
        for(int i=0;i<n;i++){
            scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].t);
        }
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            scanf("%d%d",&um[i].x,&um[i].y);
        }
        cl(g,0);
        Nx=n;Ny=m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)if(distance(p[i],um[j])/p[i].t<=t){
                g[i][j]=1;
            }
        }
        printf("Scenario #%d:\n%d\n\n",cas++,MaxMatch());

    }
    return 0;
}






