#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define N 60
#define ll long long
using namespace std;
ll a[N][N];
ll b[N][N];
ll c[N][N];
ll tp[N][N];
//void print(ll pt[N][N],int nb){
//    for (int i=0;i<=nb+1;i++){
//        for (int j=0;j<=nb+1;j++)
//            printf("%I64d ",pt[i][j]);
//        printf("\n");
//    }
//}
int main(){
    int n,x;
    ll MOD;
    while (scanf("%d%d",&n,&x)==2){
        cin>>MOD;
        if (n<0&&x<0&&MOD<0) break;
        for (int i=0;i<=x;i++)
            c[i][i]=c[i][0]=1ll;
        for (int i=2;i<=x;i++)
            for (int j=1;j<i;j++)
                c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for (int i=0;i<=x;i++)
            for (int j=0;j<=i;j++)
                a[j][i]=c[i][j]*x%MOD;
        for (int i=0;i<=x;i++)
            a[i][x+1]=a[i][x];
        a[x+1][x+1]=1ll;
        for (int i=0;i<=x+1;i++)
            b[0][i]=x;
        n=n-1;
        while (n>0){
            if (n%2){
                memset(tp,0,sizeof(tp));
                for (int i=0;i<=x+1;i++)
                    for (int j=0;j<=x+1;j++)
                        for (int k=0;k<=x+1;k++)
                            tp[i][j]=(tp[i][j]+b[i][k]*a[k][j])%MOD;
                memcpy(b,tp,sizeof(tp));
            }
            n=n/2;
            memset(tp,0,sizeof(tp));
            for (int i=0;i<=x+1;i++)
                for (int j=0;j<=x+1;j++)
                    for (int k=0;k<=x+1;k++)
                        tp[i][j]=(tp[i][j]+a[i][k]*a[k][j])%MOD;
            memcpy(a,tp,sizeof(tp));
        }
        cout<<b[0][x+1]<<endl;
    }
    return 0;
}
