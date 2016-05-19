#include <cstdio>
#include <map>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll __int64
int s1[35], s2[35];
int seq1[35], seq2[35], n;
struct MAT1
{
    int a[35][35];
} mt1;
struct MAT2
{
    int b[35];
} mt2, x, y;
MAT2 mul(MAT1 r1,MAT2 r2)
{
    int i, j;
    MAT2 tp;
    memset(tp.b,0,sizeof(tp.b));
    for(i=0;i<=n;i++)
        for(j=0;j<=n;j++) tp.b[i]+=r1.a[i][j]*r2.b[j];
    for(i=0;i<=n;i++) tp.b[i]%=2;
    return tp;
}
MAT1 fast_pow(MAT1 r1,int cnt)
{
    MAT1 ret, tp;
    int i, j, k;
    memset(ret.a,0,sizeof(ret.a));
    for(i=0;i<=n;i++) ret.a[i][i]=1;
    while(cnt){
        if(cnt&1){
            memset(tp.a,0,sizeof(tp.a));
            for(i=0;i<=n;i++){
                for(j=0;j<=n;j++){
                    for(k=0;k<=n;k++){
                        tp.a[i][j]+=ret.a[i][k]*mt1.a[k][j];
                    }
                    tp.a[i][j]%=2;
                }
            }
            ret=tp;
        }
        memset(tp.a,0,sizeof(tp.a));
        for(i=0;i<=n;i++){
            for(j=0;j<=n;j++){
                for(k=0;k<=n;k++){
                    tp.a[i][j]+=mt1.a[i][k]*mt1.a[k][j];
                }
                tp.a[i][j]%=2;
            }
        }
        mt1=tp;
        cnt>>=1;
    }
    return ret;
}
map<int,int> mp;
int main()
{
    int i, j, S1, S2, m;
    ll tot, sta, ans;
    while(~scanf("%d%d%d",&n,&S1,&S2)){
        mp.clear();
        for(i=1;i<=S1;i++) scanf("%d",&s1[i]);
        for(i=1;i<=S2;i++) scanf("%d",&s2[i]);
        for(i=1;i<=n;i++) scanf("%d",&seq1[i]);
        for(i=1;i<=n;i++) scanf("%d",&seq2[i]);
        for(i=1;i<=n;i++) {
            if(seq1[i]!=seq2[i]) break;
        }
        if(i==n+1) {
            puts("0");
            continue;
        }
        memset(mt1.a,0,sizeof(mt1.a));
        for(i=0;i<n-1;i++) mt1.a[i][i+1]=1;
        for(i=1;i<=S1;i++) mt1.a[n-1][s1[i]-1]=1;
        for(i=1;i<=S2;i++) mt1.a[s2[i]-1][n]=1;
        mt1.a[n][n]=1;
        for(i=1;i<=n;i++) x.b[i-1]=seq1[i];
        for(i=1;i<=n;i++) y.b[i-1]=seq2[i];
        x.b[n]=1;
        y.b[n]=1;
        tot=1LL<<n;
        m=ceil(sqrt((double)tot))+1;
        sta=0;
        for(i=0;i<n;i++) {
            sta*=2;
            sta+=y.b[i];
        }
        mp[sta]=0;
        for(i=1;i<m;i++){
            y=mul(mt1,y);
            sta=0;
            for(j=0;j<n;j++) sta=sta*2+y.b[j];
            mp[sta]=i;
        }

        mt1=fast_pow(mt1,m);
        ans=-1;
        for(i=1;i<=m;i++){
            x=mul(mt1,x);
            sta=0;
            for(j=0;j<n;j++) sta=sta*2+x.b[j];
            if(mp.find(sta)!=mp.end()){
                ans=(ll)i*m-mp[sta];
                break;
            }
        }
        if(ans==-1){
            puts("poor sisyphus");
            continue;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
