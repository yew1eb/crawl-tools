#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 15;
#define mod 9973
int res[maxn][maxn];
int n;
void mul(int a[][15],int b[][15],int c[][15]){
    int temp[15][15];  memset(temp,0,sizeof(temp));
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        for(int k=0;k<n;k++){
           temp[i][j]=(temp[i][j]+ a[i][k]*b[k][j] )%mod;
        }
    memcpy(c,temp,sizeof(temp));
}
void pow(int a[][15],int k){
     while(k){
         if(k&1){
             mul(res,a,res);
         }
         mul(a,a,a);
         k>>=1;
     //    printf("%d\n",k);
     }
}
int main(){
    int T,k;
    int a[maxn][maxn];
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++)  for(int j=0;j<n;j++)  res[i][j]=(i==j);
        for(int i=0;i<n;i++)  for(int j=0;j<n;j++)  scanf("%d",&a[i][j]);
        pow(a,k);
        int ans=0;
        for(int i=0;i<n;i++) ans+=res[i][i];
        printf("%d\n",ans%mod);
    }
    return 0;
}
