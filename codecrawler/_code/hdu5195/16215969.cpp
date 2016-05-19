#include"cstdio"
#include"cstring"
#include"cmath"
#include"cstdlib"
#include"algorithm"
#include"iostream"
#include"map"
#include"vector"
#include"queue"
#define ll long long
#define inf 9999999
using namespace std;
#define MAXN 100004
struct tree
{
    int l,r;
    int mi;
} a[MAXN*4];
int rd[MAXN];
vector<int>edge[MAXN];
void init(int id,int l,int r)
{
    a[id].l=l;
    a[id].r=r;
    if(a[id].l==a[id].r)
    {
        a[id].mi=rd[l];
        return;
    }
    init(2*id,l,(l+r)/2);
    init(2*id+1,(r+l)/2+1,r);
    a[id].mi=min(a[2*id].mi,a[2*id+1].mi);
}
void make(int id,int x,int y)
{
    if(a[id].l==a[id].r)
    {
        a[id].mi=y;
        return ;
    }
    int mid=(a[id].r+a[id].l)/2;
    if(x<=mid) make(id*2,x,y);
    else make(id*2+1,x,y);
    a[id].mi=min(a[id*2].mi,a[id*2+1].mi);
}
int solve(int id,int k)
{
    if(a[id].l==a[id].r) return a[id].l;
    if(a[id*2+1].mi<=k) return solve(id*2+1,k);
    else return solve(id*2,k);
}
int main()
{
    int n,m,k;
    while(cin>>n>>m>>k)
    {
        memset(rd,0,sizeof(rd));
        for(int i=1; i<=n; i++) edge[i].clear();
        while(m--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            edge[x].push_back(y);
            rd[y]++;
        }
        init(1,1,n);
        for(int i=1;i<=n;i++)
        {
            int now=solve(1,k);
            k-=rd[now];
            rd[now]=inf;
            make(1,now,inf);
            int len=edge[now].size();
            for(int j=0;j<len;j++)
            {
                int tep=edge[now][j];
                rd[tep]--;
                make(1,tep,rd[tep]);
            }
            printf(i==n?"%d\n":"%d ",now);
        }
    }
    return 0;
}