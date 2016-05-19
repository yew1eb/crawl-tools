#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

typedef long long llo;
typedef double llb;

#define con continue
#define vec vector
#define str string
#define pt puts("");
#define pb push_back
#define lowbit(x) (x&(-x))
#define for0(a,b) for(a=0;a<b;++a)
#define for1(a,b) for(a=1;a<=b;++a)
#define foru(i,a,b) for(i=a;i<=b;++i)
#define ford(i,a,b) for(i=a;i>=b;--i)

const long maxn=550,maxm=2004000;

long i,j,k,l,n,m;
long sx,sy,tx,ty;
long x,y,x2,y2,t,h;
long tt,ca,tmp;
long ntime,cost;
long d[maxn][maxn];
long e2[maxn][maxn],e[maxn][maxn];
long ec[maxn],cant[maxn][maxn][10];
long fx[10][2]={{0,1},{1,0},{0,-1},{-1,0}};


char c[maxn];


struct node{
    long x,y;
}f[maxm];

long jl(long x){
    return d[f[x].x][f[x].y];
}
void huan(long x,long y){
    node tmp;
    tmp=f[x];
    f[x]=f[y];
    f[y]=tmp;
    e2[f[x].x][f[x].y]=x;
    e2[f[y].x][f[y].y]=y;
    return;
}
void up(long x){
    if(x<2)return;
    long tmp=(x>>1);
    if(jl(tmp)>jl(x)){
        huan(tmp,x);
        up(tmp);
    }
    return;
}
void down(long x){
    long tmp=(x<<1);
    if(tmp>t)return;
    if(tmp<t && jl(tmp+1)<jl(tmp))++tmp;
    if(jl(tmp)<jl(x)){
        huan(x,tmp);
        down(tmp);
    }
    return;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("i.in","r",stdin);
    freopen("i.out","w",stdout);
    #endif    
    scanf("%ld",&tt);
    ec['E']=1;
    ec['S']=2;
    ec['W']=3;
    ec['N']=4;
    for1(ca,tt){
        printf("Case #%ld: ",ca);
        scanf("%ld\n",&n);
        for1(i,n) for1(j,n) for0(k,4)cant[i][j][k]=0;
        for1(i,n){
            gets(c+1);
            for1(j,n){
                d[i][j]=-1;
                e[i][j]=(c[j]=='#');
                if(c[j]=='M'){
                    sx=i;
                    sy=j;
                }else if(c[j]=='T'){
                    tx=i;
                    ty=j;
                }else if(ec[c[j]]){
                    tmp=ec[c[j]]-1;
                    for0(k,4){
                        x2=i;
                        y2=j;
                        for1(l,3){
                            if(x2>0 && x2<=n && y2>0 && y2<=n)
                                cant[x2][y2][k]=1;
                            x2=i+fx[(k+tmp)&3][0];
                            y2=j+fx[(k+tmp)&3][1];
                        }
                    }
                }
            }
        }
        d[sx][sy]=0;
        f[t=1].x=sx;
        f[1].y=sy;
        e2[sx][sy]=1;
        while(t){
            x=f[1].x;
            y=f[1].y;
            ntime=d[x][y];
            f[1]=f[t--];
            if(t)down(1);
            for0(i,4){
                x2=x+fx[i][0];
                y2=y+fx[i][1];
                if(x2>n || y2>n || x2<1 || y2<1 || e[x2][y2])continue;
                if(!cant[x][y][ntime&3] && !cant[x2][y2][ntime&3])cost=1;
                else if(!cant[x][y][(ntime+1)&3] && !cant[x2][y2][(ntime+1)&3])cost=2;
                else cost=3;
                if(d[x2][y2]<0){
                    d[x2][y2]=ntime+cost;
                    f[++t].x=x2;
                    f[t].y=y2;
                    e2[x2][y2]=t;
                    up(t);
                }else{
                    if(d[x2][y2]>ntime+cost){
                        d[x2][y2]=ntime+cost;
                        up(e2[x2][y2]);
                    }
                }
            }
        }
    /*    for1(i,n){
            for1(j,n)printf("%ld ",d[i][j]);
            pt;
        }*/
        printf("%ld\n",d[tx][ty]);
    }
    return 0;
}