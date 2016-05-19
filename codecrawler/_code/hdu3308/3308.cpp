#include <iostream>
#include <cstring>
#include <cstdio>
#define lson pos<<1
#define rson pos<<1|1
using namespace std;
const int MAXN=100005;
struct node
{
    int l,r;
    int msum;
    int lsum,rsum;
    int mid()
    {
        return (l+r)>>1;
    }
};
node tree[MAXN*4];
int num[MAXN];
inline void pushup(int pos)
{
    tree[pos].msum=max(tree[lson].msum,tree[rson].msum);
    tree[pos].lsum=tree[lson].lsum;
    tree[pos].rsum=tree[rson].rsum;
    if(num[tree[lson].r]<num[tree[rson].l])
    {
        tree[pos].msum=max(tree[pos].msum,tree[lson].rsum+tree[rson].lsum);
        if(tree[lson].lsum==tree[lson].r-tree[lson].l+1)
            tree[pos].lsum+=tree[rson].lsum;
        if(tree[rson].rsum==tree[rson].r-tree[rson].l+1)
            tree[pos].rsum+=tree[lson].rsum;
    }
}
void build(int l,int r,int pos)
{
    tree[pos].l=l;
    tree[pos].r=r;
    if(l==r)
    {
        tree[pos].lsum=tree[pos].rsum=tree[pos].msum=1;
        return ;
    }
    int mid=tree[pos].mid();
    build(l,mid,lson);
    build(mid+1,r,rson);
    pushup(pos);
}
void update(int a,int b,int pos)
{
    if(tree[pos].l==tree[pos].r)
    {
        num[a]=b;
        return ;
    }
    int mid=tree[pos].mid();
    if(a<=mid)
        update(a,b,lson);
    else
        update(a,b,rson);
    pushup(pos);
}
int queryL(int l,int r,int pos)
{
    if(r-l+1>=tree[pos].lsum)
        return tree[pos].lsum;
    else
        return r-l+1;
}
int queryR(int l,int r,int pos)
{
    if(r-l+1>=tree[pos].rsum)
        return tree[pos].rsum;
    else
        return r-l+1;
}
int query(int l,int r,int pos)
{
    if(l==tree[pos].l&&r==tree[pos].r)
        return tree[pos].msum;
    int mid=tree[pos].mid();
    if(r<=mid)
        return query(l,r,lson);
    else if(l>mid)
        return query(l,r,rson);
    else
    {
        int res=0;
   