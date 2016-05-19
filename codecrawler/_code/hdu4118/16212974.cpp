#include <stdio.h>
#include <cstring>
#include <stack>
using namespace std;
struct gtype {
       int y,d,next;
}g[200010];
int first[100100],tot,a[100100],tt,x,y,d,n;
bool v[100100];
inline int min(int a,int b) {
       if (a<b) return a; else return b;
} 
void add(int x,int y,int d) {
     tot++;
     g[tot].d=d;
     g[tot].y=y;
     g[tot].next=first[x];
     first[x]=tot;
     tot++;
     g[tot].d=d;
     g[tot].y=x;
     g[tot].next=first[y];
     first[y]=tot;
}
void dfs(int p) {
     stack <int> stk;
     int t=first[p];
     
     stk.push(p);
     v[p]=true;
     while (1) {
           if (t==-1) {
                      int y = stk.top();
                      stk.pop();
                      if (stk.empty()) break;
                      a[stk.top()]+=a[y];
           }
           int x = stk.top();
           t = first[x];
           while (t!=-1) {
                 if (!v[g[t].y]) {
                                 v[g[t].y]=true;
                                 stk.push(g[t].y);
                                 break;
                 }
                 t=g[t].next;
           }
     }
}
int main() {
    scanf("%d",&tt);
    for (int cas=1;cas<=tt;cas++) {
        tot=0;
        memset(g,0,sizeof(g));
        memset(first,-1,sizeof(first));
        scanf("%d",&n);
        for (int i=1;i<n;i++) {
            scanf("%d%d%d",&x,&y,&d);
            add(x,y,d);
        }
        for (int i=1;i<=n;i++) a[i]=1;
        memset(v,0,sizeof(v));
        dfs(1);
        __int64 ans=0;
        for (int i=1;i<=2*(n-1);i+=2) {
            x=g[i].y;
            y=g[i+1].y;
            d=min(a[x],a[y]);
            ans+=min(d,n-d)*2*g[i].d;
        }
        printf("Case #%d: %I64d\n",cas,ans);
    }
    return 0;
}
