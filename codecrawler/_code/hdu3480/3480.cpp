#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define N 10003
#define M 5002
using namespace std;
int f[N][M];
int s[N][M];
int a[N];
int main(){
    int T,n,m;
    scanf("%d",&T);
    for (int cas=1;cas<=T;cas++){
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        for (int i=1;i<=n;i++){
            f[i][1]=(a[i]-a[1])*(a[i]-a[1]);
            s[i][1]=1;
        }
        for (int i=2;i<=m;i++){
            s[n+1][i]=n-1;
            for (int j=n;j>=i;j--){
                f[j][i]=-1;
                for (int k=s[j][i-1];k<=s[j+1][i];k++){
                    int tp=f[k][i-1]+(a[j]-a[k+1])*(a[j]-a[k+1]);
                    if (f[j][i]==-1||f[j][i]>tp){
                        f[j][i]=tp;
                        s[j][i]=k;
                    }
                    //printf("%d %d %d %d %d\n",i,j,k,f[j][i],s[j][i]);
                }
            }
        }
        printf("Case %d: %d\n",cas,f[n][m]);
    }
    return 0;
}
