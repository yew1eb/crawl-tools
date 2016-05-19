/*
we should set the array size beyond the standard more  such as +50 or +500
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#define M 1000000
using namespace std;
int flag[1000000+500]={0};
int digit[7+5]={0};//the number of the bit
/*d(n)*/
int d1(int num)
{
    int sum=num;
    int bit=0;
    while(num>0)
    {
        bit=num%10;
        num/=10;
        sum+=bit;
    }
    return(sum);
}
/*d(n)*/
int d(int num)
{
    int sum=num;
    int i=0;
    for(i=0;i<=7-1;i++)
    {
        sum+=digit[i];
    }
    return(sum);//sum > 1000000  so will lead to the flag[d{i}] overflow
}
/*big data plus one*/
int PlusDigit()
{
    int i=0;
    digit[0]++;
    for(i=0;i<=7-1;i++)
    {
        if(digit[i]>=10)
        {
            int c=digit[i]/10;
            digit[i+1]+=c;
            digit[i]=digit[i]%10;
        }
    }
    return(0);
}
/*for test*/
int test()
{
    return(0);
}
/*main process*/
int MainProc()
{
    int i=0;
    for(i=1,digit[0]=1;i<=M;i++)//907019
    {
        flag[d(i)]=1;
        if(!flag[i])
        {
            printf("%d\n",i);
        }
        PlusDigit();
    }
    return(0);
}
int main()
{
    MainProc();
    return(0);
}
