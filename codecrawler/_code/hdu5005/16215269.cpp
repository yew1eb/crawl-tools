#include<cstring>
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
#define ll long long
#define pf printf
#define sf scanf
#define Fill(a,b) memset(a,b,sizeof(a))
const int N = 222;
struct st
{
    int a,x,tot;
    int nxt[202];
    char turn;
};
int f[N],g[N];
st a[N];
int n;
void solve(int x)
{
    if (f[x] != -1 || g[x] != -1) return;
    int maxa = 0,maxx = 0;
    for (int i = 1; i <= a[x].tot; i++)
    {
        int y = a[x].nxt[i];
        solve(y);
        if (a[x].turn == 'X')
        {
            if (maxx < g[y])
            {
                maxx = g[y];
                maxa = f[y];
            }
        }
        else
        {
            if (maxa < f[y])
            {
                maxa = f[y];
                maxx = g[y];
            }
        }
    }
    f[x] = maxa; g[x] = maxx;
}
void dfs(int x,int va,int vx)
{
  //  cout<<x<<" "<<a[x].turn<<endl;
    //cout<<x<<endl;
    //cout<<f[x]<<" "<<g[x]<<endl;
    if (f[x] != -1 || g[x] != -1) return;
    if (a[x].turn == 'X')
    {
        bool flag = 0;
     //   cout<<x<<endl;
        for (int i = 1; i <= a[x].tot; i++)
        {
            int y = a[x].nxt[i];
          //  if (x == 5) cout<<y<<endl;
            dfs(y,va,vx);
            if (g[y] == vx) flag = 1;
        }
        //if (x == 5) cout<<flag<<endl;
        if (flag)
        {
            f[x] = va;
            g[x] = vx;
            return;
        }
        int maxa = 1e9,maxx;
        for (int i = 1; i <= a[x].tot; i++)
        {
            int y = a[x].nxt[i];
            if (maxa > f[y])
            {
                maxa = f[y];
                maxx = g[y];
            }
        }
        f[x] = maxa; g[x] = maxx;
    }
    else
    {
        int maxa = 0,maxx = 0;
        for (int i = 1; i <= a[x].tot; i++)
        {
            int y = a[x].nxt[i];
            dfs(y,va,vx);
            if (maxa < f[y])
            {
                maxa = f[y];
                maxx = g[y];
            }
        }
        f[x] = maxa; g[x] = maxx;
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    int T;
    sf("%d",&T);
    for (int TT = 1; TT <= T; TT++)
    {
        sf("%d",&n);
        for (int i = 1; i <= n; i++)
        {
            int x;
            sf("%d",&x);
            //cout<<i<<" "<<x<<endl;
            if (x == 0)
            {
                sf("%d%d",&a[i].a,&a[i].x);
                a[i].tot = 0;
            }
            else
            {
               // cout<<x<<endl;
                a[i].tot = 0;
                for (int j = 1; j <= x; j++) sf("%d",&a[i].nxt[++a[i].tot]);
                char ch;
                sf("%c%c",&ch,&a[i].turn);
                //cout<<a[i].turn<<endl;
            }
        }
        Fill(f,-1); Fill(g,-1);
        for (int i = 1; i <= n; i++)
            if (a[i].tot == 0) f[i] = a[i].a,g[i] = a[i].x;
        solve(1);
        int ans1 = g[1],ans2 = 0;
        for (int i = 1; i <= n; i++)
            if (a[i].tot == 0)
            {
                int va = a[i].a,vx = a[i].x;
               // va = 100; vx = 101;
              // cout<<va<<" "<<vx<<endl;
                Fill(f,-1); Fill(g,-1);
                for (int j = 1; j <= n; j++)
                    if (a[j].tot == 0) f[j] = a[j].a,g[j] = a[j].x;
                dfs(1,va,vx);
                if (g[1] == vx) ans2 = max(ans2,g[1]);
            }
        pf("%d %d\n",ans1,ans2);
    }
    return 0;
}
