#include<iostream>
using namespace std;
int main()
{
 __int64 a[501]={0,1};
 int i,x,y;
 for(i=2,x=y=0;i<=500;i++)
 { 
        if(i%2==0){x++;}
        else {y++;}
  a[i]=a[i-1]+i*i-x*y;
 }
 int n;
 while(scanf("%d",&n)!=EOF)
 {printf("%I64d\n",a[n]);}
 return 0;
}
