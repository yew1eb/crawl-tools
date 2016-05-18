#include <stdio.h>
 #include <algorithm>
 using namespace std;
 #include <iostream>
 
 __int64 gcd(__int64 x1,__int64 x2){
     return x2 ? gcd(x2,x1%x2) : x1;
 }
 __int64 lcm(__int64 x1,__int64 x2){
     return x1 / gcd(x1,x2) * x2;
 }
 int getl(__int64 x){
     int cnt = 0;
     while(x>0){
         cnt++;x/=10;
     }
     return cnt;
 }
 void cal(int x)
 {
     int cnt = 0;
     __int64 fz=x,fm=1,tx;
     for(int i=2;i<=x;i++)
     {
         tx = lcm(fm,i);
         fz *= (tx/fm);
         fz += (tx/i*x);
         fm = tx;
         if(fz > fm) cnt+=(fz/fm) , fz %= fm;
         tx = gcd(fz,fm);
         fz /= tx;
         fm /= tx;
     }
     fz %= fm;
     //cout<<cnt<<' ' <<fz<<' '<<fm<<'\n';
     if(fz == 0) cout<<cnt<<endl;
     else
     {
         int l1 = getl(cnt),l2 = getl(fm);
         for(int i=0;i<=l1;i++) cout<<' ';
         cout<<fz<<'\n';
         cout<<cnt<<' ';
         for(int i=0;i<l2;i++) cout<<'-';
         cout<<'\n';
         for(int i=0;i<=l1;i++) cout<<' ';
         cout<<fm<<'\n';
     }
 }
 
 int main()
 {
     int n;
     while(cin>>n)
     {
         if(n==1) cout<<"1\n";
         else cal(n);
     }
     return 0;
 }