#include <iostream>
 #include <cstdio>
 #include <cstring>
 using namespace std;
 #define L(x)(x<<1)
 #define R(x)(x<<1|1)
 #define MID(x,y) ((x+y)>>1)
 const int MAX=200005;
 struct Tnode{
 int sum,left,right,max;
 }node[MAX*4];
 int num[MAX];
 void init()
 {
     memset(node,0,sizeof(node));
 }
 void Build(int t,int l,int r)
 {
     node[t].left=l;
     node[t].right=r;
     if(l+1==r)
     {
         node[t].sum=num[l];
         node[t].max=num[l];
         return ;
     }
     int mid=MID(l,r);
     Build(L(t),l,mid);
     Build(R(t),mid,r);
     node[t].max=(node[L(t)].max>node[R(t)].max)?node[L(t)].max:node[R(t)].max;
 }
 void update(int t,int l,int r,int sum)
 {
     if(node[t].left==l&&node[t].right==r)
     {
         node[t].sum=sum;
         node[t].max=sum;
         return ;
     }
     int mid=MID(node[t].left,node[t].right);
     if(l>=mid) update(R(t),l,r,sum);
     else if(r<=mid) update(L(t),l,r,sum);
     else {
         update(L(t),l,mid,sum);
         update(R(t),mid,r,sum);
     }
     //if(node[t].max<sum)node[t].max=sum;
     node[t].max=(node[L(t)].max>node[R(t)].max)?node[L(t)].max:node[R(t)].max;
 }
 int query(int t,int l,int r)
 {
     int gg,mm,tt;
     if( node[t].left == l && node[t].right == r )
         return node[t].max;
     int mid = MID(node[t].left,node[t].right);
     if( l >= mid )
         return query(R(t),l,r);
     else
         if( r <= mid )
             return query(L(t),l,r);
         else
         {
             gg=query(L(t),l,mid);
             mm=query(R(t),mid,r);
             if(gg>mm)tt=gg;
             else tt=mm;
             return tt;
         }
 
 }
 int main()
 {
      int ind = 1,m,n,x,y;
      char s[10];
 
     while(scanf("%d%d",&n,&m)!=EOF)
     {
         for(int i=0; i<n; i++)
             scanf("%d",&num[i]);
         init();
         Build(1,0,n+1);
 
         while(m--)
         {
             scanf("%s%d%d",s,&x,&y);
 
             if(s[0] =='U' )
                 update(1,x-1,x,y);
             else
                 printf("%d\n",query(1,x-1,y));
         }
     }
 return 0;
 }