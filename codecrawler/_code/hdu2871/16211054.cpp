#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define lson 2*i
#define rson 2*i+1
#define lc l,mid,2*i
#define rc mid+1,r,2*i+1
const int L = 50000+10;

struct node
{
    int start,end;
    int ls,rs,ms;
    int lazy,cnt,cover;
} a[L<<2];

void pushdown(int mid,int L,int R,int i)
{
    if(a[i].lazy!=-1)
    {
        a[lson].lazy = a[rson].lazy = a[i].lazy;
        a[lson].ms = a[lson].ls = a[lson].rs = (mid-L+1)*a[i].lazy;
        a[rson].ms = a[rson].ls = a[rson].rs = (R-mid)*a[i].lazy;
        a[lson].start = a[rson].start = a[i].start;
        a[lson].end = a[rson].end = a[i].end;
        a[i].lazy = -1;
    }
}

void pushup(int mid,int L,int R,int i)
{
    a[i].ls = a[lson].ls;
    a[i].rs = a[rson].rs;
    if(a[i].ls == mid-L+1)
        a[i].ls+=a[rson].ls;
    if(a[i].rs == R-mid)
        a[i].rs+=a[lson].rs;
    a[i].ms = max(max(a[lson].ms,a[rson].ms),a[lson].rs+a[rson].ls);
}

void insert(int L,int R,int t,int l,int r,int i)//tä¸º0éæ¾è¯¥åºé´ï¼ä¸º1ååéåºé´
{
    if(L<=l && r<=R)
    {
        a[i].lazy = t;
        a[i].ls = a[i].rs = a[i].ms = t*(r-l+1);
        if(t)
            a[i].start = a[i].end = -1;
        else
        {
            a[i].start = L;
            a[i].end = R;
        }
    }
    else
    {
        int mid = (l+r)>>1;
        pushdown(mid,l,r,i);
        if(L<=mid)
            insert(L,R,t,lc);
        if(R>mid)
            insert(L,R,t,rc);
        pushup(mid,l,r,i);
    }
}

void Reset(int n)
{
    insert(1,n,1,1,n,1);
    a[1].cover = 1;
    a[1].cnt = 0;
}

int New(int x,int l,int r,int i)
{
    if(l == r)
        return l;
    int mid = (l+r)>>1;
    pushdown(mid,l,r,i);
    if(a[lson].ms>=x)
        return New(x,lc);
    else if(a[lson].rs+a[rson].ls>=x)
        return mid-a[lson].rs+1;
    else
        return New(x,rc);
}

int Free(int x,int l,int r,int i)
{
    if(l == r)
        return i;
    int mid = (l+r)>>1;
    pushdown(mid,l,r,i);
    if(x<=mid)
        return Free(x,lc);
    else
        return Free(x,rc);
}

void countup(int i)
{
    a[i].cnt = a[lson].cnt+a[rson].cnt;
}

void countdown(int i)
{
    if(a[i].cover)
    {
        a[lson].cnt = a[rson].cnt = 0;
        a[lson].cover = a[rson].cover = 1;
        a[i].cover = 0;
    }
}

int Get(int x,int l,int r,int i)
{
    if(l == r)
        return l;
    else
    {
        int mid = (l+r)>>1;
        countdown(i);
        if(a[lson].cnt>=x)
            return Get(x,lc);
        else
            return Get(x-a[lson].cnt,rc);
    }
}

void count(int x,int t,int l,int r,int i)
{
    if(l == r)
        a[i].cnt = t;
    else
    {
        int mid = (l+r)>>1;
        countdown(i);
        if(x<=mid)
            count(x,t,lc);
        else
            count(x,t,rc);
        countup(i);
    }
}

int main()
{
    char s[20];
    int n,m,x,ans;
    while(~scanf("%d%d",&n,&m))
    {
        Reset(n);//åå§ç¶ææ¢æ¯åå­å¨é¨éæ¾çç¶æ
        while(m--)
        {
            scanf(" %s",s);
            if(!strcmp(s,"Reset"))
            {
                Reset(n);
                printf("Reset Now\n");
            }
            else if(!strcmp(s,"New"))
            {
                scanf("%d",&x);
                if(a[1].ms>=x)
                {
                    ans = New(x,1,n,1);
                    printf("New at %d\n",ans);
                    count(ans,1,1,n,1);
                    insert(ans,ans+x-1,0,1,n,1);
                }
                else
                    printf("Reject New\n");
            }
            else if(!strcmp(s,"Free"))
            {
                scanf("%d",&x);
                ans = Free(x,1,n,1);
                if(a[ans].start<0)
                    printf("Reject Free\n");
                else
                {
                    printf("Free from %d to %d\n",a[ans].start,a[ans].end);
                    count(a[ans].start,0,1,n,1);
                    insert(a[ans].start,a[ans].end,1,1,n,1);
                }
            }
            else
            {
                scanf("%d",&x);
                if(x>a[1].cnt)
                    printf("Reject Get\n");
                else
                    printf("Get at %d\n",Get(x,1,n,1));
            }
        }
        printf("\n");
    }

    return 0;
}
