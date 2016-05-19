#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
int t,c=1;
cin>>t;
while(t--)
{
__int64 a,b;
scanf("%I64d%I64d",&a,&b);
double p=1-pow((a-1)/(1.0*a),b*1.0);
//å ä¸ºæ±çæ¯iå¨è¿bæ¬¡ä¸­"æ"åºç°çæ¦çæä»¥æ¯(1-iä»ä¸åºç°)
__int64 sum=(a+1)*a/2;
double ans=sum*p;
//ç»åä¸­åå«æä¸ªæ°çæ¬¡æ°å¯¹äºææçæ°æ¥è¯´æ¯ç¸åç
//é£ä¹EX=1*E(X1)+2*E(X2)+3*E(X3)+...+x*E(Xx)=(1+x)*x/2*(1-(1-1/x)^b)
printf("Case #%d: %.3lf\n",c++,ans);
}
return 0;
}