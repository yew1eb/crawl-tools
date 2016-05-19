 //STATUS:C++_AC_156MS_4268KB
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
 const int N=1010;
 const int INF=0x3f3f3f3f;
 const LL MOD=1000000007,STA=8000010;
 const LL LNF=1LL<<55;
 const double EPS=1e-9;
 const double OO=1e50;
 const int dx[8]={-1,-1,0,1,1,1,0,-1};
 const int dy[8]={0,1,1,1,0,-1,-1,-1};
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
 
 int g[N][N];
 int T,n,m,k;
 
 int bfs(int x,int y)
 {
     int i,nx,ny,ret=0;
     pii t;
     g[x][y]=-1;
     queue<pii> q;
     q.push(make_pair(x,y));
     while(!q.empty())
     {
         t=q.front();q.pop();
         for(i=0;i<8;i++){
             nx=t.first+dx[i];
             ny=t.second+dy[i];
             if(nx<0||nx>=n || ny<0||ny>=m || g[nx][ny]==-1)continue;
             if(g[nx][ny])ret++;
             else q.push(make_pair(nx,ny));
             g[nx][ny]=-1;
         }
     }
     return ret;
 }
 
 int main(){
  //   freopen("in.txt","r",stdin);
     int i,j,sg,x,y,nx,ny,ca=1;
     scanf("%d",&T);
     while(T--)
     {
         scanf("%d%d%d",&n,&m,&k);
         mem(g,0);
         for(i=0;i<k;i++){
             scanf("%d%d",&x,&y);
             g[x][y]=-1;
             for(j=0;j<8;j++){
                 nx=x+dx[j];ny=y+dy[j];
                 if(nx<0||nx>=n || ny<0||ny>=m || g[nx][ny]==-1)continue;
                 g[nx][ny]=1;
             }
         }
 
         sg=0;
         for(i=0;i<n;i++){
             for(j=0;j<m;j++){
                 if(g[i][j])continue;
                 sg^=(bfs(i,j)&1)+1;
             }
         }
         for(i=0;i<n;i++){
             for(j=0;j<m;j++){
                 if(g[i][j]==-1)continue;
                 sg^=1;
             }
         }
 
         printf("Case #%d: %s\n",ca++,sg?"Xiemao":"Fanglaoshi");
     }
     return 0;
 }
