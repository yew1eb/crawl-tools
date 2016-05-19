#include<stdio.h>
 #define maxn 5010
 #define lson l,m,rt << 1
 #define rson m+1,r,rt << 1 | 1
 int tree[maxn<<2],x[maxn];
 int min(int a,int b)
 {
     return a<b?a:b;
 }
 void PushUP(int rt)
 {
     tree[rt]=tree[rt<<1]+tree[rt<<1|1];
 }
 void build(int l,int r,int rt)
 {
     tree[rt]=0;
     if(l==r)
         return ;
     int m=(l+r)>>1;
     build(lson);
     build(rson);
 }
 int query(int L,int R,int l,int r,int rt)
 {
     if(L<=l&&R>=r)
         return tree[rt];
     int m=(l+r)>>1;
     int ret=0;
     if(L<=m)
         ret+=query(L,R,lson);
     if(R>m)
         ret+=query(L,R,rson);
     return ret;
 }
 void update(int p,int l,int r,int rt)
 {
     if(l==r)
     {
         tree[rt]++;
         return ;
     }
     int m=(l+r)>>1;
     if(p<=m)
         update(p,lson);
     else
         update(p,rson);
     PushUP(rt);
 }
 int main()
 {
     int i,n,sum;
     while(scanf("%d",&n)!=EOF)
     {
         build(0,n-1,1);
         sum=0;
         for(i=0;i<n;i++)
         {
             scanf("%d",&x[i]);
             sum+=query(x[i],n-1,0,n-1,1);
             update(x[i],0,n-1,1);
         }
         int ret=sum;
         for(i=0;i<n;i++)
         {
             sum+=n-x[i]-1-x[i];
             ret=min(ret,sum);
         }
         printf("%d\n",ret);
     }
     return 0;
 }