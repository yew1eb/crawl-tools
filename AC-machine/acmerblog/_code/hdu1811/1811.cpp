#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int N = 10005;
int n,m,f[N],rank[N],X[2*N],Y[2*N],son[N],t;
char O[2*N];
vector<int>G[N];

void initSet(int n){
    for(int i=0; i<=n; ++i)
        f[i]=i, rank[i]=0; 
    for(int i=0; i<=n; ++i)
        G[i].clear();
    memset(son, 0, sizeof(son));
}
int find(int x){
    int i,j=x;
    while(j!=f[j]) j=f[j];
    while(x!=j){
        i=f[x], f[x]=j, x=i;
    }
    return j;
}
bool Union(int x,int y){
    int a=find(x), b=find(y);
    if(a==b){
        return false;
    }
    if(rank[a]>rank[b])
        f[b]=a;
    else{
        if(rank[a]==rank[b])
            ++rank[b];
        f[a]=b;
    }
    return true;
}


int main(){
    int u,v;
    char ch;
    while(~scanf("%d%d",&n,&m)){
        initSet(n);
        int num=n;
        for(int i=0; i<m; ++i){
            scanf("%d %c %d",&X[i],&O[i],&Y[i]);
            if(O[i]=='='){
                if(Union(X[i], Y[i]))
                    --num;
            }
        }
        for(int i=0; i<m; ++i)if(O[i]!='='){
            int x=find(X[i]), y=find(Y[i]);
            if(O[i]=='>'){
                G[x].push_back(y);
                son[y]++;
            }
            else{
                G[y].push_back(x);
                son[x]++;
            }
        }
        queue<int>q;
        for(int i=0; i<n; ++i){
            if(son[i]==0&&i==find(i))
                q.push(i);
        }
        int stan=0;//是否唯一
        while(!q.empty()){
            if(q.size()>1) stan=1;
            int t=q.front();
            q.pop();
            --num;
            for(int v=0; v<G[t].size(); ++v){
                if(--son[G[t][v]]==0)
                    q.push(G[t][v]);
            }
        }
        if(num>0)
            printf("CONFLICT\n");
        else if(stan)
            printf("UNCERTAIN\n");
        else 
            printf("OK\n");
    }
    return 0;
}