/*hdu 5201 The Monkey King
  é¢æï¼
  ænä¸ªè¹æï¼mä¸ªäººï¼è¦æ±åç»ç¬¬ä¸ä¸ªäººæå¤ï¼å¶ä»äººéæï¼æ±æå¤å°ç§åæ³ãæåç»ææ¨¡1000000007ã
  éå¶ï¼
  1 <= n,m <= 100000
  æè·¯ï¼
  æ¯å½æ°ï¼æ³°åå±å¼
  æä¸¾ç¬¬ä¸ä¸ªäººåå°çè¹æï¼è®¾ä¸ºuï¼
  å©ä¸çè¹æä¸ºn-uä¸ªï¼åæm-1ä»½ï¼åæï¼
  çæå½æ°ä¸ºï¼
  G(x)=(1+x+x^2+...+x^(u-1))^(m-1)
  => G(x)=((1-x^u)/(1-x))^(m-1)
  => G(x)=(1-x^u)^(m-1) / (1-x)^(m-1)
  => G(x)=(1-x^u)^(m-1) * (1-x)^(1-m)    ---ä¸å¼
  
  å¯¹äºä»»æäºé¡¹å¼ï¼å¶æ³°åå±å¼ä¸ºï¼
  (1+x)^k = 1 + kx + k(k-1)/2!*x^2 + ... + k(k-1)...(k-n+1)/n!x^k + ... 

  å¯¹"ä¸å¼"è¿è¡æ³°åå±å¼ï¼å¾å°ä¸¤ä¸ªå¤é¡¹å¼ç¸ä¹ï¼ç¶åå¯¹äºæ¯ä¸ªuï¼å°±è½éè¿æ±"ä¸å¼"çx^(n-u)çç³»æ°ï¼æ±ç»æã
 */
#include<iostream>
#include<cstdio>
using namespace std;
#define LL __int64
const int MOD=1000000007;
const int N=1000005;
LL inv(LL a,LL m){
    LL p=1,q=0,b=m,c,d;
    while(b>0){
        c=a/b;
        d=a; a=b; b=d%b;
        d=p; p=q; q=d-c*q;
    }
    return p<0?p+m:p;
}
LL fac[N],ny[N];
void predo(){
    fac[0]=1;
    ny[0]=inv(fac[0],MOD);
    for(int i=1;i<N;++i){
        fac[i]=fac[i-1]*i%MOD;
        ny[i]=inv(fac[i],MOD);
    }
}
LL C(int n,int m){
    if(m<0 || n<m) return 0;
    return fac[n]*ny[m]%MOD*ny[n-m]%MOD;
}
int main(){
    int T;
    int n,m;
    predo();
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        if(m==1){
            puts("1");
            continue;
        }
        LL ans=0;
        for(int i=1;i<=n;++i){
            LL fu=1;
            for(int j=0;j*i<=n-i && j<m;++j){
                ans=(ans+C(n-i-j*i+m-2,n-i-j*i)*C(m-1,j)*fu%MOD+MOD)%MOD;
                fu=-fu;
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}