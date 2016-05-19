#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
const int maxn=51;
int i,j,k;
int n,m,nm,nm1,nm2,bj;
int a[maxn],wz1[maxn],ans[maxn];
int b[maxn],wz2[maxn],col[maxn];
int line[4][maxn],gs[4];
int cmp(int x,int y){
    return gs[x]>gs[y];
}
int main(){
    int T,q;
    scanf("%d",&T);
    for(int ca=1;ca<=T;++ca){
        printf("Case #%d:\n",ca);
        scanf("%d%d%d",&n,&m,&q);
        for(i=1;i<=q;++i){
            scanf("%d",&a[i]);
        }
        nm=n*m;
        nm1=(nm+1)>>1;
        nm2=nm>>1;
        
        int l1=0,l2=0;
        col[0]=0;
        for(int i=2;i<=m;++i)    col[i]=1-col[i-1];
        for(int i=m+1;i<=nm;++i) col[i]=1-col[i-m];
        for(int i=1;i<=nm;++i){
            if(col[i])wz2[++l2]=i;
            else wz1[++l1]=i;
        }
        
        
        gs[1]=gs[2]=gs[3]=0;
        for(i=1;i<4;++i)b[i]=i;
        for(i=1;i<=q && gs[1]+a[i]<=nm1;++i){
            while(a[i]--)line[1][++gs[1]]=i;
        }
        for(;i<=q && gs[2]+a[i]<=nm1;++i){
            while(a[i]--)line[2][++gs[2]]=i;
        }
        for(;i<=q && gs[3]+a[i]<=nm1;++i){
            while(a[i]--)line[3][++gs[3]]=i;
        }
        
        if(i<=q){
            puts("NO");
            continue;
        }
        puts("YES");
        sort(b+1,b+4,cmp);
        for(i=1;i<=nm1-gs[b[1]];++i){
            ans[wz1[i]]=line[b[3]][i];
        }
        k=i;
        for(j=1;j<=gs[b[1]];++j,++i){
            ans[wz1[i]]=line[b[1]][j];
        }
        for(i=nm2;i>gs[b[2]];--i,++k){
            ans[wz2[i]]=line[b[3]][k];
        }
        for(;i>0;--i){
            ans[wz2[i]]=line[b[2]][i];
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){                
                if(j)printf(" ");
                printf("%d",ans[i*m+1+j]);
            }
            puts("");
        }
    }
//    system("pause");
    return 0;
}
