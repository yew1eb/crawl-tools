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
const int maxn=1005;
const int inf=999999;

char s[100005];
vector<int> G[maxn];
int Nx,limit,cnt[maxn];//cntæ°ç»æ¯è®°å½XéåXiç¹ ç®åå·²ç»å¹éYéåéçç¹çä¸ªæ°
int matching[maxn][505];//è¿ä¸ªè¡¨ç¤ºXéåçXiç¹ä¸Yéåçcntä¸ªç¹ç¸è¿æ¥
bool vis[maxn];
bool dfs(int u){//å¤éå¹éåäºåå¾çä¸è¬å¹éå·®ä¸å¤ï¼è¿æ¯ä¸¤ä¸ªæ¡ä»¶
    int N=G[u].size();
    for(int i=0;i<N;i++){
        int v=G[u][i];
        if(vis[v])continue;
        vis[v]=true;
        if(cnt[v]<limit){
            matching[v][cnt[v]++]=u;//æ²¡æè¾¾å°ä¸éï¼å¹é
            return true;
        }else {
            for(int i=0;i<cnt[v];i++){//è¾¾å°ä¸éï¼ç»§ç»­æ¥çæ¯å¦è¿è½æ¾å°å¢å¹¿è·¯
                if(dfs(matching[v][i])){
                    matching[v][i]=u;
                    return true;
                }
            }
        }
    }
    return false;
}
bool hungar(){
    cl(cnt,0);
    for(int i=0;i<Nx;i++){
        cl(vis,false);
        if(!dfs(i))return false;
    }
    return true;
}
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)&&(n||m)){
        getchar();
        for(int i=0;i<n;i++){
            gets(s);
            int len=strlen(s);
            for(int j=0;j<len;j++){
                if(s[j]>='0'&&s[j]<='9'){
                    int num=0;
                    while(s[j]>='0'&&s[j]<='9'){
                        num=num*10+s[j]-'0';
                        j++;
                    }
                    G[i].pb(num);
                }
            }
        }
        Nx=n;
        int l=0,r=n;
        while(l<r){///äºåç­æ¡
           // printf("%d  %d \n",l,r);
            limit=(l+r)/2;
            if(hungar()){
                r=limit;
            }
            else {
                l=limit+1;
            }
        }
        printf("%d\n",r);
        for(int i=0;i<maxn;i++)G[i].clear();
    }
    return 0;
}