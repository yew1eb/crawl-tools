#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

#define LL(x) (x<<1)
#define RR(x) (x<<1|1)
#define MID(a,b) (a+((b-a)>>1));
#define INF (1<<30)
const int N=100005;

struct BOARD
{
    int h,x1,x2,valu,ind;
    BOARD(){}
    BOARD(int a,int b,int c,int d)
    {h=a;x1=b;x2=c;valu=d;}
    bool operator<(const BOARD&b)const
    { return h<b.h; }
}p[N];
struct node
{
    int lft,rht,flag;
    int mid(){return MID(lft,rht);}
};

int n,dis[N];
vector<int> y;
vector<pair<int,int> >adj[N];
map<int,int> H;
bool vis[N];

struct Segtree
{
    node tree[N*4];
    void down(int ind)
    {
        if(tree[ind].flag)
        {
            tree[LL(ind)].flag=tree[ind].flag;
            tree[RR(ind)].flag=tree[ind].flag;
            tree[ind].flag=0;
        }
    }
    void build(int lft,int rht,int ind)
    {
        tree[ind].lft=lft;    tree[ind].rht=rht;
        tree[ind].flag=0;
        if(lft!=rht)
        {
            int mid=tree[ind].mid();
            build(lft,mid,LL(ind));
            build(mid+1,rht,RR(ind));
        }
    }
    void updata(int st,int ed,int ind,int valu)
    {
        int lft=tree[ind].lft,rht=tree[ind].rht;
        if(st<=lft&&rht<=ed) tree[ind].flag=valu;
        else
        {
            down(ind);
            int mid=tree[ind].mid();
            if(st<=mid) updata(st,ed,LL(ind),valu);
            if(ed> mid) updata(st,ed,RR(ind),valu);
        }
    }
    int query(int pos,int ind)
    {
        if(tree[ind].flag) return tree[ind].flag;
        else
        {
            int mid=tree[ind].mid();
            if(pos<=mid) return query(pos,LL(ind));
            else return query(pos,RR(ind));
        }
    }
}seg;
int spfa(int st,int ed,int valu)
{
    if(valu<=0) return -1;
    queue<int> que;
    dis[st]=valu;
    que.push(st);
    while(!que.empty())
    {
        int u=que.front(); que.pop();
        vis[u]=0;
        for(int i=0;i<(int)adj[u].size();i++)
        {
            int v=adj[u][i].first,w=adj[u][i].second;
            if(dis[u]+w<=0) continue;
            if(dis[v]<dis[u]+w)
            {
                dis[v]=dis[u]+w;
                if(!vis[v])
                {
                    que.push(v);
                    vis[v]=1;
                }
            }
        }
    }
    //for(int i=ed;i<=st;i++) printf("%d ",dis[i]);puts("");
    if(dis[ed]<=0) return -1;
    return dis[ed];
}
int main()
{
    //freopen("in.txt","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        y.clear(); H.clear();
        for(int i=0;i<=n+5;i++)
        {
            adj[i].clear(),dis[i]=-INF,vis[i]=0;
        }

        int h,x1,x2,valu;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d%d",&h,&x1,&x2,&valu);
            p[i]=BOARD(h,x1,x2,valu);
            y.push_back(x1); y.push_back(x2);
        }
        p[++n]=BOARD(0,0,N+5,0);
        y.push_back(0); y.push_back(N+5);
        sort(p+1,p+n+1);
        for(int i=1;i<=n;i++)
        {
            p[i].ind=i;
            //cout<<p[i].h<<" "<<p[i].x1<<" "<<p[i].x2<<endl;
        }

        sort(y.begin(),y.end());
        y.erase(unique(y.begin(),y.end()),y.end());
        for(int i=0;i<(int)y.size();i++) H[y[i]]=i;
        seg.build(0,(int)y.size()-1,1);

        seg.updata(H[p[1].x1],H[p[1].x2],1,p[1].ind);
        for(int i=2;i<=n;i++)
        {
            int tmp1=seg.query(H[p[i].x1],1);
            adj[p[i].ind].push_back(make_pair(tmp1,p[tmp1].valu));
            //cout<<p[i].ind<<"->"<<tmp1<<" "<<p[tmp1].valu<<endl;
            int tmp2=seg.query(H[p[i].x2],1);
            if(tmp1!=tmp2)
                adj[p[i].ind].push_back(make_pair(tmp2,p[tmp2].valu));
            //cout<<p[i].ind<<"->"<<tmp2<<" "<<p[tmp2].valu<<endl;
            seg.updata(H[p[i].x1],H[p[i].x2],1,p[i].ind);
        }
        int res=spfa(p[n].ind,p[1].ind,p[n].valu+100);
        printf("%d\n",res);
    }
    return 0;
}
