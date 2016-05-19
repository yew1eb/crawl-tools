#include <iostream>
 #include <string.h>
 #include <string>
 #include <fstream>
 #include <algorithm>
 #include <stdio.h>
 #include <vector>
 #include <queue>
 #include <set>
 #include <cmath>
 using namespace std;
 const double eps = 1e-8;
 const double pi=acos(-1.0);
 const int INF=0x7fffffff;
 unsigned long long uINF = ~0LL;
 #define MAXN 1007
 #define mod 1000000007
 typedef long long LL;
 
 LL d1[33][1000],d2[33][1000];
 LL len1[33],len2[33];
 int n,k;
 void init()
 {
     len1[1]=len1[2]=1;
     len2[1]=len2[2]=2;
     for(int i=3;i<=30;i+=2)
     {
         len1[i]=len1[i+1]=len1[i-1]+2;
         len2[i]=len2[i+1]=len2[i-1]+2;
     }
 }
 //D[i,j] = (Len[i]-j+1)*D[i-1,j-1] + D[i-1,j]
 int main()
 {
     //freopen("0.in","r",stdin);
     init();
     while(scanf("%d%d",&n,&k),n+k!=0)
     {
         memset(d1,0,sizeof(d1));
         memset(d2,0,sizeof(d2));
 
         for(int i=0;i<=n;i++)
         {
             d1[i][0]=1;d2[i][0]=1;
         }
 
         for(int i=1;i<=n;i++)
         for(int j=1;j<=k;j++)
         {
             d1[i][j]=(len1[i]-j+1)*d1[i-1][j-1]+d1[i-1][j];
             if(i!=n)d2[i][j]=(len2[i]-j+1)*d2[i-1][j-1]+d2[i-1][j];
         }
 
         LL ans=0;
         for(int i=0;i<=k;i++)
         ans+=d1[n][i]*d2[n-1][k-i];
         printf("%lld\n",ans);
     }
 
     return 0;
 }