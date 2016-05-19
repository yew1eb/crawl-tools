#include<map>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
#include<bitset>
#include<climits>
#include<list>
#include<iomanip>
#include<stack>
#include<set>
using namespace std;
typedef long long ll;
/************Read**********/  
char *ch, *ch1, buf[40*1024000+5], buf1[40*1024000+5];  
  
void read(int &x)  
{  
    for (++ch; *ch <= 32; ++ch);  
    for (x = 0; '0' <= *ch; ch++)    x = x * 10 + *ch - '0';  
}  
/**************************/  
struct Tree
{
    int l,r,num,mx,flag;
    //è¿ä¸ªç»ç¹å½åç®¡æ§numä¸ªæ°ï¼è¿æ¯ç¨æ¥å¿«éæ±åç¨ç
    //mx:è¿ä¸ªç»ç¹çæå¤§å¼
    //flag:è¿ä¸ªç»ç¹çä¿®æ¹å¼ 
    ll sum;
    //sum:è¿ä¸ªç»ç¹çå 
}tree[1000000<<2];
void makeflag(int k,int flag)
{
    if(tree[k].flag!=0&&tree[k].flag<=flag)
        return;
    tree[k].flag=flag;
    tree[k].sum+=ll(tree[k].r-tree[k].l+1-tree[k].num)*flag;
    //numåæ¥æ±åçä½ç¨ï¼è¥ç®¡æ§ä¸äºè¿ä¸ªç»ç¹çæææ°ï¼åä¼å ä¸ä¿®æ¹å¼ 
    if(tree[k].num<tree[k].r-tree[k].l+1)
        tree[k].mx=flag;
    tree[k].num=tree[k].r-tree[k].l+1;
    //ä¿®æ¹å®æ¯åï¼å·²ç»ç®¡æ§äºè¿ä¸ªç»ç¹æææ° 
}
void pushdown(int k)//æ´æ°kçå¿å­ 
{
    if(tree[k].flag==0)
        return;
    makeflag(k<<1,tree[k].flag);
    makeflag(k<<1|1,tree[k].flag);    
}
void pushup(int k)//ç¨å¿å­æ´æ°k 
{
    tree[k].mx=max(tree[k<<1].mx,tree[k<<1|1].mx);
    tree[k].num=tree[k<<1].num+tree[k<<1|1].num;
    tree[k].sum=tree[k<<1].sum+tree[k<<1|1].sum;
}
void build(int l,int r,int k)
{
    tree[k].l=l;
    tree[k].r=r;
    tree[k].flag=0;
    if(l==r)
    {
        read(tree[k].flag);
        tree[k].num=1;
        tree[k].mx=tree[k].sum=tree[k].flag;
        return;
    }
    int m=l+r>>1;
    build(l,m,k<<1);
    build(m+1,r,k<<1|1);
    pushup(k);
}
void dfs(int k,int flag)
{
    if(tree[k].mx<=flag)
        return;
    if(tree[k].flag>=flag)
        tree[k].flag=0;
    if(tree[k].l==tree[k].r)
    {
        tree[k].mx=tree[k].sum=tree[k].flag;
        tree[k].num=tree[k].flag!=0;
        return;
    }
    pushdown(k);
    dfs(k<<1,flag);
    dfs(k<<1|1,flag);
    pushup(k);
}
void update(int l,int r,int flag,int k)
{
    if(tree[k].mx<=flag)
        return;
    if(l==tree[k].l&&r==tree[k].r)
    {
        dfs(k,flag);//æ´æ°è¿ä¸ªç»ç¹çåä»£ 
        makeflag(k,flag);//æ´æ°è¿ä¸ªç»ç¹ 
        return;
    }
    int m=tree[k].l+tree[k].r>>1;
    pushdown(k);
    if(r<=m)
        update(l,r,flag,k<<1);
    else if(l>m)
        update(l,r,flag,k<<1|1);
    else
    {
        update(l,m,flag,k<<1);
        update(m+1,r,flag,k<<1|1);
    }
    pushup(k);
}
Tree seek(int l,int r,int k)
{
    if(l==tree[k].l&&r==tree[k].r)
        return tree[k];
    int m=tree[k].l+tree[k].r>>1;
    pushdown(k);
    if(r<=m)
        return seek(l,r,k<<1);
    if(l>m)
        return seek(l,r,k<<1|1);
    Tree t1=seek(l,m,k<<1);
    Tree t2=seek(m+1,r,k<<1|1);
    t1.mx=max(t1.mx,t2.mx);
    t1.sum+=t2.sum;
    return t1;
}
int main()
{
    ch = buf - 1;  
    ch1 = buf1 - 1;  
    fread(buf, 1, 1000 * 35 * 1024, stdin);  
    int T;
    read(T);
    while(T--)
    {
        int n,m;
        read(n);read(m);
        build(1,n,1);
        while(m--)
        {
            int x,l,r;
            read(x);read(l);read(r);
            if(x==0)
            {
                read(x);
                update(l,r,x,1);
            }
            else
            {
                if(x==1)
                    printf("%d\n",seek(l,r,1).mx);
                else
                    printf("%I64d\n",seek(l,r,1).sum);
            }
        }
    }
}