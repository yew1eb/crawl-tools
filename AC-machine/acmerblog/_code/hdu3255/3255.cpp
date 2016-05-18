#include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <algorithm>
 using namespace std;
 
 #define lson l,mid,ID<<1
 #define rson mid+1,r,ID<<1|1
 const int maxn=150101;
 typedef long long lld;
 int flag[maxn];
 lld sum[maxn];
 int X[maxn], Z[maxn];
 
 struct Node   ///这题快把我整哭了
 {
     int lx, rx, y, z, s;
     Node(){}
     Node(int lx_, int rx_ , int y_, int z_, int s_)
     {
         lx=lx_, rx=rx_, y=y_, z=z_, s=s_;
     }
     bool operator<(const Node &S) const
     {
         if(y==S.y) return s>S.s;
         else return y<S.y;
     }
 }line[maxn], tmp[maxn];
 
 
 int find(int x, int M)
 {
     int l,r,m;
     l=1;
     r=M;
     while(l<=r)
     {
         m=(l+r)>>1;
         if(X[m]==x)
             return m;
         if(X[m]<x)
             l=m+1;
         else
             r=m-1;
     }
 }
 void Push_up(int ID,int l,int r)
 {
     if(flag[ID])sum[ID]=X[r+1]-X[l];
     else if(l==r)sum[ID]=0;
     else sum[ID]=sum[ID<<1]+sum[ID<<1|1];
 }
 void Update(int x,int y,int z,int l,int r,int ID)
 {
     int mid;
     if(x<=l&&r<=y)
     {
         flag[ID]+=z;
         Push_up(ID,l,r);
         return ;
     }
     mid=(l+r)>>1;
     if(x<=mid)
         Update(x,y,z,lson);
     if(y>mid)
         Update(x,y,z,rson);
     Push_up(ID,l,r);
 }
 
 int main()
 {
     int n, m, T, tcase=0;
     cin >> T;
     while(T--)
     {
         cin >> n >> m;
         Z[0]=0;
         for(int i=1; i<=m; i++)
             cin >> Z[i];
         int num=0;
         for(int i=0; i<n; i++)
         {
             int x1, x2, y1, y2, id;
             scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&id);
             line[++num]=Node(x1,x2,y1,Z[id],1);
             X[num]=x1;
             line[++num]=Node(x1,x2,y2,Z[id],-1);
             X[num]=x2;
         }
         sort(Z,Z+m+1);
         sort(X+1,X+num+1);
         sort(line+1,line+num+1);
         int ep=1;
         for(int i=2; i<=num; i++)
             if(X[i]!=X[ep]) X[++ep]=X[i];
         lld ans=0;
         for(int i=0; i<m; i++)
         {
             memset(sum,0,sizeof(sum));
             memset(flag,0,sizeof(flag));
             lld tp=0, cnt=0;
             for(int j=1; j<=num; j++)
                if(line[j].z>Z[i]) tmp[++cnt]=line[j];
             for(int j=1; j<cnt; j++)
             {
                 int l=find(tmp[j].lx,ep);
                 int r=find(tmp[j].rx,ep)-1;
                 Update(l,r,tmp[j].s,1,ep-1,1);
                 tp+=sum[1]*(lld)(tmp[j+1].y-tmp[j].y);
             }
             ans+=tp*(lld)(Z[i+1]-Z[i]);
         }
         printf("Case %d: %I64d\n",++tcase,ans);
     }
     return 0;
 }