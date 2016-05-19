#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <cctype>
using namespace std;

#define lc (c<<1)
#define rc (c<<1|1)
const int maxn=5e4+10;
struct node{
    int l,r,rmax,sum;
}e[maxn*4];
struct op{
    char ch[10];
    int w,t;
}f[maxn];
int val[maxn*4],discrete[maxn],tt,len;
int get_id(int x)
{
    return lower_bound(discrete,discrete+tt,x)-discrete;
}
void build(int a,int b,int c)
{
    e[c].l=a;e[c].r=b;
    e[c].rmax=e[c].sum=0;
    if(a==b)return ;
    int mid=(a+b)>>1;
    build(a,mid,lc);
    build(mid+1,b,rc);
}
void update(int a,int b,int c,int d)
{
    if(e[c].l==a&&e[c].r==b)
    {
        val[c]=d;
        if(d>=0)
        {
            e[c].sum=e[c].rmax=1;
        }
        else
        {
            e[c].sum=-1;
            e[c].rmax=0;
        }
        return ;
    }
    int mid=(e[c].l+e[c].r)>>1;
    if(b<=mid)update(a,b,lc,d);
    else if(a>mid)update(a,b,rc,d);
    e[c].sum=e[lc].sum+e[rc].sum;
    e[c].rmax=max(e[rc].rmax,e[rc].sum+e[lc].rmax);
}
int query(int a,int c)
{
    if(e[c].r<=a)
    {
        int s=len+e[c].rmax;
        if(s<=0)
        {
            len+=e[c].sum;
            return -1;
        }
    }
    if(e[c].l==e[c].r)return val[c];
    int mid=(e[c].l+e[c].r)>>1;
    if(mid<a)
    {
        int ans=query(a,rc);
        if(ans!=-1)return ans;
    }
    return query(a,lc);
}
void readchar(char *s)
{
    int i=0;
    char ch=getchar();
    while(!(ch<='z'&&ch>='a'))ch=getchar();
    while(ch<='z'&&ch>='a')
    {
        s[i++]=ch;
        ch=getchar();
    }
    s[i]='\0';
}
int readint()
{
    int x=0;
    char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x;
}
int main()
{
    //freopen("D:\\1008.in","r",stdin);
    //freopen("C:\\Documents and Settings\\Administrator\\æ¡é¢\\false.out","w",stdout);
    int n,tot=0;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)break;
        int i,j,k;
        tt=0;
        for(i=0;i<n;i++)
        {
            //scanf("%s",f[i].ch);
            readchar(f[i].ch);
            if(f[i].ch[1]=='u')
            {
                //scanf("%d%d",&f[i].w,&f[i].t);
                f[i].w=readint();
                f[i].t=readint();
            }
            else //scanf("%d",&f[i].t);
                f[i].t=readint();
            if(f[i].ch[1]!='e')discrete[tt++]=f[i].t;
        }
        sort(discrete,discrete+tt);
        build(0,tt-1,1);
        printf("Case #%d:\n",++tot);
        for(i=0;i<n;i++)
        {
            int id=get_id(f[i].t);
            if(f[i].ch[1]=='o')update(id,id,1,-1);
            else if(f[i].ch[1]=='u')update(id,id,1,f[i].w);
            else
            {
                if(id==0)printf("-1\n");
                else
                {
                    len=0;
                    printf("%d\n",query(id-1,1));
                }
            }
        }
    }
    return 0;
}
