//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<cmath>
#include<climits>
#include<string>
#include<map>
#include<queue>
#include<vector>
#include<stack>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb(a) push_back(a)
#define INF 0x1f1f1f1f
#define lson idx<<1,l,mid
#define rson idx<<1|1,mid+1,r
#define PI  3.1415926535898
template<class T> T min(const T& a,const T& b,const T& c) {
    return min(min(a,b),min(a,c));
}
template<class T> T max(const T& a,const T& b,const T& c) {
    return max(max(a,b),max(a,c));
}
void debug() {
#ifdef ONLINE_JUDGE
#else

    freopen("d:\\in.txt","r",stdin);
    freopen("d:\\out1.txt","w",stdout);
#endif
}
int getch() {
    int ch;
    while((ch=getchar())!=EOF) {
        if(ch!=' '&&ch!='\n')return ch;
    }
    return EOF;
}

vector<int>  g[2000];
int dp[2000][2];
int f(int idx,int flag,int fa)
{
    if(dp[idx][flag]>=0)return dp[idx][flag];
    int a=1;
    for(int i=0;i<g[idx].size();i++)
    {
        int v=g[idx][i];
        if(v!=fa)
            a+=f(v,1,idx);
    }
    if(fa==-1||flag==1)
    {
        int x=0;
        for(int i=0;i<g[idx].size();i++)
        {
            int v=g[idx][i];
            if(v!=fa)
                x+=f(v,0,idx);
        }
        a=min(a,x);
    }
    return dp[idx][flag]=a;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
            g[i].clear();
        for(int i=1;i<=n;i++)
        {
            int u,k;
            scanf(" %d:(%d)",&u,&k);
            for(int j=1;j<=k;j++)
            {
                int v;
                scanf("%d",&v);
                g[u].pb(v);
                g[v].pb(u);
            }
        }
        memset(dp,-1,sizeof(dp));
        int num=f(0,1,-1);
        printf("%d\n",num);
    }
    return 0;
}