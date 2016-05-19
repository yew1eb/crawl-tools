#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
#include<string>
#pragma comment(linker, "/STACK:102400000,102400000")
typedef long long ll;
using namespace std;
const ll maxn=105;
int T,n,m,t,f[maxn][maxn],x,y,a[maxn],b[maxn],c[maxn][maxn];

struct point
{
    int x,y,z,t,now;
    point(){}
    point(int x,int y,int z,int t,int now):
    x(x),y(y),z(z),t(t),now(now) {};
    bool operator <(const point &a) const
    {
        return now+t>a.now+a.t;
    }
};

int get(int x,int y,int d)
{
    if (d&1)
    {
        if (d==1)
        {
            for (int i=y+1;i<=m;i++)
                if (f[x][i]) return i-y;
            return 0;
        }
        else 
        {
            for (int i=y-1;i>=1;i--)
                if (f[x][i]) return y-i;
            return 0;
        }
    }
    else 
    {
        if (d==0) 
        {
            for (int i=x-1;i>=1;i--)
                if (f[i][y]) return x-i;
            return 0;
        }
        else 
        {
            for (int i=x+1;i<=n;i++)
                if (f[i][y]) return i-x;
            return 0;
        }
    }
}

int main()
{
    //scanf("%d",&T);
    while (~scanf("%d%d%d%d",&n,&m,&t,&T))
    {
        memset(f,0,sizeof(f));
        memset(c,0,sizeof(c));
        for (int i=1;i<=t;i++)
        {
            scanf("%d%d",&x,&y);
            a[i]=x;    b[i]=y;
            scanf("%d",&f[x][y]);
        }
        scanf("%d%d",&x,&y);
        priority_queue<point> p;
        for (int i=0;i<4;i++) 
        {
            int k=get(x,y,i);
            if (k>0) p.push(point(x,y,i,k,0));
        }
        while (!p.empty())
        {
            point tp,q=p.top();    p.pop();
            
            for (;;p.pop())
            {
                if (p.empty()) break;
                tp=p.top();
                if(tp.now+tp.t!=q.now+q.t) break;
                int k=get(tp.x,tp.y,tp.z);
                if (!k) continue;
                if (k!=tp.t) p.push(point(tp.x,tp.y,tp.z,k,tp.now));
                else 
               {
                if (k+tp.now>T) break;
                if (tp.z==0) x=tp.x-k,y=tp.y;
                if (tp.z==1) x=tp.x,y=tp.y+k;
                if (tp.z==2) x=tp.x+k,y=tp.y;
                if (tp.z==3) x=tp.x,y=tp.y-k;
                f[x][y]++;
                }
            }
            int k=get(q.x,q.y,q.z);
            if (k) 
            if (k!=q.t) p.push(point(q.x,q.y,q.z,k,q.now));
            else 
            {
                if (k+q.now>T) break;
                if (q.z==0) x=q.x-k,y=q.y;
                if (q.z==1) x=q.x,y=q.y+k;
                if (q.z==2) x=q.x+k,y=q.y;
                if (q.z==3) x=q.x,y=q.y-k;
                f[x][y]++;
            }
            for(int i=1;i<=t;i++)
            {
                x=a[i];    y=b[i];
                if (f[x][y]>4)
                {
                    f[x][y]=0;
                    c[x][y]=q.t+q.now;
                    for (int j=0;j<4;j++) 
                    {
                        int u=get(x,y,j);
                        if (u>0) p.push(point(x,y,j,u,q.t+q.now));
                    }
                }
            }
        }
        for (int i=1;i<=t;i++)
        {
            if (f[a[i]][b[i]]) printf("1 %d\n",f[a[i]][b[i]]);
            else printf("0 %d\n",c[a[i]][b[i]]);
        }
    }
    return 0;
}