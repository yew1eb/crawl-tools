#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
const short maxn=26;
short n,m,nm,nm1,nm2,bj;
short a[maxn],wz1[maxn],ans[maxn];
short b[maxn],wz2[maxn],col[maxn];
short line[4][maxn],gs[4];
short cmp(int x,int y){
    return gs[x]>gs[y];
}

template<class T>
inline bool scan_d(T &ret){
    char c; ret = 0;
    while((c=getchar())<'0'||c>'9');
    while(c>='0'&&c<='9') ret = ret*10 + (c-'0'),c=getchar();
    return 0;
}
int main(){
    int T;
    short q, i, j, k;
    scan_d(T);
    for(int ca=1;ca<=T;++ca){
        printf("Case #%d:\n",ca);
        scan_d(n); scan_d(m); scan_d(q);
        for(i=1;i<=q;++i){
            scan_d(a[i]);
        }
        nm=n*m;
        nm1=(nm+1)>>1;
        nm2=nm>>1;
        int l1=0,l2=0;
        col[1]=0;
        for(i=2;i<=m;++i)    col[i]=1-col[i-1];
        for(i=m+1;i<=nm;++i) col[i]=1-col[i-m];
        for(i=1;i<=nm;++i){
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
        for(i=0;i<n;++i){
            for(j=0;j<m;++j){
                if(j)printf(" ");
                printf("%d",ans[i*m+1+j]);
            }
            puts("");
        }
    }
    return 0;
}