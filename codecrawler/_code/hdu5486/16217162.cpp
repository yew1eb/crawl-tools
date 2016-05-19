#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<stdlib.h>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
#define rd(x) scanf("%d",&x)
#define rdd(x,y) scanf("%d%d",&x,&y)
#define rddd(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define rdddd(x,y,z,w) scanf("%d%d%d%d",&x,&y,&z,&w)
#define rds(s) scanf("%s",s)
#define rep(i,n) for(int i=0;i<n;i++)
#define LL long long
const int N = 1e6+10;
const int M=2000;
const int inf=0x3f3f3f3f;
const double eps=1e-8;
int MOD=1e9+7;
int cas=1;
int n,m,k,q;
int a[N];
int b[N];
int f[N*2];
int c[N];
int get(int x,int *a,int len){
    return lower_bound(a+1,a+len+1,x)-a;
}
int find(int x){
    if(f[x]==x) return x;
    return f[x]=find(f[x]);
}
int unit(int u,int v){
    int u1=find(u),v1=find(v);
    if(u1!=v1){
        f[u1]=v1;
    }
}

int res[N][2];
int main()
{
#ifndef ONLINE_JUDGE
  freopen("aaa","r",stdin);
#endif
    int T;
    rd(T);
    while(T--){
        rd(n);
        for(int i=1;i<=n;i++) rdd(a[i],b[i]);
        for(int i=1;i<=n;i++) c[i]=a[i];
        sort(c+1,c+n+1);
        int lena=1;
        for(int i=2;i<=n;i++) if(c[i]!=c[i-1]) c[++lena]=c[i];
        for(int i=1;i<=n;i++) a[i]=get(a[i],c,lena);

        for(int i=1;i<=n;i++) c[i]=b[i];
        sort(c+1,c+n+1);
        int lenb=1;
        for(int i=2;i<=n;i++) if(c[i]!=c[i-1]) c[++lenb]=c[i];
        for(int i=1;i<=n;i++) b[i]=get(b[i],c,lenb);
        memset(res,0,sizeof res);
        for(int i=1;i<=lena+lenb;i++) f[i]=i;
        for(int i=1;i<=n;i++) unit(a[i],b[i]+lena);

        for(int i=1;i<=lena;i++){
            int u=find(i);
            res[u][0]++;
        }
        for(int i=1;i<=lenb;i++){
            int u=find(i+lena);
            res[u][1]++;
        }
        int one,mer,sp;
        one=mer=sp=0;
        for(int i=1;i<=lena+lenb;i++)
        {
            int u=res[i][0];
            int v=res[i][1];
            if(u==1 && v==1) one++;
            else if(u>1 && v==1) mer++;
            else if(u==1 && v>1) sp++;
        }
        printf("Case #%d: %d %d %d\n",cas++,sp,mer,one);
    }
    return 0;
}
