#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
#define lch(i) ((i)<<1)
#define rch(i) ((i)<<1|1)
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define N 50010

struct node
{
    int l,r;
    int mark;
    int tlen,llen,rlen;
    int mid(){
        return (l+r)>>1;
    }
    int cal_len(){
        return r-l+1;
    }
    void updata_len(){
        tlen = llen = rlen = (mark ? 0 : cal_len());
    }
}t[4*N];

void build(int l , int r , int rt)
{
    t[rt].l = l; t[rt].r = r; 
    t[rt].mark = 0;
    t[rt].tlen = t[rt].llen = t[rt].rlen = t[rt].cal_len();
    if(l == r) return ;
    int mid = t[rt].mid();
    build(l , mid , lch(rt));
    build(mid+1 , r , rch(rt));
    return ;
}

void updata(int pos ,int val ,int rt)
{
    if(t[rt].l == t[rt].r)
    {
        t[rt].mark = val;
        t[rt].updata_len();
        return ;
    } 
    if(t[rt].mark != -1)
    {
        t[lch(rt)].mark = t[rch(rt)].mark = t[rt].mark;
        t[rt].mark = -1;
        t[lch(rt)].updata_len();
        t[rch(rt)].updata_len();
    }
    int mid = t[rt].mid();
    if(pos <= mid) //在左半
        updata(pos , val , lch(rt));
    else //在右半
        updata(pos , val , rch(rt));

    int temp = max(t[lch(rt)].tlen , t[rch(rt)].tlen);
    t[rt].tlen = max(temp , t[lch(rt)].rlen + t[rch(rt)].llen);
    t[rt].llen = t[lch(rt)].llen;
    t[rt].rlen = t[rch(rt)].rlen;
    if(t[lch(rt)].tlen == t[lch(rt)].cal_len())
        t[rt].llen += t[rch(rt)].llen;
    if(t[rch(rt)].tlen == t[rch(rt)].cal_len())
        t[rt].rlen += t[lch(rt)].rlen;
    return ;
}

int query(int pos , int rt)
{
    if(t[rt].l == t[rt].r || t[rt].tlen == 0 || t[rt].tlen == t[rt].cal_len())
        return t[rt].tlen;
    //上面的部分可以改变一下写法，看看时间会不会有明显的变化
    
    if(t[rt].mark != -1)
    {
        t[lch(rt)].mark = t[rch(rt)].mark = t[rt].mark;
        t[rt].mark = -1;
        t[lch(rt)].updata_len();
        t[rch(rt)].updata_len();
    }
    int mid = t[rt].mid();
    if(pos <= mid) //查询的点在左边 
    {
        int index = mid-t[lch(rt)].rlen+1;
        if(index <= pos) //包含在内
            return query(pos , lch(rt)) + query(mid+1 , rch(rt));
        else
            return query(pos , lch(rt));
    }
    else
    {
        int index = mid+t[rch(rt)].llen;
        if(pos <= index) //包含在内
            return query(mid , lch(rt)) + query(pos , rch(rt));
        else
            return query(pos , rch(rt));
    }
}

int main()
{
    int n,m;
    stack<int>sta;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        build(1,n,1);
        while(!sta.empty()) sta.pop();
        while(m--)
        {
            char op[5];
            int pos , len;
            scanf("%s",op);
            if(op[0] == 'R')
            {
                if(sta.empty()) continue;
                int pos = sta.top();
                sta.pop();
                updata(pos , 0 , 1);
            }
            else if(op[0] == 'D')
            {
                scanf("%d",&pos);
                sta.push(pos);
                updata(pos , 1 , 1);
            }
            else
            {
                scanf("%d",&pos);
                len = query(pos,1);
                printf("%d\n",len);
            }
        }
    }
    return 0;

}