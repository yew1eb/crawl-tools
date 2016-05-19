#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define LL(x) (x<<1)
#define RR(x) (x<<1|1)
const int N=1e5+5;
struct Query
{
    int st,ed,id;
    Query(){}
    Query(int a,int b,int c){st=a;ed=b;id=c;}
    bool operator < (const Query &b) const
    {
        return ed<b.ed;
    }
};
struct node
{
    int lft,rht,sum;
    int mid(){return lft+(rht-lft)/2;}
};
struct Segtree
{
    node tree[N*4];
    void build(int lft,int rht,int ind)
    {
        tree[ind].lft=lft;  tree[ind].rht=rht;
        tree[ind].sum=0;
        if(lft!=rht)
        {
            int mid=tree[ind].mid();
            build(lft,mid,LL(ind));
            build(mid+1,rht,RR(ind));
        }
    }
    void updata(int pos,int ind,int valu)
    {
        tree[ind].sum+=valu;
        if(tree[ind].lft==tree[ind].rht) return;
        else
        {
            int mid=tree[ind].mid();
            if(pos<=mid) updata(pos,LL(ind),valu);
            else updata(pos,RR(ind),valu);
        }
    }
    int query(int be,int end,int ind)
    {
        int lft=tree[ind].lft,rht=tree[ind].rht;
        if(be<=lft&&rht<=end) return tree[ind].sum;
        else
        {
            int mid=tree[ind].mid();
            int sum1=0,sum2=0;
            if(be<=mid) sum1=query(be,end,LL(ind));
            if(end>mid) sum2=query(be,end,RR(ind));
            return sum1+sum2;
        }
    }
}seg;
int data1[N],data2[N];
int low[N],high[N],res[N],idx;
vector<int> adj[N],pos[N];
vector<Query> q;
map<int,int> imap;

void dfs(int u,int fa)
{
    low[u]=++idx;
    data2[idx]=data1[u];
    for(int i=0;i<(int)adj[u].size();i++)
    {
        int v=adj[u][i];
        if(v==fa) continue;
        dfs(v,u);
    }
    high[u]=idx;
}
void init(int n)
{
    idx=0;
    imap.clear(); q.clear();
    for(int i=0;i<=n;i++)
    {
        pos[i].clear(); adj[i].clear();
    }
}
int main()
{
    int t,t_cnt=0;
    scanf("%d",&t);
    while(t--)
    {
        int n,k,a,b,m,sc=0;
        scanf("%d%d",&n,&k);
        init(n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&data1[i]);
            if(imap.find(data1[i])==imap.end())
                imap.insert(make_pair(data1[i],sc++));
        }
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            adj[a].push_back(b);
        }
        dfs(1,-1);
        scanf("%d",&m);
        for(int i=0;i<m;i++)
        {
            scanf("%d",&a);
            q.push_back(Query(low[a],high[a],i));
        }
        sort(q.begin(),q.end());
        int ind=0;
        seg.build(1,idx,1);
        for(int i=1;i<=n;i++)
        {
            int id=imap[data2[i]];
            pos[id].push_back(i);
            int cnt=(int)pos[id].size();
            if(cnt>=k)
            {
                if(cnt>k)
                    seg.updata(pos[id][cnt-k-1],1,-2);
                if(cnt>k+1)
                    seg.updata(pos[id][cnt-k-2],1,1);
                seg.updata(pos[id][cnt-k],1,1);
            }
            while(ind<m&&q[ind].ed==i)
            {
                res[q[ind].id]=seg.query(q[ind].st,q[ind].ed,1);
                ind++;
            }

        }
        if(t_cnt!=0) puts("");
        printf("Case #%d:\n",++t_cnt);
        for(int i=0;i<m;i++) printf("%d\n",res[i]);
    }
    return 0;
}
