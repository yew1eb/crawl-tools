#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define LL(x) (x<<1)
#define RR(x) (x<<1|1)
#define MID(a,b) (a+((b-a)>>1))

const int N=60005;

struct node
{
    int lft,rht;
    int cnt,delay;
    int mid(){return MID(lft,rht);}

    void fun(int valu)
    {
        delay=valu;
        if(valu>0) cnt=0;
        else cnt=rht-lft+1;
    }
    void init(){ cnt=rht-lft+1; delay=0; }
};
struct Segtree
{
    node tree[N*4];
    void PushDown(int ind)
    {
        if(tree[ind].delay)
        {
            tree[LL(ind)].fun(tree[ind].delay);
            tree[RR(ind)].fun(tree[ind].delay);
            tree[ind].delay=0;
        }
    }
    void PushUp(int ind)
    {
        tree[ind].cnt=tree[LL(ind)].cnt+tree[RR(ind)].cnt;
    }
    void build(int lft,int rht,int ind)
    {
        tree[ind].lft=lft;    tree[ind].rht=rht;
        tree[ind].init();
        if(lft!=rht)
        {
            int mid=tree[ind].mid();
            build(lft,mid,LL(ind));
            build(mid+1,rht,RR(ind));
        }
    }
    void updata(int st,int ed,int valu,int ind)
    {
        int lft=tree[ind].lft,rht=tree[ind].rht;
        if(st<=lft&&rht<=ed) tree[ind].fun(valu);
        else
        {
            PushDown(ind);
            int mid=tree[ind].mid();
            if(st<=mid) updata(st,ed,valu,LL(ind));
            if(ed> mid) updata(st,ed,valu,RR(ind));
            PushUp(ind);
        }
    }
    int query(int st,int ed,int ind)
    {
        int lft=tree[ind].lft,rht=tree[ind].rht;
        if(st<=lft&&rht<=ed) return tree[ind].cnt;
        else
        {
            PushDown(ind);
            int mid=tree[ind].mid();
            int cnt1=0,cnt2=0;
            if(st<=mid) cnt1=query(st,ed,LL(ind));
            if(ed> mid) cnt2=query(st,ed,RR(ind));
            PushUp(ind);
            return cnt1+cnt2;
        }
    }
    int findPos(int st,int ed,int valu,int ind)
    {
        int lft=tree[ind].lft,rht=tree[ind].rht;
        if(lft==rht) return lft;
        else
        {
            PushDown(ind);
            int mid=tree[ind].mid(),pos;
            if(ed<=mid) pos=findPos(st,ed,valu,LL(ind));
            else if(st>mid) pos=findPos(st,ed,valu,RR(ind));
            else
            {
                if(tree[LL(ind)].cnt>=valu) pos=findPos(st,ed,valu,LL(ind));
                else pos=findPos(st,ed,valu-tree[LL(ind)].cnt,RR(ind));
            }
            PushUp(ind);
            return pos;
        }
    }
}seg;
int main()
{
    //freopen("04.in","r",stdin);

    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m; scanf("%d%d",&n,&m);

        seg.build(0,n-1,1);
        for(int i=0;i<m;i++)
        {
            int a,b,c; scanf("%d%d%d",&a,&b,&c);
            if(a==1)
            {
                int tmp=seg.query(b,n-1,1);
                b=min(b,n-1);
                if(tmp==0)
                {
                    puts("Can not put any one.");
                    continue;
                }
                else if(tmp<=c) c=tmp;

                int sum=0;
                if(b-1>=0) sum=seg.query(0,b-1,1);
                int pos1=seg.findPos(0,n-1,sum+1,1);
                int pos2=seg.findPos(0,n-1,c+sum,1);

                seg.updata(pos1,pos2,1,1);
                printf("%d %d\n",pos1,pos2);
            }
            else
            {
                b=min(b,n-1); c=min(c,n-1);
                int sum=seg.query(b,c,1);
                seg.updata(b,c,-1,1);
                printf("%d\n",c-b+1-sum);
            }
        }
        puts("");
    }
    return 0;
}