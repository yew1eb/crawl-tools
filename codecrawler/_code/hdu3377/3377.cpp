#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stack>
#define maxn 15
#define maxk 3000000
#define maxm 1000
using namespace std;
int f[2][maxk];
int ans;
int hash[maxm];
int a[2][maxk];
int pre[2][maxk];
int map[maxn][maxn];
int n,m,e,tot,num;
int fopp(int k,int b,int x,int fx)
{
    stack <int> st;
    while (!st.empty()) st.pop();
    for (int i=k+b;;i+=b){
        int h=fx>>i*2-2&3;
        if (h==x){
           if(st.empty()) return i;
           else st.pop();
        }
        else if(h) st.push(h);
    }
}
    
void put(int x,int v)
{
     int h=x%997;
     int p=hash[h];
     while (p>0){
           if (a[e][p]==x) break;
           p=pre[e][p];
     }
     if (p==0){
        num++;
        pre[e][num]=hash[h];hash[h]=num;
        a[e][num]=x;f[e][num]=v;
     }
     else f[e][p]=max(f[e][p],v);
}


void dp(int i,int j,int x,int v)
{
     int left=x>>2*j-2&3;
     int up=x>>2*j&3;
     //printf("%d %d %d %d\n",i,j,x,v);
     //printf("%d %d\n",left,up);
     x-=(left<<2*j-2)+(up<<2*j);
     if (left+up==0){
        if (i==1&&j==1) {put(x+(1<<2*j-2),v);put(x+(2<<2*j),v);return;}
        if (i<n&&j<m) put(x+(1<<2*j-2)+(2<<2*j),v);
        put(x,v-map[i][j]);
     }
     else if(left==0||up==0){
          int temp=left+up;
          if (i==n&&j==m) ans=max(ans,v);
          if (i<n) put(x+(temp<<2*j-2),v);
          if (j<m) put(x+(temp<<2*j),v);
     }
     else if(left+up==3){
          if (left==2) put(x,v);
     } 
     else if(left+up==2){
          int t=fopp(j+1,1,2,x);
          put(x-(1<<t*2-2),v);
     }
     else if(left+up==4){
          int t=fopp(j,-1,1,x);
          put(x+(1<<t*2-2),v);
     }
}
int main(){
    int cas=0;
    while (scanf("%d%d",&n,&m)==2){
          int i,j,k,code;cas++;
          for (i=1;i<=n;i++)
              for (j=1;j<=m;j++)
                  scanf("%d",&map[i][j]);
          if (n==1&&m==1) {printf("Case %d: %d\n",cas,map[1][1]);continue;}
          memset(f,0,sizeof(f));
          memset(hash,0,sizeof(hash));
          e=0;num=0;
          put(0,0);
          ans=-100000000;
          for (i=1;i<=n;i++)
              for (j=1;j<=m;j++){
                  memset(hash,0,sizeof(hash));
                  e=1-e;tot=num;num=0;
                  for (k=1;k<=tot;k++){
                      code=a[1-e][k];
                      if (j==1)  code=code<<2;
                      dp(i,j,code,f[1-e][k]+map[i][j]);
                  }
              }
          printf("Case %d: %d\n",cas,ans);
    }
    return 0;
}