#include<cstdio>
 #include<cstring>
 #include<cmath>
 const int MAX = 10005;
 bool prim[MAX];
 void dabiao() {           //先打素数表 
     memset(prim,0,sizeof(prim));
     for(int i = 4;i<=MAX;i+=2)
     prim[i] = 1;
     int d = sqrt(MAX);
     for(int i = 2;i<d;++i) {
         if(prim[i])
         continue;
         for(int j = i*i;j<MAX;j+=i)
         prim[j] = 1;
     }
 }
 int main( ) {
     int n;
     dabiao();
     while(scanf("%d",&n)!=EOF) {
         int loc,MIN = MAX;
         for(int i = 2;i<=n/2;++i)
         if(!prim[i]&&!prim[n-i]&&(n-2*i)<MIN)
         loc = i;
         printf("%d %d\n",loc,n-loc);
     }
     return 0;
 }