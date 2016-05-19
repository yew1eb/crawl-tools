#include <iostream>
 #include <cstdio>
 
 using namespace std;
 
 int main()
 {
     int t;
     scanf("%d",&t);
     while(t--)
     {
         long long n;
         scanf("%I64d",&n);
         if(n == 1)
         {
             printf("1\n");
             continue;
         }
         long long ans = (n*(n+1))%(20090524*6);
         ans = (ans*(n+2)/6)%20090524;
         printf("%lld\n",ans);
     }
     return 0;
 }