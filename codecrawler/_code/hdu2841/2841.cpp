#include <iostream>
 #include <cstdio>
 #include <algorithm>
 #include <cstring>
 #include <vector>
 using namespace std;
 vector<int>vt;
 
 __int64  n, a, b, res;
 __int64 que[1024];
 
 void fx()
 {
     vt.clear();
     res=n;
     for(int i=2; i*i<=n; i++)
     {
         if(res%i==0)
         {
           vt.push_back(i);
           while(res%i==0)
                res/=i;
         }
     }
     if(res>1)  vt.push_back(res);
 }
 
 __int64 cal(__int64 n, __int64 t)
 {
     int num=0;
     que[num++]=1;
     for(int i=0; i<vt.size(); i++)
     {
         int ep=vt[i];
         int k=num;
         for(int j=0; j<k; j++)
             que[num++]=ep*que[j]*(-1);
     }
     __int64 sum=0;
     for(int i=0; i<num; i++)
         sum+=t/que[i];
     return sum;
 }
 
 int main()
 {
     int  T, tcase=0;
     cin >> T;
     while(T--)
     {
         cin >> a >> b >> n;
         fx();
         __int64 ans=cal(n,b)-cal(n,a-1);
         printf("Case #%d: %I64d\n",++tcase,ans);
     }
     return 0;
 }