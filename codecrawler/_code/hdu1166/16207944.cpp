#include<iostream>
#include<cstdio>
#include<cstring>
#define N 50000
using namespace std;
struct node
{
    int l,r;
    long long sum;
};
node tree[N*3];
void buildtree(int l,int r,int pos)
{
    tree[pos].l=l;
    tree[pos].r=r;
    if(l==r)
    {
        scanf("%I64d",&tree[pos].sum);
        return ;
    }
    int mid=(l+r)>>1;
    buildtree(l,mid,pos*2);
    buildtree(mid+1,r,pos*2+1);
    tree[pos].sum=tree[pos*2].sum+tree[pos*2+1].sum;
}
long long query(int l,int r,int pos)
{
    if(l==tree[pos].l&&r==tree[pos].r)
        return tree[pos].sum;
    else if(r<=(tree[pos].l+tree[pos].r)/2)
        return query(l,r,pos<<1);
    else if(l>=(tree[pos].l+tree[pos].r)/2+1)
        return query(l,r,(pos<<1)+1);
    else
        return query(l,tree[pos*2].r,pos*2)+query(tree[pos*2+1].l,r,pos*2+1);
}
void update(int pos,int k,int add)
{
    if(k>=tree[pos].l&&k<=tree[pos].r)
    {
        tree[pos].sum+=add;
        if(tree[pos].l==tree[pos].r)
            return ;
        update(pos*2,k,add);
        update(pos*2+1,k,add);
    }
    return ;
}
int main()
{
    int t;
    scanf("%d",&t);
    int cas=1;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int i;
        printf("Case %d:\n",cas++);
        buildtree(1,n,1);
        while(1)
        {
            char str[20];
            scanf("%s",str);
            if(str[0]=='E')
                break;
            else if(str[0]=='Q')
            {
                int t1,t2;
                scanf("%d%d",&t1,&t2);
                printf("%I64d\n",query(t1,t2,1));
            }
            else if(str[0]=='S')
            {
                int t1,t2;
                scanf("%d%d",&t1,&t2);
                update(1,t1,-t2);
            }
            else if(str[0]=='A')
            {
                int t1,t2;
                scanf("%d%d",&t1,&t2);
                update(1,t1,t2);
            }
        }
    }
}