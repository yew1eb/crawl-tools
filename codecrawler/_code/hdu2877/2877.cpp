#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;
 
const int INF=0x3f3f3f3f;
typedef long long ll;
const int M=10005;
const int mod=1e9+7;
const double eps=1e-6;
const double Pi=2*acos(0.0);
 
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
inline int bit(int x){return 1<<x;}
inline double dabs(double x){return x>0?x:(-x);}
inline int abs(int x){return x>0?x:(-x);}
inline int lowbit(int x){return x&(-x);}
 
int t,n,m,tail;
short ma[12][10010];
int dp[10010],color[30],cnt;
struct node{
    int next[30],val;
}trie[180000];
 
void init(){
    tail=1;
    cnt=0;
    memset(trie,-1,sizeof(trie));
}
 
int find(int num){
    for(int i=0;i<cnt;i++)
        if(color[i]==num)
            return i;
    color[cnt++]=num;
    return cnt-1;
}
 
void add(int c,int l){
    int now=0,tmp;
    for(int i=0;i<l;i++){
        scanf("%d",&tmp);
        tmp=find(tmp);
        if(trie[now].next[tmp]==-1)
            trie[now].next[tmp]=tail++;
        now=trie[now].next[tmp];
    }
    if(trie[now].val==-1)
        trie[now].val=c;
    else
        trie[now].val=min(trie[now].val,c);
}
 
void getdp(int x){
    memset(dp,-1,sizeof(dp));
    dp[0]=0;
    for(int i=1;i<=m;i++){
        if(dp[i-1]==-1) continue;
        int tmp=trie[0].next[ma[x][i]],j=i;
        while(tmp!=-1&&j<=m){
            if(trie[tmp].val!=-1){
                if(dp[j]==-1)
                    dp[j]=dp[i-1]+trie[tmp].val;
                else
                    dp[j]=min(dp[j],dp[i-1]+trie[tmp].val);
            }
            tmp=trie[tmp].next[ma[x][++j]];
        }
    }
}
 
int main(){
    int x1,x2,y1,y2,c,l;
    while(~scanf("%d %d",&n,&m)){
        init();
        scanf("%d",&t);
        while(t--){
            scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&c);
            c=find(c);
            for(int i=x1;i<x2;i++)
            for(int j=y1;j<y2;j++)
                ma[i][j+1]=c;
        }
        scanf("%d",&t);
        while(t--){
            scanf("%d",&c);
            scanf("%d",&l);
            add(c,l);
        }
        int ans=0;
        bool jud=0;
        for(int i=0;i<n;i++){
            getdp(i);
            ans+=dp[m];
            if(dp[m]<0) {
                jud=1;
                break;
            }
        }
        if(jud) puts("impossible");
        else printf("%d\n",ans);
    }
    return 0;
}