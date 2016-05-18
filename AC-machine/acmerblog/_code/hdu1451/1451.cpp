#include<stdio.h>
#include<math.h>
#define eps 1e-9
#define pi acos(-1.0)
int main()
{
 int T=0;
 double a,b,c,len,p0,p1,S,R,r;
 //len为自由线的长度；p0为原三角形的周长；p1为原三角形的半周长；
  //R为原三角形的内切圆半径；r为相似三角形的内切圆半径。 
 while(scanf("%lf%lf%lf%lf",&a,&b,&c,&len),a+b+c+len)
 {
   printf("Case %d: ",++T);
   p0=a+b+c;
   p1=p0/2;
   S=sqrt(p1*(p1-a)*(p1-b)*(p1-c));
   if(len>=p0)  {printf("%.2lf\n",S);continue;} //自由线长大于三角形周长
   R=2*S/p0; //三角形内切圆公式S=p0*R/2; R为内切圆半径
   if(2*pi*R-len>eps)
   {
     R=len/pi/2;
     S=pi*R*R;
     printf("%.2lf\n",S);
     continue;
   }
  //利用的就是三角形相似的原理；公式；p0/R*(R-r)=len-2*pi*R;左边是通过内切圆半径与周长的关系求
  //得小三角形的周长；右边是通过自由线的长度减掉三段弧得到相似三角形的周长；
  r=(p0-len)/(p0/R-2*pi);//三角形相似
  a=a/R*(R-r); b=b/R*(R-r);  c=c/R*(R-r);
  p=(a+b+c)/2;
  S=pi*r*r+sqrt(p*(p-a)*(p-b)*(p-c))+r*(a+b+c);//分三个部分求面积
  printf("%.2lf\n",S);
 }
}