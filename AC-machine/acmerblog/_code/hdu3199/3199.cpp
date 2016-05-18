#include <iostream>
 #include <cstdio>
 #include <algorithm>
 #include <cstring>
 using namespace std;
 
 const int maxn=5843;
 __int64  f[maxn];
 
 __int64 Min(__int64 a, __int64 b, __int64 c,__int64 d)
 {
     a=min(a,b);
     a=min(a,c);
     a=min(a,d);
     return a;
 }
 
 int main()
 {
     f[0]=1;
     int a=0, b=0, c=0, d=0;
     for(int i=1; i<maxn; i++)  //打表
     {
         f[i]=Min(f[a]*2,f[b]*3,f[c]*5,f[d]*7);   //这里我们用到一点动态规划思想，每次只取前面记录的最小值，依次类推
         if(f[i]==f[a]*2) a++;  //2出现的次数
         if(f[i]==f[b]*3) b++;  //3出现的次数
         if(f[i]==f[c]*5) c++;  //5出现的次数
         if(f[i]==f[d]*7) d++;  //7出现的次数
     }
     int  n;
     while(~scanf("%d",&n),n)
     {
         if(n%100==11||n%100==12||n%100==13)
             printf("The %dth humble number is %I64d.\n",n,f[n-1]);
         else
         {
             if(n%10==1)
                 printf("The %dst humble number is %I64d.\n",n,f[n-1]);
             else if(n%10==2)
                 printf("The %dnd humble number is %I64d.\n",n,f[n-1]);
             else if(n%10==3)
                 printf("The %drd humble number is %I64d.\n",n,f[n-1]);
             else
                 printf("The %dth humble number is %I64d.\n",n,f[n-1]);
         }
     }
     return 0;
 }