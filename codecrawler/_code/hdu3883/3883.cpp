#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 128
int f[N][N],g[N][N][N];
int main() {
 register int n,m,i,j,k,v,maxf;
 while (~scanf("%d%d",&n,&m)) {
 memset(f,0xf0,sizeof(f));
 memset(g,0xf0,sizeof(g));
 int ans=-0x7fffffff;
 for (i=1;i<=n;i++)
 for (j=1;j<=m;j++) {
 scanf("%d",&f[i][j]);
 v=abs(f[i][j]);
 maxf=max(g[i-1][j][v+1],g[i][j-1][v+1]);
 if (maxf!=0xf0f0f0f0L) f[i][j]-=maxf;
 if (ans<f[i][j]) ans=f[i][j];
 for (k=100;k>=0;k--) {
 g[i][j][k]=max(g[i-1][j][k],g[i][j-1][k]);
 g[i][j][k]=max(g[i][j][k],g[i][j][k+1]);
 if (k==v&&g[i][j][k]<f[i][j]) g[i][j][k]=f[i][j];
 }
 }
 printf("%d\n",ans);
 }
 return 0;
}