#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<map>
using namespace std;
const int maxn = 205;
const int INF = (1<<30)-1;
int g[maxn][maxn];
int lx[maxn],ly[maxn];
int match[maxn];
bool visx[maxn],visy[maxn];
int slack[maxn];
char s1[maxn],s2[maxn];
map<string ,int > m1,m2;
int n,m;
bool dfs(int cur){
     visx[cur] = true;
     for(int y=1;y<=m;y++){
         if(visy[y])   continue;
         int t=lx[cur]+ly[y]-g[cur][y];
         if(t==0){
            visy[y] = true;
            if(match[y]==-1||dfs(match[y])){
                match[y] = cur;
                return true;
            }
         }
         else if(slack[y]>t){
                 slack[y]=t;
         }
     }
     return false;
}
int KM(){
    memset(match,-1,sizeof(match));
    memset(ly,0,sizeof(ly));
    for(int i=1 ;i<=n;i++){
         lx[i]=-INF;
       for(int j=1;j<=m;j++)
           if(g[i][j]>lx[i])   lx[i]=g[i][j];
    }
    for(int x=1;x<=n;x++){
        for(int i=1;i<=m;i++)  slack[i]=INF;
        while(true){
            memset(visx,false,sizeof(visx));
            memset(visy,false,sizeof(visy));
            if(dfs(x))  break;
            int d=INF;
            for(int i=1;i<=m;i++){
               if(!visy[i]&&d>slack[i])     d=slack[i];
            }
            for(int i=1;i<=n;i++){
               if(visx[i])                  lx[i]-=d;
            }
            for(int i=1;i<=m;i++){
               if(visy[i])                 ly[i]+=d;
               else                        slack[i]-=d;
            }
        }
   }
    int result = 0;
    for(int i = 1; i <=m  ; i++){
      if(match[i]>-1){
        result += g[match[i]][i];
      }
    }
    return result;
}
int main(){
    int val,k;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF){
        m1.clear();  m2.clear();
        int k1=1,k2=1;
        for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
          g[i][j]=-INF;
        for(int i=0;i<k;i++){
            scanf("%s%s%d",s1,s2,&val);
            string a(s1);
            string b(s2);
            if(!m1[a])
            m1[a]=k1++;
            if(!m2[b])
            m2[b]=k2++;
            g[m1[a]][m2[b]]=-val;
        }
        int ans=-KM();
        printf("%d\n",ans);
    }
    return 0;
}