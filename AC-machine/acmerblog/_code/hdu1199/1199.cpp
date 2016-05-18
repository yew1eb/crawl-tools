#include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <algorithm>
 using namespace std;
 
 #define lz 2*u,l,mid
 #define rz 2*u+1,mid,r   ///注意:这里是点化为线段（左闭右开）
 const int maxn=5555;
 const int oo=0x3fffffff;
 int flag[4*maxn], color[maxn];
 int X[maxn];
 
 struct Node
 {
     int lx, rx, s;
     Node(){}
     Node(int lx_, int rx_, int s_)
     {
         lx=lx_, rx=rx_, s=s_;
     }
 }line[maxn];
 
 void push_down(int u, int l, int r)
 {
     if(flag[u]==-1) return ;
     else
     {
         flag[2*u]=flag[2*u+1]=flag[u];
         flag[u]=-1;
     }
 }
 
 void Update(int u, int l, int r, int tl, int tr, int c)
 {
     if(tl>=tr) return ; ///这里要注意了
     if(tl<=l&&r<=tr)
     {
         flag[u]=c;
         return ;
     }
     push_down(u,l,r);
     int mid=(l+r)>>1;
     if(tr<=mid) Update(lz,tl,tr,c);
     else if(tl>mid) Update(rz,tl,tr,c);
     else
     {
         Update(lz,tl,mid,c);
         Update(rz,mid,tr,c);
     }
 }
 
 void Query(int u, int l, int r)
 {
     if(l>=r) return ; ///！！！
     if(flag[u]!=-1)
     {
         for(int i=l; i<r; i++) color[i]=flag[u];  ///右端点不标记
         return ;
     }
     push_down(u,l,r);
     int mid=(l+r)>>1;
     Query(lz);
     Query(rz);
 }
 
 int find(int tmp, int n)
 {
     int l=1, r=n, mid;
     while(l<=r)
     {
         mid=(l+r)>>1;
         if(X[mid]==tmp) return mid;
         else if(X[mid]<tmp) l=mid+1;
         else r=mid-1;
     }
 }
 
 int main()
 {
     int n, x, y, c;
     char ch[3];
     while(~scanf(“%d”,&n))
     {
         int num=0;
         for(int i=0; i<n; i++)
         {
             scanf(“%d%d%s”,&x,&y,ch);
             if(*ch==’w') c=1;
             else c=0;
             line[i]=Node(x,y+1,c);
             X[++num]=x;
             X[++num]=y+1;
         }
         sort(X+1,X+num+1);
         int ep=1;
         for(int i=2; i<=num; i++)
             if(X[ep]!=X[i]) X[++ep]=X[i];
         memset(color,0,sizeof(color));
         memset(flag,-1,sizeof(flag));
         for(int i=0; i<n; i++)
         {
             int lx=find(line[i].lx,ep);
             int rx=find(line[i].rx,ep);
             Update(1,1,ep+1,lx,rx,line[i].s);
         }
         Query(1,1,ep+1);
         int s=0, d=0, ts, td;
         for(int i=1; i<=ep; i++)
         {
               if(color[i]!=1) continue;
               ts=X[i];
               while(color[i]==1) i++;
               if(i>ep) break;
               td=X[i];
               if(td-ts>d-s)
               {
                   s=ts;
                   d=td;
               }
         }
         if(s==d) puts(“Oh, my god”);
         else printf(“%d %d\n”,s, d-1);
     }
     return 0;
 }