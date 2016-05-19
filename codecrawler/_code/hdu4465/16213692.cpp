/*
ä¸¤ä¸ªç¶å­éé½è£äºnä¸ªç³æï¼ä»ç¬¬ä¸ä¸ªç¶å­æ¿çæ¦çæ¯p
å½ä½ åæ¿ç³æçæ¶åï¼åç°ç¶å­ç©ºäº
æ±è¿æ¶åå¦å¤ä¸ä¸ªç¶å­çå©ä½çç³æçæ°éçææ

è®¡ç®è¿ç¨ä¼é æä¸æº¢åä¸æº¢

ç¨logå°±ä¸ä¼äº


*/
#include<math.h>
#include<stdio.h>
double lognjie[400010];
double logC(int n,int m)
{
    return lognjie[n]-lognjie[m]-lognjie[n-m];//c(n,m)=n!/((n-m)!*m!)  log(c(n,m))=log(n!)-log(m!)-log((m-n)!)
}
int main()
{
    int i,n,index=1;
    double p,q;
    lognjie[0]=0;
    for(i=1;i<=400000;++i)
    {
        lognjie[i]=lognjie[i-1]+log(1.0*i);//log(n!)=log((n-1)!)+log(n)
    }
    while(scanf("%d%lf",&n,&p)!=EOF)
    {
        double ret=0;
        q=1-p;
        for(i=0;i<=n;++i)//ç¬¬äºä¸ªçå­éè¾¹æ¿äºiä¸ª  å¦å¤ä¸ä¸ªçå­åäºn+1æ¬¡
        {
            ret+=(n-i)*(exp(logC(n+i,i)+(n+1)*log(1.0*p)+i*log(1.0*q))+exp(logC(n+i,i)+(n+1)*log(1.0*q)+i*log(1.0*p)));
        }
        printf("Case %d: %.6lf\n",index++,ret);
    }
    return 0;
}
