#include<stdio.h>
 int judge(int n)//返回真约数的和
 {
     int count = 0;
     int i;
     for(i = 1;i < n; i++)
     {
         if (n % i == 0)//是真约数就累加
         {
             count += i;
         }
     }
     return count;
 }
 int main()
 {
     int t;
     int n,m;
     scanf("%d",&t);
     while(t--)
     {
         scanf("%d%d",&n,&m);
         if (judge(n) == m && judge(m) == n)//同时满足就是亲和数。
         {
             puts("YES");
         }
         else
         {
             puts("NO");
         }
     }
     return 0;
 }