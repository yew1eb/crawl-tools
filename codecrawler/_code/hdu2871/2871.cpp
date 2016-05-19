#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define lson pos<<1
#define rson pos<<1|1
using namespace std;
const int MAXN=50005;
int blocks[MAXN*2];
struct node
{
    int l,r;
    int msum,lsum,rsum;
    int lazy;
    int mid()
    {
        return (l+r)>>1;
    }
};
node tree[MAXN*4];
inline void pushup(int pos)
{
    tree[pos].msum=max(tree[lson].msum,tree[rson].msum);
    tree[pos].lsum=tree[lson].lsum;
    tree[pos].rsum=tree[rson].rsum;
    tree[pos].msum=max(tree[pos].msum,tree[lson].rsum+tree[rson].lsum);
    int l1=tree[lson].r-tree[lson].l+1;
    int l2=tree[rson].r-tree[rson].l+1;
    if(tree[lson].lsum==l1)
        tree[pos].lsum+=tree[rson].lsum;
    if(tree[rson].rsum==l2)
        tree[pos].rsum+=tree[lson].rsum;
}
inline void pushdown(int pos)
{
    if(tree[pos].lazy!=-1)
    {
        tree[lson].lazy=tree[pos].lazy;
        tree[rson].lazy=tree[pos].lazy;
        if(tree[pos].lazy==1)
        {
            tree[lson].lsum=tree[lson].rsum=tree[lson].msum=0;
            tree[rson].lsum=tree[rson].rsum=tree[rson].msum=0;
        }
        else
        {
            tree[lson].lsum=tree[lson].rsum=tree[lson].msum=
                tree[lson].r-tree[lson].l+1;
            tree[rson].lsum=tree[rson].rsum=tree[rson].msum=
                tree[rson].r-tree[rson].l+1;
        }
        tree[pos].lazy=-1;
    }
}
void build(int l,int r,int pos)
{
    tree[pos].l=l;
    tree[pos].r=r;
    if(l==r)
    {
        tree[pos].msum=1;
        tree[pos].lsum=tree[pos].rsum=1;
        tree[pos].lazy=-1;
        return ;
    }
    int mid=tree[pos].mid();
    build(l,mid,lson);
    build(mid+1,r,rson);
    pushup(pos);
    tree[pos].lazy=-1;
}
void update(int l,int r,int x,int pos)
{
    if(l==tree[pos].l&&r==tree[pos].r)
    {
        tree[pos].lazy=x;
        if(x==0)
        {
            tree[pos].lsum=tree[pos].rsum=tree[pos].msum=
                tree[pos].r-tree[pos].l+1;
        }
        else
        {
            tree[pos].lsum=tree[pos].rsum=tree[pos].msum=0;
        }
        return ;
    }
    pushdown(pos);
    int mid=tree[pos].mid();
    if(r<=mid)
        update(l,r,x,lson);
    else if(l>mid)
        update(l,r,x,rson);
    else
    {
        update(l,mid,x,lson);
        update(mid+1,r,x,rson);
    }
    pushup(pos);
}
int query(int x,int pos)
{
    if(tree[pos].msum<x)
        return 0;
    if(tree[pos].lsum>=x)
        return tree[pos].l;
    pushdown(pos);
    if(tree[lson].msum>=x)
        return query(x,lson);
    else if(tree[lson].rsum+tree[rson].lsum>=x)
        return tree[lson].r-tree[lson].rsum+1;
    else
        return query(x,rson);
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        build(1,n,1);
        char word[10];
        int i;
        int k=0;
        int ff=0;
        for(i=0;i<m;i++)
        {
            int x;
            scanf("%s",word);
            if(word[0]!='R')
                scanf("%d",&x);
            if(word[0]=='R')
            {
                update(1,n,0,1);
                printf("Reset Now\n");
                k=0;
            }
            else if(word[0]=='N')
            {
                int a=query(x,1);
                if(a==0)
                    printf("Reject New\n");
                else
                {
                    printf("New at %d\n",a);
                    update(a,a+x-1,1,1);
                    blocks[k++]=a;
                    blocks[k++]=a+x-1;
                    ff=0;

                }
            }
            else if(word[0]=='F')
            {
                if(ff==0)
                    sort(blocks,blocks+k),ff=1;
                int l=0,r=k-1;
                int res;
                while(l<=r)
                {
                    int mid=(l+r)>>1;
                    if(blocks[mid]>x)
                        r=mid-1;
                    else
                    {
                        l=mid+1;
                    }
                }
                res=l-1;
                if(res==-1)
                    printf("Reject Free\n");
                else if(blocks[res]==x)
                {
                    if(res%2==0)
                        l=res,r=res+1;
                    else
                        l=res-1,r=res;
                    printf("Free from %d to %d\n",blocks[l],blocks[r]);
                    update(blocks[l],blocks[r],0,1);
                    for(int j=r+1;j<k;j++)
                        blocks[j-2]=blocks[j];
                    k=k-2;
                }
                else
                {
                    if(res%2==0)
                    {
                        l=res,r=res+1;
                        printf("Free from %d to %d\n",blocks[l],blocks[r]);
                        update(blocks[l],blocks[r],0,1);
                        for(int j=r+1;j<k;j++)
                            blocks[j-2]=blocks[j];
                        k=k-2;
                    }
                    else
                    {
                        printf("Reject Free\n");
                    }
                }

            }
            else if(word[0]=='G')
            {
                if(ff==0)
                    sort(blocks,blocks+k),ff=1;
                if((x-1)*2>=k)
                    printf("Reject Get\n");
                else
                    printf("Get at %d\n",blocks[(x-1)*2]);
            }
        }
        printf("\n");
    }
    return 0;
}