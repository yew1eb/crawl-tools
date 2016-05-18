#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;

#define CL(a, b) memset(a, b, sizeof(a))
#define CLQ(q) while(!q.empty()) q.pop()
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(i,n) for(int i=0;i<n;++i)
#define FS(i,s) for(int i=0;s[i];++i)
#define FD(i,a,b) for(int i=a;i>=b;--i)
#define FOREACH(itr,c) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define PR2(a,n,m) for(int i=0;i<n;++i){for(int j=0;j<m;++j)cout<<a[i][j]<<" ";puts("");}
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define checkMax(a,b) {if(a<b)a=b;}
#define checkMin(a,b) {if(a>b)a=b;}
#define sqr(x) ((x)*(x))
#define INF 100000000
#define EPS 1e-8
typedef long long LL;
const double pi = acos(-1.0);
#define PII pair<int,int>
#define MP make_pair
#define db double
//-----------------------------------------------------------
#define N 1005

const int M = (1<<7);
int a[N][7],sta[N];
int f[N][M];
int sub[M][M],si[M];
int n,tot;
bool o[M];

void getdata(void);
void initsub(void);

int main() {
#ifndef ONLINE_JUDGE
 freopen("in", "r", stdin);
// freopen("out", "w", stdout);
#endif
 int t,ca,ans;
 int i,j,k,l,tj,tp,nx,v,tp0;
 bool can;
 initsub();
 cin >> t;
 for (ca=1;ca<=t;ca++)
 {
 getdata();
 CL(f,0);
 for (i=1;i<=n;i++)
 {
 tp0=sta[i-1];
 for (tj=0;tj<si[tp0];tj++)
 {
 j=sub[tp0][tj];
 tp=sta[i];
 for (k=0;k<si[tp];k++)
 {
 nx=sub[tp][k];
 if (o[j] && o[nx])
 {
 v=0;
 can=true;
 for (l=0;l<7;l++)
 {
 if (a[i][l]==-1 && (j&(1<<l)) && (nx&(1<<l))==0)
 v++;
 else if (a[i][l]==1 && (nx&(1<<l)))
 v++;
 else if (a[i][l]==2 && (nx&(1<<l)) && (j&(1<<l))==0)
 can=false;
 }
 if (can && f[i-1][j]+v>f[i][nx])
 {
 f[i][nx]=f[i-1][j]+v;
 //if (i==3 && nx==5) printf("f[%d][%d]+%d=f[%d][%d]=%d\n",i-1,j,v,i,nx,f[i][nx]);
 }
 }
 }
 //printf("f[%d][%d]=%d\n",i,k,f[i][k]);
 }
 }
 //printf("f[%d][%d]=%d\n",3,6,f[3][6]);
 ans=0;
 for (i=0;i<M;i++)
 if (o[i] && f[n][i]>ans)
 ans=f[n][i];
 printf("Case #%d: %d\n",ca,ans);
 }
 return 0;
}

void getdata(void)
{
 char ch,str[10];
 int i,j,k,m,s,t,v;
 scanf("%d",&n);
 CL(a,0);
 for (i=0;i<7;i++)
 {
 scanf("%d",&m);
 for (j=0;j<m;j++)
 {
 scanf("%d",&s);
 ch=getchar();
 if (ch=='-')
 {
 scanf("%d",&t);
 a[s][i]=1;
 for (k=s+1;k<t;k++)
 a[k][i]=2;
 a[t][i]=-1;
 }
 else
 a[s][i]=1;
 }
 }
 CL(sta,0);
 for (i=1;i<=n;i++)
 {
 for (j=0;j<7;j++)
 if (a[i][j]>0)
 sta[i]|=(1<<j);
 }
 CL(o,true);
 scanf("%d",&tot);
 for (i=0;i<tot;i++)
 {
 scanf(" %s",str);
 v=0;
 for (j=0;j<7;j++)
 if (str[j]=='1')
 v+=(1<<j);
 for (j=0;j<M;j++)
 if ((j|v)==j)
 o[j]=false;
 }
}

void initsub(void)
{
 int i,j;
 for (i=0;i<M;i++)
 {
 si[i]=0;
 for (j=0;j<=i;j++)
 if ((i|j)==i)
 sub[i][si[i]++]=j;
 }
}