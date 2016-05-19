#include<stdio.h>
#include<math.h>

__int64 C(int n,int m)                //ç»åæ°å¬å¼
{
    __int64 u,d,i;         //ç»åæ°å¬å¼ä¸­ç åå­uååæ¯d
    if(m>n/2) m=n-m;                     //é²æ­¢æº¢åº 
    for(u=d=i=1;i<=m;i++)
    {
        u=u*(n-i+1);
        d=d*i;
    }
    return u/d;
}

main()
{
    int i,M,N;
    __int64 f[14]={1,0,1},sum;
    for(i=3;i<=13;i++)
        f[i]=(i-1)*(f[i-1]+f[i-2]);
    while(scanf("%d",&N),N)
    {
        for(sum=i=0;i<=N/2;i++)
            sum+=C(N,N-i)*f[i];
        printf("%I64d\n",sum);
        
    }
}
