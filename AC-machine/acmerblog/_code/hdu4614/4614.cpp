#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define N 50100
#define lson (pos<<1)
#define rson (pos<<1|1)
struct node
{
    int l,r,tag,sum;
} tree[N*4];

void build(int pos, int l, int r)
{
    tree[pos].l=l;
    tree[pos].r=r;
    tree[pos].tag=0;
    tree[pos].sum=r-l+1;
    if(l==r)return ;
    int mid=(l+r)/2;
    build(lson,l,mid);
    build(rson,mid+1,r);
}
void pushdown(int pos)
{
    if(tree[pos].tag)
    {
        if(tree[pos].tag==2)
        {
            tree[lson].sum=(tree[lson].r-tree[lson].l+1);
            tree[lson].tag=2;
            tree[rson].sum=(tree[rson].r-tree[rson].l+1);
            tree[rson].tag=2;
            tree[pos].tag=0;
        }
        else
        {
            tree[lson].sum=0;
            tree[lson].tag=1;
            tree[rson].sum=0;
            tree[rson].tag=1;
            tree[pos].tag=0;
        }
    }
}
void pushup(int pos)
{
    tree[pos].sum=tree[lson].sum+tree[rson].sum;
}
void update(int pos, int L, int R, int v)
{
    if(L<=tree[pos].l&&tree[pos].r<=R)
    {
        if(v==1)
        {
            tree[pos].tag=1;
            tree[pos].sum=0;
        }
        else if(v==2)
        {
            tree[pos].tag=2;
            tree[pos].sum=tree[pos].r-tree[pos].l+1;
        }
        return ;
    }
    pushdown(pos);
    int mid=(tree[pos].l+tree[pos].r)/2;
    if(L<=mid)update(lson,L,R,v);
    if(mid<R)update(rson,L,R,v);
    pushup(pos);
}

int query(int pos, int L, int R)
{
    if(L<=tree[pos].l&&tree[pos].r<=R)
    {
        return tree[pos].sum;
    }
    pushdown(pos);
    int mid=(tree[pos].l+tree[pos].r)/2;
    int ans=0;
    if(L<=mid)ans+=query(lson,L,R);
    if(mid<R)ans+=query(rson,L,R);
    return ans;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        build(1,1,n);
        for(int i = 0; i < m; i++)
        {
            int id;
            scanf("%d",&id);
            if(id==1)
            {
                int A,B;
                int s, w;
                scanf("%d%d",&s,&w);
                s++;
                int sum=query(1,s,n);
                sum=min(w,sum);
                if(sum==0)
                {
                    printf("Can not put any one.\n");
                    continue;
                }
                int l=s,r=n;
                if(sum==1)
                {
                    if(query(1,l,l))
                    {
                        A=l;
                        B=l;
                        printf("%d %d\n",A-1,B-1);
                        update(1,A,B,1);
                        continue;
                    }
                }

                sum--;
                //printf("sum=%d\n",sum);
                while(l+1<r)
                {
                    int mid=(l+r)/2;
                    int tmp=query(1,s,mid);
                    //printf("mid=%d tmp=%d l=%d r=%d\n",mid,tmp,l,r);
                    if(tmp>sum)r=mid;
                    else l=mid;
                }
                B=r;
                l=s;
                r=B;
                if(sum==0)
                {
                    if(query(1,r,r))
                    {
                        A=r;
                        B=r;
                        printf("%d %d\n",A-1,B-1);
                        update(1,A,B,1);
                        continue;
                    }
                }
                while(l+1<r)
                {
                    int mid=(l+r)/2;
                    int tmp=query(1,mid,B);
                    if(tmp>sum)l=mid;
                    else r=mid;
                }
                A=l;
                printf("%d %d\n",A-1,B-1);
                update(1,A,B,1);
            }
            else if(id==2)
            {
                int a,b;
                scanf("%d%d",&a,&b);
                a++;
                b++;
                int hehe=b-a+1-query(1,a,b);
                printf("%d\n",hehe);
                if(hehe!=0)
                    update(1,a,b,2);
            }

        }
        printf("\n");
    }
    return 0;
}
/*2
10 5
1 0 1
1 0 2
1 0 1
*/
