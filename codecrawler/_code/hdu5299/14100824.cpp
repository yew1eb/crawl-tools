#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int maxn=20020;
struct node{
    int x,y,r;
}a[maxn];
int T,n;
int ans[maxn],fa[maxn];
int cmp(node a,node b){
    return a.r>b.r;
}
int pf(int x){return x*x;}
int pd(int x,int y){
    return ( pf(a[y].x-a[x].x)+pf(a[y].y-a[x].y) <pf(a[y].r) );
}
int main(){
    scanf("%ld",&T);
    while(T--){
        scanf("%ld",&n);
        for(int i=1;i<=n;++i){
            scanf("%ld%ld%ld",&a[i].x,&a[i].y,&a[i].r);
        }
        sort(a+1,a+n+1,cmp);
        ans[0]=0;
        for(int i=1;i<=n;){
            int k=i;
            for(;i<=n && a[i].r==a[k].r;++i){
                ans[i]=fa[i]=0;
                for(int j=k-1;j;--j){
                    if(pd(i,j)){
                        fa[i]=j;
                        break;
                    }
                }
            }
        }
        for(int i=n;i;--i){
            ans[fa[i]]^=++ans[i];
        }
    //    printf("%ld\n",ans[0]);
        puts(ans[0]?"Alice":"Bob");
    }    
    return 0;    
}