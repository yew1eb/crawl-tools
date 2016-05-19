#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define lc l,mid,2*i
#define rc mid+1,r,2*i+1
#define lson 2*i
#define rson 2*i+1
const int L = 100000+10;
int n,m;
int s[L];
struct node
{
    int l,r;
    int ls0,rs0,ms0;//å·¦ï¼å³ï¼æå¤§è¿ç»­0çä¸ªæ°
    int ls1,rs1,ms1;//å·¦ï¼å³ï¼æå¤§è¿ç»­1çä¸ªæ°
    int sum;//åºé´å1çæ»æ°
    int cover,x_or;//è¦çæ è®°ä¸å¼ææ è®°
} a[L<<2];

void XOR(int i)//åºé´å0,1ï¼ååå°±æ¯å°0,1æå³çæ°æ®äº¤æ¢å³å¯
{
    swap(a[i].ls0,a[i].ls1);
    swap(a[i].rs0,a[i].rs1);
    swap(a[i].ms0,a[i].ms1);
    a[i].sum = a[i].r-a[i].l+1-a[i].sum;//åºé´åçæ»æ°åå»ä»¥å1çæ»æ°ä¸ºåæ¢å1çæ»æ°
}
void pushup(int i)//1,0é½è¦æ´æ°
{
    if(a[i].l == a[i].r)
        return ;
    int len = a[i].r-a[i].l+1;
    a[i].ls0 = a[lson].ls0;
    a[i].rs0 = a[rson].rs0;
    if(a[lson].ls0 == a[lson].r-a[lson].l+1)
        a[i].ls0+=a[rson].ls0;
    if(a[rson].rs0 == a[rson].r-a[rson].l+1)
        a[i].rs0+=a[lson].rs0;
    a[i].ms0 = max(max(a[lson].ms0,a[rson].ms0),a[lson].rs0+a[rson].ls0);

    a[i].ls1 = a[lson].ls1;
    a[i].rs1 = a[rson].rs1;
    if(a[lson].ls1 == a[lson].r-a[lson].l+1)
        a[i].ls1+=a[rson].ls1;
    if(a[rson].rs1 == a[rson].r-a[rson].l+1)
        a[i].rs1+=a[lson].rs1;
    a[i].ms1 = max(max(a[lson].ms1,a[rson].ms1),a[lson].rs1+a[rson].ls1);

    a[i].sum = a[lson].sum+a[rson].sum;
}

void pushdown(int i)
{
    if(a[i].l == a[i].r)
        return;
    if(a[i].cover!=-1)//çåºé´æ¯è¢«0è¿æ¯1è¦çäº
    {
        int len = a[i].r-a[i].l+1;
        a[lson].cover = a[rson].cover = a[i].cover;
        a[lson].x_or = a[rson].x_or = 0;

        a[lson].ls0 = a[lson].rs0 = a[lson].ms0 = a[i].cover?0:(len+1)/2;
        a[lson].ls1 = a[lson].rs1 = a[lson].ms1 = a[i].cover?(len+1)/2:0;
        a[lson].sum = a[i].cover?(len+1)/2:0;

        a[rson].ls0 = a[rson].rs0 = a[rson].ms0 = a[i].cover?0:len/2;
        a[rson].ls1 = a[rson].rs1 = a[rson].ms1 = a[i].cover?len/2:0;
        a[rson].sum = a[i].cover?len/2:0;

        a[i].cover = -1;
    }
    if(a[i].x_or)
    {
        a[i].x_or = 0;
        a[lson].x_or^=1;
        a[rson].x_or^=1;
        XOR(lson);
        XOR(rson);
    }
}

void init(int l,int r,int i)
{
    a[i].l = l;
    a[i].r = r;
    a[i].cover = -1;
    a[i].x_or = 0;
    if(l==r)
    {
        a[i].ls0 = a[i].rs0 = a[i].ms0 = (s[l]==0);
        a[i].ls1 = a[i].rs1 = a[i].ms1 = (s[l]==1);
        a[i].cover = s[l];
        a[i].sum = s[l];
        return;
    }
    int mid = (l+r)>>1;
    init(lc);
    init(rc);
    pushup(i);
}

void insert(int l,int r,int i,int flag)
{
    pushdown(i);//è®©å­æ ç»§æ¿ç¶äº²çç¹æ§ï¼å ä¸ºè¦å¾ä¸æ´æ°
    if(l<=a[i].l && a[i].r<=r)
    {
        if(flag<2)
        {
            int len = a[i].r-a[i].l+1;
            a[i].cover = flag;
            a[i].ls0 = a[i].rs0 = a[i].ms0 = flag?0:len;
            a[i].ls1 = a[i].rs1 = a[i].ms1 = flag?len:0;
            a[i].sum = flag?len:0;
        }
        else
        {
            a[i].x_or = 1;
            XOR(i);
        }
    }
    else
    {
        if(l<=a[lson].r)
            insert(l,r,lson,flag);
        if(r>=a[rson].l)
            insert(l,r,rson,flag);
        pushup(i);
    }
}

int query(int l,int r,int i,int flag)
{
    pushdown(i);
    if(l<=a[i].l && a[i].r<=r)
    {
        if(flag == 3) return a[i].sum;
        else return a[i].ms1;
    }
    else
    {
        if(r<=a[lson].r) return query(l,r,lson,flag);
        if(l>=a[rson].l) return query(l,r,rson,flag);
        if(flag == 3)
        return query(l,a[lson].r,lson,flag)+query(a[rson].l,r,rson,flag);
        int ans1 = min(a[lson].rs1,a[lson].r-l+1)+min(a[rson].ls1,r-a[rson].l+1);
        int ans2 = max(query(l,a[lson].r,lson,flag),query(a[rson].l,r,rson,flag));
        return max(ans1,ans2);
    }
}

int main()
{
    int t,l,r,flag;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i = 1;i<=n;i++)
        scanf("%d",&s[i]);
        init(1,n,1);
        while(m--)
        {
            scanf("%d%d%d",&flag,&l,&r);
            l++;
            r++;
            if(flag<3)
            insert(l,r,1,flag);
            else
            printf("%d\n",query(l,r,1,flag));
        }
    }

    return 0;
}
