/*
N!<2^bit
log(N!)<log(2^bit)
log(1)+log(2)+......+log(N)<bit * log(2)
log(1)/log(2) + ......log(N)/log(2) < bit
*/
#include<stdio.h>
#include<iostream>
#include<string>
#include<stdlib.h>
#include<math.h>
using namespace std;
__int64 year=0,N=0;
__int64 bit=0;//wrong answer   compile error: __int64_t
double sum=0.0;
double logs[100]={0.0};
int main()
{
    while(scanf("%lld",&year)!=EOF&&year>0)
    {
        //bit=(int)pow(2.0,(year-1960)/10)*4;
        bit=(year-1960)/10+2;
        bit=1<<bit;
        N=1;
        sum=0;
        do
        {
//            if(logs[N]==0.0)
//            {
                sum+=log(N)/log(2.0);
//                logs[N]=sum;//logs[N]=log(1)/log(2)+......log(N)/log(2)
//            }
//            else
//            {
//                sum=logs[N];
//            }
            N++;
        }while(sum<bit);//wrong answer : sum < (double)bit
        printf("%lld\n",N-1-1);//-1 for N++  and another -1 is for sum > bit and let sum < bit so N-1 another
    }
    return(0);
}
