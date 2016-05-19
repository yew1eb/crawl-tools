#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<map>
#include<algorithm>
#include<queue>
#include<set>
#define inf 1000000000
#define pi acos(-1.0)
#define eps 1e-8
#define seed 131
using namespace std;
typedef pair<int,int> pii;
typedef unsigned long long ull;
typedef long long ll;
const int maxn=50005;
struct Node
{
    int state;
    int x,ti;
}node[maxn];
int cpy[maxn];
int n;
int d[maxn];
int sum[maxn<<2];
int hou[maxn<<2];
int tot,ans;
void pushup(int rt)
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
    hou[rt]=max(hou[rt<<1|1],sum[rt<<1|1]+hou[rt<<1]);
}
void update(int L,int u,int l,int r,int rt)
{
    if(l==r)
    {
        sum[rt]+=u;
        hou[rt]+=u;
        return;
    }
    int m=(l+r)>>1;
    if(L<=m)
        update(L,u,l,m,rt<<1);
    if(L>m)
        update(L,u,m+1,r,rt<<1|1);
    pushup(rt);
}
void solve(int l,int r,int rt)
{
    if(l==r)
    {
        ans=l;
        return;
    }
    int m=(l+r)>>1;
    if(tot+hou[rt<<1|1]>0)
        solve(m+1,r,rt<<1|1);
    else
    {
        tot+=sum[rt<<1|1];
        solve(l,m,rt<<1);
    }
}
void query(int L,int R,int l,int r,int rt)
{
    if(ans!=-1)
        return;
    if(L<=l&&R>=r)
    {
        if(tot+hou[rt]>0)
            solve(l,r,rt);
        else
            tot+=sum[rt];
        return;
    }
    int m=(l+r)>>1;
    if(R>m)
        query(L,R,m+1,r,rt<<1|1);
    if(L<=m)
        query(L,R,l,m,rt<<1);
}
int main()
{
    string s;
    int a,b;
    int cas=1;
    while(~scanf("%d",&n)&&n)
    {
        for(int i=0;i<n;i++)
        {
            cin>>s;
            if(s=="push")
            {
                scanf("%d%d",&node[i].x,&node[i].ti);
                node[i].state=1;
            }
            else if(s=="pop")
            {
                scanf("%d",&node[i].ti);
                node[i].state=2;
            }
            else
            {
                scanf("%d",&node[i].ti);
                node[i].state=3;
            }
            cpy[i]=node[i].ti;
        }
        sort(cpy,cpy+n);
        for(int i=0;i<n;i++)
        {
            node[i].ti=lower_bound(cpy,cpy+n,node[i].ti)-cpy+1;
            d[node[i].ti]=node[i].x;
        }
        printf("Case #%d:\n",cas++);
        memset(sum,0,sizeof(sum));
        memset(hou,0,sizeof(hou));
        for(int i=0;i<n;i++)
        {
            if(node[i].state==1)
                update(node[i].ti,1,1,n,1);
            else if(node[i].state==2)
                update(node[i].ti,-1,1,n,1);
            else
            {
                tot=0;ans=-1;
                query(1,node[i].ti,1,n,1);
                if(ans==-1)
                    printf("-1\n");
                else
                    printf("%d\n",d[ans]);
            }
        }
    }
    return 0;
}