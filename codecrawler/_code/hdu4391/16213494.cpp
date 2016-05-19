#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

#define Maxn 100005
#define lx (x<<1)
#define rx ((x<<1) | 1)
#define MID ((l + r)>>1)

//æ¢åå½æ è®°ï¼ååå½å¼
int S[Maxn<<2];
//åªæç¨
int mi[Maxn<<2],mx[Maxn<<2];
int A[Maxn];

int n,m;

void pushUp(int x)
{
   S[x] = S[lx] == S[rx] ? S[lx] : -1;
   mi[x] = min(mi[lx],mi[rx]);
   mx[x] = max(mx[lx],mx[rx]);
}
void pushDown(int l,int r,int x)
{
   if(S[x]!=-1)
   {
      S[rx] = S[lx] = S[x];
      mi[rx] = mi[lx] = S[x];
      mx[rx] = mx[lx] = S[x];
   }
}
void build(int l,int r,int x)
{
   if(l == r)
   {
      S[x] = mi[x] = mx[x] = A[l];
      return;
   }
   build(l,MID,lx);
   build(MID+1,r,rx);
   pushUp(x);
}

void update(int L,int R,int d,int l,int r,int x)
{
   if(S[x] == d) return;
   if(L<=l && r<=R)
   {
      S[x] = mi[x] = mx[x] = d;
      return;
   }
   pushDown(l,r,x);
   if(L<=MID) update(L,R,d,l,MID,lx);
   if(MID+1<=R) update(L,R,d,MID+1,r,rx);
   pushUp(x);
}
int query(int L,int R,int z,int l,int r,int x)
{
   if(L<=l && r<=R)
   {
      if(z>=mi[x] && z<=mx[x])
      {
         if(S[x]!=-1)
         {
            if(S[x] == z) return r-l+1;
            else return 0;
         }
         else return query(L,R,z,l,MID,lx) + query(L,R,z,MID+1,r,rx);
      }
      else return 0;
   }
   pushDown(l,r,x);
   int ans = 0;
   if(L<=MID) ans += query(L,R,z,l,MID,lx);
   if(MID+1<=R) ans += query(L,R,z,MID+1,r,rx);
   return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
   int op,a,b,z;
   while(scanf(" %d %d",&n,&m)!=EOF)
   {
      for(int i=1;i<=n;i++)
      {
         scanf(" %d",&A[i]);
      }
      build(1,n,1);
      for(int i=0;i<m;i++)
      {
         scanf(" %d %d %d %d",&op,&a,&b,&z);
         a++;b++;
         if(op == 1) update(a,b,z,1,n,1);
         else if(op == 2)
         {
            int ans = query(a,b,z,1,n,1);
            printf("%d\n",ans);
         }
      }
   }
   return 0;
}
