#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn =100000+5;
const int maxm=maxn+maxn;
int v[maxm],info[maxn],Prev[maxm],Q[maxn],dep[maxn];
int belong[maxn],head[maxn];
long long size[maxn];
bool vis[maxn];
int cnt=0,N,nedge=0;
int weight[maxn];
inline void insert(int x,int y){
    ++nedge;
    v[nedge]=y;Prev[nedge]=info[x];info[x]=nedge;
}
void split(){
    int l,r;
    memset(dep,-1,sizeof(dep));
    l=0;
    dep[Q[r=1]=1]=0;
    while(l<r){
        int x=Q[++l];
        vis[x]=false;
        for(int y=info[x];y!=-1;y=Prev[y]){
            if(dep[v[y]]==-1){
                dep[Q[++r]=v[y]]=dep[x]+1;
            }
        }
    }
    for(int i=N;i;i--){
        int x=Q[i],p=-1;
        size[x]=weight[x];
        for(int y=info[x];y!=-1;y=Prev[y]){
            if(vis[v[y]]){
                if(p==-1||size[v[y]]>size[p])
                    p=v[y];
            }
        }
        if(p==-1){
            ++cnt;
            belong[head[cnt]=x]=cnt;
        }
        else {
            size[x]+=size[p];
            belong[x]=belong[p];
            head[belong[x]]=x;
        }
        vis[x]=true;
    }

}
bool cmp(int a,int b){
    return size[head[a]]>size[head[b]];
}
int ans[maxn];
long long get_ans(int k){
    long long ret=0;
    for(int i=1;i<=cnt;i++) ans[i]=i;
    sort(ans+1,ans+cnt+1,cmp);
    for(int i=1;i<=min(cnt,k);i++){
        ret+=size[head[ans[i]]];
    }
    return ret;
}
int main(){
    int k,a,b,T,cas=0;
    //freopen("data.in","r",stdin);
    scanf("%d",&T);
    while(T--){
        printf("Case #%d: ",++cas);
        scanf("%d%d",&N,&k);
        memset(info,-1,sizeof(info));
        cnt=0;nedge=0;
        for(int i=1;i<=N;i++){
            scanf("%d",weight+i);
        }
        for(int i=1;i<N;i++){
            scanf("%d%d",&a,&b);
            insert(a,b);
        }
        split();
        cout<<get_ans(k)<<endl;
    }
    return 0;
}