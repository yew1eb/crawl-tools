#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#define N 10005
#define LL long long
#define inf 1<<29
#define eps 1e-7
using namespace std;
vector<int>v[1005];
int n,sg[1005];
int get_sg(int n){
    if(sg[n]!=-1)
       return sg[n];
    if(v[n].size()==0)
       return 0;
    int vis[1005];
    memset(vis,0,sizeof(vis));
    for(int i=0;i<v[n].size();i++){
        sg[v[n][i]]=get_sg(v[n][i]);
        vis[sg[v[n][i]]]=1;
    }
    for(int i=0;;i++)
        if(vis[i]==0)
            return i;
}
int main(){
    while(scanf("%d",&n)!=EOF){
        memset(sg,-1,sizeof(sg));
        for(int i=0;i<n;i++){
            v[i].clear();
            int k,u;
            scanf("%d",&k);
            while(k--){
                scanf("%d",&u);
                v[i].push_back(u);
            }
        }
        int q,k,u;
        while(scanf("%d",&k)&&k){
            int ret=0;
            while(k--){
                scanf("%d",&u);
                if(sg[u]==-1)
                    sg[u]=get_sg(u);
                ret^=sg[u];
            }
            if(ret==0)
                puts("LOSE");
            else
                puts("WIN");
        }
    }
    return 0;
}
