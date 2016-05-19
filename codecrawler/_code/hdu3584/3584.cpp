#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define maxn 101
#define lowbit(x) ((x)&(-x))
int c[maxn][maxn][maxn];
int n,m;

void update(int x,int y,int z) {
 for(int i=x;i<=n;i+=lowbit(i))
 for(int j=y;j<=n;j+=lowbit(j))
 for(int k=z;k<=n;k+=lowbit(k))
 c[i][j][k]^=1;
}

int sum(int x,int y,int z) {
 int res=0;
 for(int i=x;i;i-=lowbit(i))
 for(int j=y;j;j-=lowbit(j))
 for(int k=z;k;k-=lowbit(k))
 res^=c[i][j][k];
 return res;
}

int main() {
 while(~scanf("%d%d",&n,&m)) {
 int com;
 memset(c,0,sizeof(c));
 while(m--) {
 scanf("%d",&com);
 if(com) {
 int x,y,z,x1,y1,z1;
 scanf("%d%d%d%d%d%d",&x,&y,&z,&x1,&y1,&z1);
 update(x,y,z);
 update(x,y,z1+1);
 update(x,y1+1,z);
 update(x1+1,y,z);
 update(x1+1,y1+1,z);
 update(x1+1,y,z1+1);
 update(x,y1+1,z1+1);
 update(x1+1,y1+1,z1+1);
 }
 else {
 int x,y,z;
 scanf("%d%d%d",&x,&y,&z);
 printf("%d\n",sum(x,y,z));
 }
 }
 }
 return 0;
}