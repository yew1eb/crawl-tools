#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cmath>
#include<bitset>
#include<string>
#include<climits>
#include<cstdio>
#include<vector>
#include<utility>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define IN puts("in")
#define OUT puts("out")
#define FR(x) freopen(x,"r",stdin)
#define FW(x) freopen(x,"w",stdout)
#define MSET(x,y) memset(x,y,sizeof(x))
#define ST system("pause")
#define lowbit(x) (x)&(-x)
#define L(x) (x)<<1
#define R(x) ((x)<<1)^1
using namespace std;
const int maxn = 505;
char cat[maxn][2][5];
char dog[maxn][2][5];
struct nd{
        int v,next;
}edge[maxn*maxn];
int head[maxn],vis[maxn],to[maxn];
int ecnt,n,m,vv;
void add(int u,int v)
{
        edge[ecnt].v = v;
        edge[ecnt].next = head[u];
        head[u] = ecnt++;
}
void readin()
{
        int i,j,c,d,v;
        char str[2][5];
        scanf("%d %d %d",&c,&d,&v);
        vv = v;
        n = m = ecnt = 0;
        while(v--)
        {
                scanf("%s %s",str[0],str[1]);
                if(str[0][0]=='D'){
                        strcpy(dog[n][0],str[0]);
                        strcpy(dog[n][1],str[1]);
                        n++;
                }else{
                        strcpy(cat[m][0],str[0]);
                        strcpy(cat[m][1],str[1]);
                        m++;
                }
        }
        MSET(head,-1);
        for(i = 0; i < n; ++ i)
                for(j = 0; j < m; ++ j)
                        if(strcmp(dog[i][0],cat[j][1])==0||strcmp(dog[i][1],cat[j][0])==0)
                                add(i,j);
}
int dfs(int u)
{
        int i,v;
        for(i = head[u]; i != -1; i = edge[i].next)
        {
                v = edge[i].v;
                if(!vis[v]){
                        vis[v] = 1;
                        if(to[v]==-1||dfs(to[v])){
                                to[v] = u;
                                return 1;
                        }
                }
        }return 0;
}
void processing()
{
        int i,k = 0;
        MSET(to,-1);
        for(i = 0; i < n; ++ i){
                MSET(vis,0);
                k += dfs(i);
        }
        printf("%d\n",vv-k);
}
int main()
{
        int t;
        scanf("%d",&t);
        while(t--)
        {
            readin();
            processing();
        }
        return 0;
}