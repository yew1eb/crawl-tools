/*hdu 5278 YJC plays automaton
  æè·¯ï¼
  å»ºç«ååå¾ï¼åèèäºåç»ï¼ä½¿ç¨bfsæç®çç¶æè½å°è¾¾çäºåç»è®°ä¸æ¥ã
  æåè®¡ç®ç­æ¡ï¼å¥½é¾è¡¨è¿°ã
 */
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define PII pair<int,int>
#define LL __int64
#define MP make_pair
#define PB push_back
#define X first
#define Y second
const int MOD=998244353;
const int N=1005;
const int M=10;
int tran[N][M];
LL two[N];
void predo(){
    two[0]=1;
    for(int i=1;i<N;++i)
        two[i]=two[i-1]*2%MOD;
}

vector<PII> e[N][N];
PII que[N*N];
int front,tail;

int fa[N],num[N];
void init_bcj(){
    for(int i=0;i<N;++i){
        fa[i]=i;
        num[i]=1;
    }
}
int getFa(int x){
    if(x!=fa[x]) return fa[x]=getFa(fa[x]);
    return x;
}
void bin(int x,int y){
    int fx=getFa(x);
    int fy=getFa(y);
    if(fx==fy) return ;
    fa[fy]=fx;
    num[fx]+=num[fy];
    num[fy]=0;
}


int mark=0;
int used[N][N];
void gao(int n,int m){
    ++mark;
    for(int i=0;i<=n;++i)
        for(int j=0;j<=n;++j)
            e[i][j].clear();

    for(int x1=0;x1<=n;++x1){
        for(int y1=x1+1;y1<=n;++y1){
            for(int i=0;i<m;++i){
                int x2=tran[x1][i];
                int y2=tran[y1][i];
                if(x2>y2) swap(x2,y2);
                e[x2][y2].PB(MP(x1,y1));
            }
        }
    }
    front=tail=0;
    for(int i=1;i<=n;++i){
        que[tail++]=MP(0,i);
        used[0][i]=mark;
    }
    while(front<tail){
        PII now=que[front++];
        for(int i=0;i<e[now.X][now.Y].size();++i){
            int tmpx=e[now.X][now.Y][i].X;
            int tmpy=e[now.X][now.Y][i].Y;
            if(used[tmpx][tmpy]==mark) continue;
            que[tail++]=MP(tmpx,tmpy);
            used[tmpx][tmpy]=mark;
        }
    }
    
    init_bcj();
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            if(used[i][j]!=mark) bin(i,j);
        }
    }

    LL ans=(two[n]-1+MOD)%MOD;
    for(int i=1;i<=n;++i){
        if(num[i]){
            //cout<<i<<' '<<num[i]<<endl;
            ans=(ans-(two[num[i]]-1)+MOD)%MOD;
        }
    }
    cout<<ans<<endl;

}
int main(){
    predo();
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=1;i<=n;++i)
            for(int j=0;j<m;++j)
                scanf("%d",&tran[i][j]);
        gao(n,m);
    }
    return 0;
}
