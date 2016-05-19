#include<stdio.h>
 typedef long long i64;
 int main()
 {
     int T,n;
     i64 s[150][150],f[150];
     scanf("%d",&T);
     f[0]=1;
     for(int i=1;i<=100;i++)
     {
         s[i][i]=1;s[i][1]=1;f[i]=f[i-1]*i%20090126;
     }
     for(int i=2;i<=100;i++)
     for(int j=2;j<=i;j++)
     s[i][j]=(s[i-1][j-1]+j*s[i-1][j])%20090126;
     while(T--)
     {
         i64 sum=0;
         scanf("%d",&n);
         for(int i=1;i<=n;i++)
         sum+=f[i]*s[n][i]%20090126;
         printf("%d\n",sum%20090126);
     }
     return 0;
 }