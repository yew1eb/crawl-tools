#include<cstdio>
#include<cstring>
#define N 1010
using namespace std;
int c1,c2;
int f1[N],f2[N];
int n,m,k;
void init(){
    int i;
    c1=c2=0;
    for(i=1;i<=n;i++)
        f1[i]=f2[i]=i;
}
int find(int u,int *f){
    if(f[u]==u)return u;
    return f[u]=find(f[u],f);
}
void Union(int u,int v,int &c,int *f){
    int pu=find(u,f);
    int pv=find(v,f);
    if(pu!=pv){
        f[pu]=pv;
        c++;
    }
}
int main(){
    char s[10];
    int u,v;
    int i;
    while(scanf("%d %d %d",&n,&m,&k)){
        if(n==0 && m==0 && k==0)break;
        init();
        for(i=1;i<=m;i++){
            scanf("%s %d %d",&s,&u,&v);
            if(s[0]=='R')
                Union(u,v,c1,f1);
            else
                Union(u,v,c2,f2);
        }
        if(n-1-c1<=k && c2>=k) printf("1\n");
        else printf("0\n");
    }
}
