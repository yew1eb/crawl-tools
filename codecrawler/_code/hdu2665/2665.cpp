//#pragma comment(linker, "/STACK:102400000,102400000")
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#include<cctype>
#include<string>
#include<algorithm>
#include<iostream>
#include<ctime>
#include<map>
#include<set>
using namespace std;
#define MP(x,y) make_pair((x),(y))
#define PB(x) push_back(x)
typedef long long LL;
//typedef unsigned __int64 ULL;
/* ****************** */
const int INF=1000111222;
const double INFF=1e200;
const double eps=1e-8;
const LL mod=1000000007;
const int NN=100010;
const int MM=100010;
/* ****************** */

int a[NN],tf[NN],root[NN];
struct TR
{
    int ls,rs,sum;
}tr[NN*20];
int cnt;

int build(int l,int r)
{
    int id=++cnt;
    tr[id].sum=0;
    if(l!=r)
    {
        int mid=(l+r)>>1;
        tr[id].ls=build(l,mid);
        tr[id].rs=build(mid+1,r);
    }
    return id;
}

void push_up(int R)
{
    tr[R].sum=tr[ tr[R].ls ].sum + tr[ tr[R].rs ].sum;
}

int update(int x,int pre,int l,int r)
{
    int id=++cnt;
    tr[id].ls=tr[pre].ls;
    tr[id].rs=tr[pre].rs;
    tr[id].sum=tr[pre].sum;
    if(l==r)
    {
        tr[id].sum++;
        return id;
    }
    int mid=(l+r)>>1;
    if(x<=mid)
        tr[id].ls=update(x,tr[pre].ls,l,mid);
    else
        tr[id].rs=update(x,tr[pre].rs,mid+1,r);
    push_up(id);
    return id;
}

int query(int id1,int id2,int k,int l,int r)
{
    if(l==r)
        return l;
    int x=tr[ tr[id2].ls ].sum;
    x-=tr[ tr[id1].ls ].sum;
    int mid=(l+r)>>1;

  //  printf("now==[%d,%d]\n",l,r);
   // printf("[%d,%d] have %d\n",l,mid,x);

    if(x>=k)
        return query(tr[id1].ls,tr[id2].ls,k,l,mid);
    else
        return query(tr[id1].rs,tr[id2].rs,k-x,mid+1,r);
}

int main()
{
    int cas,n,m;
    int i,tol,x,st,en,k;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            tf[i]=a[i];
        }
        sort(tf+1,tf+1+n);
        tol=unique(tf+1,tf+1+n)-tf-1;
        cnt=0;
        root[0]=build(1,tol);

        for(i=1;i<=n;i++)
        {
            x=lower_bound(tf+1,tf+1+tol,a[i])-tf;
            root[i]=update(x,root[i-1],1,tol);
         //   printf("(%d,%d)%c",a[i],x,i==n?'\n':' ');
        }
        while(m--)
        {
            scanf("%d%d%d",&st,&en,&k);
            x=query(root[st-1],root[en],k,1,tol);
            printf("%d\n",tf[x]);
        }
    }
    return 0;
}