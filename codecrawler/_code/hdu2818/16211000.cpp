#include<cstdio>

const int N = 30005;
int f[N];
long long rank[N],num[N];

inline void init(){
    for(int i=0; i<N; ++i)
        f[i]=i,rank[i]=0,num[i]=1;
}
int find(int x){
    if(x==f[x]) return f[x];
    int fa = f[x];
    f[x] = find(f[x]);
    if(rank[fa]!=0)
        rank[x] += rank[fa];
    return f[x];
}

inline void Union(int x,int y){
    int a=find(x), b=find(y);
    if(a==b) return ;
    rank[a] = num[b];
    f[a] = b;
    num[b] += num[a];
    num[a] = 0;
}

int main(){
    int t, x, y;
    char cmd[3];
    scanf("%d",&t);
    init();
    for(int i=0; i<t; ++i){
        scanf("%s",cmd);
        if(cmd[0]=='M'){
            scanf("%d%d",&x,&y);
            Union(x,y);
        }
        else{
            scanf("%d",&x);
            find(x);
            printf("%lld\n", rank[x]);
        }
    }
    return 0;
}