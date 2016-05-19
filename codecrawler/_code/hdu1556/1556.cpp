#include <stdio.h>
 #include <string.h>
 #define lowbit(x) ((x)&(-x))
 int a[100005],n;
 void update(int x,int y)
 {
     while(x <= n)
     {
         a[x] += y;
         x += lowbit(x);
     }
 }
 int getsum(int x)
 {
     int ans = 0;
     while(x > 0)
     {
         ans += a[x];
         x -= lowbit(x);
     }
     return ans;
 }
 int main()
 {
     int i,j;
     while(scanf("%d",&n) == 1 && n)
     {
         memset(a,0,sizeof(a));
         for(j = 1;j <= n;j ++)
         {
             int a,b;
             scanf("%d %d",&a,&b);
             update(a,1);
             update(b+1,-1);
         }
         printf("%d",getsum(1));
         for(i = 2;i <= n;i ++)
             printf(" %d",getsum(i));
         puts("");
     }
     return 0;
 }