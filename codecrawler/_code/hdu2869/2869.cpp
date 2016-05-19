#include <iostream>
 #include <cmath>
 #include <cstring>
 #include <cstdio>
 #include <string>
 #include <stdlib.h>
 #include <algorithm>
 using namespace std;
 typedef long long LL;
 const LL Mod= 1e9+7;
 int N, M, tot; 
 int p[100], a[1000];
 void getp( )
 {
     p[0]=2;
     for( int i=3; i<40; i+=2 ){
         if( !a[i] ){
             for( int j=i+i; j<1000; j+=i )
                 a[j]=1;
         }
     }
     for( int j=3; j<1000; j+=2 )
         if( !a[j] )
             p[++tot]=j;
 }
 int AC( int x )
 {
     int ans=0; 
     for( int i=0; p[i]&&p[i]<=x; ++ i ){
         while( x%p[i]==0 ){
             ans++; 
             x/=p[i]; 
         }
     } 
     return ans;
 }
 int main( )
 {
     getp();
     while( scanf("%d%d", &N,&M)==2 ){
         if( AC( N )<=AC(M) )puts( "Lose" );
         else puts( "Win" );
     } 
     return 0;
 }