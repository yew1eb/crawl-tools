#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAXN = 505;
const int MAXV = 1000050;


int old[MAXN][MAXN],ans[MAXN][MAXN];
int C[MAXV],Max;


void update(int p,int val)
{
 while(p<=Max) {
 C[p]+=val;
 p+=p&-p;
 }
}

int findK(int K)
{
 int pos = 0,cnt = 0;
 for(int i=20; i>=0; i--) {
 pos+=(1<<i);
 if(pos>=Max||cnt+C[pos]>=K)pos-=(1<<i);
 else cnt+=C[pos];
 }
 return pos+1;
}

int main()
{
 //freopen("input.txt", "r", stdin);
 int n,r;
 while(scanf("%d%d",&n,&r),n) {
 Max = 0;
 for(int i=1; i<=n; i++)
 for(int j=1; j<=n; j++) {
 scanf("%d",&old[i][j]);
 old[i][j]++;
 if(old[i][j]>Max)Max = old[i][j];
 }

 fill(C,C+Max+1,0);

 for(int i=1; i<=2*r; i++)
 for(int j=1; j<=2*r+1; j++)
 update(old[i][j],1);

 int mid = ((2*r+1)*(2*r+1)+1)/2;
 for(int i=2*r+1; i<=n; i++) {
 if(i&1) {
 if(i-2*r-1>0)
 for(int j=1; j<=2*r+1; j++) update(old[i-2*r-1][j],-1);
 for(int j=1; j<=2*r+1; j++)update(old[i][j],1);
 for(int j=2*r+1; j<=n; j++) {
 ans[i-r][j-r] = findK(mid);
 if(j+1<=n) {
 for(int t=0; t<2*r+1; t++) {
 update(old[i-t][j-2*r],-1);
 update(old[i-t][j+1],1);
 }
 }
 }
 } else {
 for(int j=n; j>=n-2*r; j--)update(old[i-2*r-1][j],-1);
 for(int j=n; j>=n-2*r; j--)update(old[i][j],1);
 for(int j=n-2*r; j; j--) {
 ans[i-r][j+r] = findK(mid);
 if(j>1) {
 for(int t=0; t<2*r+1; t++) {
 update(old[i-t][j+2*r],-1);
 update(old[i-t][j-1],1);
 }
 }
 }
 }
 }
 for(int i=r+1; i<=n-r; i++) {
 for(int j=r+1; j<=n-r; j++)
 printf("%d ",ans[i][j]-1);
 puts("");
 }
 }
 return 0;
}