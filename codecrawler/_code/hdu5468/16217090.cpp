#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
#define maxn 100007
using namespace std;
vector<int> pri[maxn],head[maxn],ty[maxn];
int num[maxn];


void init(){
    memset(num,0,sizeof(num));
    for(int i = 0;i < maxn; i++)
        pri[i].clear(),ty[i].clear();
    for(int i = 2;i < maxn ;i++){
        if(num[i] == 0){
            for(int j = i;j < maxn; j+=i){
                num[j] = 1;
                pri[j].push_back(i);
            }
        }
    }
    vector<int> x;
    for(int i = 2;i < maxn; i++){
        x.clear();
        for(int j = 0;j < pri[i].size(); j++){
            x.push_back(pri[i][j]);
        }
        pri[i].clear();
        int n = x.size();
        for(int j = 1;j < (1<<n); j++){
            int y = 1,f=0;
            for(int k = 0;k < n; k++){
                if(j&(1<<k)){
                    y *= x[k];
                    f++;
                }
            }
            pri[i].push_back(y);
            if(f&1) ty[i].push_back(-1);
            else ty[i].push_back(1);
        }
    }
}
int val[maxn],ans[maxn];
int ch[maxn][70];
int dfs(int u,int f){
    int su = 0 ;
    int va = val[u];
    for(int i = 0;i < pri[va].size();i++)
        ch[u][i] = num[pri[va][i]];
    for(int i = 0;i < head[u].size(); i++){
        int v = head[u][i];
        if(v == f) continue;
        su += dfs(v,u);
    }
    ans[u] = su;
    for(int i = 0;i < pri[va].size(); i++){
        ans[u] += num[pri[va][i]]-ch[u][i];
    }
    for(int i = 0;i < pri[va].size(); i++){
        num[pri[va][i]]+=ty[va][i];
    }
    if(va == 1) ans[u]++;
    return su+1;
}


int main(){
    int tt=1,n,u,v;
    init();
    while(scanf("%d",&n)!=EOF){
        for(int i = 1;i <= n; i++)
            head[i].clear();
        for(int i = 1; i < n ;i++){
            scanf("%d%d",&u,&v);
            head[u].push_back(v);
            head[v].push_back(u);
        }
        memset(num,0,sizeof(num));
        for(int i = 1;i <= n; i++)
            scanf("%d",&val[i]);
        dfs(1,0);
        printf("Case #%d:",tt++);
        for(int i = 1;i <= n; i++)
            printf(" %d",ans[i]);
        printf("\n");
    }
    return 0;
}






