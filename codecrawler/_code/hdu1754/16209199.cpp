#include<iostream>
#include<cstdio>
#include<cstring>
#define N 200000
using namespace std;
struct node
{
    int l,r,max;
    int mid()
    {
        return (l+r)>>1;
    }
};
node tree[N*3];
void buildtree(int l,int r,int pos)
{
    tree[pos].l=l;
    tree[pos].r=r;
    if(l==r)
    {
        scanf("%d",&tree[pos].max);
        return ;
    }
    buildtree(l,tree[pos].mid(),pos<<1);
    buildtree(tree[pos].mid()+1,r,(pos<<1)+1);
    tree[pos].max=tree[pos*2].max;
    if(tree[pos*2+1].max>tree[pos].max)
        tree[pos].max=tree[pos*2+1].max;
}
inline int max1(int a,int b)
{
    return a>b?a:b;
}
int query(int l,int r,int pos)
{
    if(tree[pos].l==l&&tree[pos].r==r)
    {
        return tree[pos].max;
    }
    else if(r<=tree[pos].mid())
    {
        return query(l,r,pos<<1);
    }
    else if(l>=tree[pos].mid()+1)
    {
        return query(l,r,(pos<<1)+1);
    }
    else
    {
        return max1(query(l,tree[pos].mid(),pos<<1),query(tree[pos].mid()+1,r,(pos<<1)+1));
    }
}
void update(int k,int data,int pos)
{
    if(tree[pos].l<=k&&tree[pos].r>=k)
    {
        tree[pos].max=max1(data,tree[pos].max);
        if(tree[pos].l==k&&tree[pos].r==k)
        {
            tree[pos].max=data;
            return ;
        }
        update(k,data,pos<<1);
        update(k,data,(pos<<1)+1);
    }
    return ;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        buildtree(1,n,1);
        int i;
        for(i=0;i<m;i++)
        {
            char c[2];
            int t1,t2;
            scanf("%s%d%d",c,&t1,&t2);
            if(c[0]=='Q')
            {
                printf("%d\n",query(t1,t2,1));
            }
            else if(c[0]=='U')
            {
                update(t1,t2,1);
            }
        
        }
    }
    return 0;
}