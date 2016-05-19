/*
题意：
给你 n个点。他们有 上下级关系，一个点只有一个上级，一个上级 可以有多个下级，每个点有两个属性，能力值 、忠诚度（每个节点的忠诚度不同），求我们要删除 一个节点， 则我们 需从 其下级中选出 一个节点，其能力值 比该节点 要高，且 忠诚度是（比其能力高的下级节点中的）最高
题解：
首先将树状结构，转化为 线状结构， 
可以遍历一遍将树上每个点标记为一维区间上的某个点，且在同一棵子树内的点是连续的一段。
然后，将所有点按能力从大到小排序，能力相同的编号小的排在前面，然后扫描一遍，扫描时维护一颗线段树，
（我们先插入线段树的是，比其能力值 大的，我们只要从这些里面找到，忠诚度最高的就 可以了）
先查找该点为根节点的子树内的最优值，然后插入该点的忠诚度。
*/
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<set>
#include<map>
#define maxn    100110
#define mod 100000007
#define eps  1e-6;
#define ll  long long
#define M   15520
using namespace std;
map<int,int>map1;
vector<int>g[maxn] ;
int num ,ans[maxn],n,m,l[maxn],r[maxn];
struct staff
{
    int loy;
    int abt;
    int id;
}sta[maxn];
struct node
{
    int l;
    int r;
    int mx;
}p[maxn * 2];
bool cmp (staff a, staff b)
{
    return a.abt > b.abt ;
}
void dfs(int x)//编号变为线状结构
{
    l[x] = num++;
    for(int i = 0; i < g[x].size(); ++i)
    {
        dfs(g[x][i]);
    }
    r[x] = num ;
}
void build(int x,int l,int r)
{
    p[x].l = l;
    p[x].r = r;
    p[x].mx = -1 ;
    if(l == r) return  ;
    int mid = (l + r) /2;
    build(x*2,l,mid);
    build(x*2+1,mid + 1,r);
}
int get(int x,int l,int r)
{
    if( r < l ) return  -1 ;
    if(p[x].l == l && p[x].r == r)
    {
        return p[x].mx;
    }
    int mid = (p[x].l + p[x].r) /2 ;
    if(r <= mid)  return get(x * 2,l,r);
    else
    {
        if(l > mid) return get(x * 2 + 1,l,r);
        else
        {
            return max(get(x * 2,l,mid),get(x * 2 + 1,mid + 1,r));
        }
    }
}
void insert(int x,int pos,int d)
{
    if(p[x].l == p[x].r )
    {
        p[x].mx = d;
        return ;
    }
    int mid = (p[x].l + p[x].r) /2 ;
    if(pos <= mid) insert(x*2,pos,d);
    else
    {
        insert(x*2 + 1, pos,d);
    }
    p[x].mx = max(p[x*2].mx,p[x*2+1].mx);
}
void init()
{
    for( int i = 0; i <= n; ++i )
        g[i].clear();
    map1.clear();
    num = 0 ;
}
int main()
{
    int t,u,loy,abt,a,j,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        init();
        for( i = 1 ; i < n; ++i)
        {
            scanf("%d%d%d",&u,&loy,&abt);
            g[u].push_back(i);
            sta[i].loy = loy;
            sta[i].abt = abt ;
            sta[i].id = i;
            map1[loy] = i;
        }
        dfs(0);
        build(1,0,num - 1);
        sort(sta + 1,sta + n,cmp);//排序为了下面 查询 打基础，排好序之后，我们插入时，保证了，比 i 大的已经插入了这时直接找，忠诚的uida就可以了
        for( i = 1 ; i < n ; i = j)
        {
            j = i;
            while(j < n &&sta[i].abt == sta[j].abt)
            {
                int id = sta[j].id ;
                loy = get(1,l[id] + 1,r[id] - 1);

                if(loy != -1) ans[id] = map1[loy] ;
                else ans[id] = -1;
                ++j;
            }
            j = i ;
            while(j < n && sta[i].abt == sta[j].abt )
            {
                int id =  sta[j].id;
                insert(1,l[id],sta[j].loy);
                ++j;
            }
        }
        while(m--)
        {
            scanf("%d",&a);
            printf("%d\n",ans[a]) ;
        }
    }
    return 0;
}
