 //STATUS:C++_AC_0MS_248KB
 #include <functional>
 #include <algorithm>
 #include <iostream>
 //#include <ext/rope>
 #include <fstream>
 #include <sstream>
 #include <iomanip>
 #include <numeric>
 #include <cstring>
 #include <cassert>
 #include <cstdio>
 #include <string>
 #include <vector>
 #include <bitset>
 #include <queue>
 #include <stack>
 #include <cmath>
 #include <ctime>
 #include <list>
 #include <set>
 #include <map>
 using namespace std;
 //#pragma comment(linker,"/STACK:102400000,102400000")
 //using namespace __gnu_cxx;
 //define
 #define pii pair<int,int>
 #define mem(a,b) memset(a,b,sizeof(a))
 #define lson l,mid,rt<<1
 #define rson mid+1,r,rt<<1|1
 #define PI acos(-1.0)
 //typedef
 typedef __int64 LL;
 typedef unsigned __int64 ULL;
 //const
 const int N=210;
 const int INF=0x3f3f3f3f;
 const int MOD= 1000000007,STA=8000010;
 const LL LNF=1LL<<55;
 const double EPS=1e-9;
 const double OO=1e30;
 const int dx[4]={-1,0,1,0};
 const int dy[4]={0,1,0,-1};
 const int day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
 //Daily Use ...
 inline int sign(double x){return (x>EPS)-(x<-EPS);}
 template<class T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
 template<class T> T lcm(T a,T b){return a/gcd(a,b)*b;}
 template<class T> inline T lcm(T a,T b,T d){return a/d*b;}
 template<class T> inline T Min(T a,T b){return a<b?a:b;}
 template<class T> inline T Max(T a,T b){return a>b?a:b;}
 template<class T> inline T Min(T a,T b,T c){return min(min(a, b),c);}
 template<class T> inline T Max(T a,T b,T c){return max(max(a, b),c);}
 template<class T> inline T Min(T a,T b,T c,T d){return min(min(a, b),min(c,d));}
 template<class T> inline T Max(T a,T b,T c,T d){return max(max(a, b),max(c,d));}
 //End
 
 #define get(a,k) ((a)&(1<<(k))?1:0)
 
 double f[N][2],p[N];
 int num[N],op[N];
 int n;
 
 int main(){
  //   freopen("in.txt","r",stdin);
     int ca=1,i,j,k;
     double ans;
     char s[2];
     while(~scanf("%d",&n))
     {
         for(i=0;i<=n;i++)
             scanf("%d",&num[i]);
         for(i=1;i<=n;i++){
             scanf("%s",s);
             op[i]=(s[0]=='&'?0:(s[0]=='|'?1:2));
         }
         for(i=1;i<=n;i++)
             scanf("%lf",&p[i]);
         ans=0;
         for(k=0;k<20;k++){
             f[0][0]=!get(num[0],k);
             f[0][1]=!f[0][0];
             for(i=1;i<=n;i++){
                 f[i][0]=f[i-1][0]*p[i];
                 f[i][1]=f[i-1][1]*p[i];
                 if(get(num[i],k)){
                     if(op[i]==0){
                         f[i][0]+=f[i-1][0]*(1-p[i]);
                         f[i][1]+=f[i-1][1]*(1-p[i]);
                     }
                     else if(op[i]==1)
                         f[i][1]+=1-p[i];
                     else {
                         f[i][0]+=f[i-1][1]*(1-p[i]);
                         f[i][1]+=f[i-1][0]*(1-p[i]);
                     }
                 }
                 else {
                     if(op[i]==0)
                         f[i][0]+=1-p[i];
                     else {
                         f[i][0]+=f[i-1][0]*(1-p[i]);
                         f[i][1]+=f[i-1][1]*(1-p[i]);
                     }
                 }
             }
             ans+=f[n][1]*(1<<k);
         }
 
         printf("Case %d:\n%.6lf\n",ca++,ans);
     }
     return 0;
 }
