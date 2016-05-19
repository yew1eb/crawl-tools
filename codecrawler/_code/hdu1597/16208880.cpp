//ç±i*(i+1)/2=n,å¯ä»¥æ±åº i,ç¶åç±i%9ï¼å°±å¯å¾åºç­æ¡ 
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    double n;    
    __int64 i,j,T,y;
    scanf("%I64d",&T);
    while(T--)
    {
        scanf("%lf",&n);
        double x=sqrt(2*n*1.0+0.25)-0.5;//i*(i+1)/2=n -> (i*i+i+0.25)=2*n-0.25 -> (i+0.5)^2=(2*n-0.25)
        if(x>(int)x/1) y=(int)x/1+1;
        else y=(int)x/1;  //åä¸åæ´ï¼å ä¸ºè¦æ»¡è¶³i*ï¼i-1ï¼/2<n<i*ï¼i+1ï¼/2,nå°±å¤äºsum(i-1)--sum(i)ä¹é´ï¼ç¶åæ±ä½
        int sum=y*(y-1)/2;
         y=n-sum;
        if(y%9==0)
        cout<<"9";
        else cout<<y%9;
        cout<<endl;
    }
}
