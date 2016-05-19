http://acm.hdu.edu.cn/showproblem.php?pid=1257#include <iostream>
 #include <cstdio>
 #include <cmath>
 #include <algorithm>
 #include <cstring>
 using namespace std;
 
 const int maxn=150000;
 int  max_len[maxn];
 int  f[maxn];
 
 int main()
 {
     int  n, flag;
     while(cin >> n)
     {
         for(int i=1; i<=n; i++)
             cin >> f[i];
         int  Max=-1;
         for(int i=1; i<=n; i++)
         {
             max_len[i]=1;
             for(int j=1; j<i; j++)
             {
                 if( f[j]<f[i] && max_len[j]+1>max_len[i])
                 {
                     max_len[i]=max_len[j]+1;
                 }
             }
             if(Max<max_len[i])
             {
                 Max=max_len[i];
             }
         }
         cout << Max <<endl;
     }
     return 0;
 }