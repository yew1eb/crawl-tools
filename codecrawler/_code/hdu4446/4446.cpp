#include <iostream>
#include <cstdio>
#include <cstring>
#define ls (t<<1)
#define rs (t<<1|1)
#define midt (tr[t].l+tr[t].r>>1)
using namespace std;
const int maxn=1e5+9;
const int inf=1111111;
int ans[maxn<<1],que[maxn<<1];
int a[maxn];

struct
{
    int l,r,min,lazy,id;
}tr[maxn<<2];

void pushdown(int t)
{
    if(tr[t].lazy)
    {
        tr[ls].min+=tr[t].lazy;
        tr[rs].min+=tr[t].lazy;
        tr[ls].lazy+=tr[t].lazy;
        tr[rs].lazy+=tr[t].lazy;
        tr[t].lazy=0;
    }
}


void maketree(int t,int l,int r)
{
    tr[t].l=l;
    tr[t].r=r;
    tr[t].lazy=0;
    if(l==r)
    {
        tr[t].min=a[l];
        tr[t].id=l;
        return ;
    }
    int mid=midt;
    maketree(ls,l,mid);
    maketree(rs,mid+1,r);
    if(tr[ls].min<=tr[rs].min)
    {
        tr[t].min=tr[ls].min;
        tr[t].id=tr[ls].id;
    }
    else
    {
        tr[t].min=tr[rs].min;
        tr[t].id=tr[rs].id;
    }
}

void modify(int t,int l,int r,int tmp)
{
    if(tr[t].l==l&&tr[t].r==r)
    {
        tr[t].min+=tmp;
        tr[t].lazy+=tmp;
        return ;
    }
    pushdown(t);
    int mid=midt;
    if(r<=mid) modify(ls,l,r,tmp);
    else if(mid+1<=l) modify(rs,l,r,tmp);
    else
    {
        modify(ls,l,mid,tmp);
        modify(rs,mid+1,r,tmp);
    }

    if(tr[ls].min<=tr[rs].min)
    {
        tr[t].min=tr[ls].min;
        tr[t].id=tr[ls].id;
    }
    else
    {
        tr[t].min=tr[rs].min;
        tr[t].id=tr[rs].id;
    }
}

int querymin()
{
//    cout<<tr[1].min<<endl;
    if(tr[1].min==0)
    return tr[1].id;
    else return -1;
}

int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
        int st=1,ed=0,lon=2*n;
        bool flage=1;
        for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
        maketree(1,1,n);
        for(int i=1;i<=n;i++)
        {
            int tmp;
            while(querymin()==-1)
            {
                if(st<=ed)
                {
                    ans[lon--]=-que[st];
                    if(que[st]+1<=n)
                    modify(1,que[st]+1,n,-1);
                    st++;
                }
                else
                {
                    flage=0;
                    break;
                }
            }
            if(!flage) break;
            tmp=querymin();
            ans[lon--]=tmp;
            que[++ed]=tmp;
            if(1<=tmp-1)
            modify(1,1,tmp-1,-1);
            modify(1,tmp,tmp,inf);
        }
        if(!flage)
        {
            printf("Impossible\n");
        }
        else
        {
            while(st<=ed)
            {
                ans[lon--]=-que[st++];
            }
            for(int i=1;i<=n*2;i++)
            printf("%d ",ans[i]);
            printf("\n");
        }
    }
    return 0;
}
