#include<iostream>
#include<cstdio>
using namespace std;
int father[5005],num[5005];
int n,m,q;
void makeset(int n){
    for(int j=1;j<=n;j++){
        father[j]=j;
        num[j]=1;
    }
}
int findset(int x){
    return father[x]==x?x:father[x]=findset(father[x]);
}
void Union(int a,int b){
    int x=findset(a);
    int y=findset(b);
    if(x==y)
        return;
    if(num[x]<=num[y]){
        father[x]=y;
        num[y]+=num[x];
    }
    else{
        father[y]=x;
        num[x]+=num[y];
    }
}
int main(){
    int t=0;
    while(scanf("%d%d%d",&n,&m,&q)==3){
        makeset(n);
        int a,b;
        for(int i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            Union(a,b);
        }
        for(int i=0;i<q;i++){
            scanf("%d%d",&a,&b);
            findset(a)==findset(b)?puts("yes"):puts("no");
        }
    }
    return 0;
}