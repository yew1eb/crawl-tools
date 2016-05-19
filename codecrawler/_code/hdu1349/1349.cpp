#include <iostream>
 #include <cstring>
 #include <string>
 #include <stack>
 #define lson l,mid,rt<<1
 #define rson mid+1,r,rt<<1|1
 #define maxn 5010
 using namespace std;

 int num[maxn*4];
 int n;
 int val[maxn];

 int query(int L,int R,int l,int r,int rt)
 {
     if(L==l&&r==R)
     {
         return num[rt];
     }
     int mid=l+r>>1;
     if(R<=mid) return query(L,R,lson);
     else if(L>mid) return query(L,R,rson);
     else
     {
         return query(L,mid,lson)+query(mid+1,R,rson);
     }
 }

 void update(int L,int R,int l,int r,int rt)
 {
     num[rt]++;
     if(L==l&&r==R)
     {
         return;
     }
     int mid=l+r>>1;
     if(R<=mid)  update(L,R,lson);
     else if(L>mid)  update(L,R,rson);
     else
     {
          update(L,mid,lson);
          update(mid+1,R,rson);
     }
 }

 int main()
 {
     freopen("input.txt","r",stdin);
     int i,j;
     while(scanf("%d",&n)!=EOF)
     {
         memset(num,0,sizeof(num));
         int ret=0;
         for(i=0;i<n;i++)
         {
             int temp;
             scanf("%d",&temp);
             val[i]=temp;
             ret+=query(temp,n-1,0,n-1,1);
             update(temp,temp,0,n-1,1);
         }
         int ans=ret;
         for(i=0;i<n;i++)
         {
             ret=ret-val[i]+(n-val[i]-1);
             ans=min(ans,ret);
         }
         printf("%d\n",ans);
     }
     return 0;
 }