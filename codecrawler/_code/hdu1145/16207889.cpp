#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
double ex[30+5]={0.0};//best expect
double mon[30+5]={0.0};//best money
double t=0.0;//probability p is t < p < 1
int n=0;//number of question
double bp=0.0;//boundary probability, if p > bp then get in the question  otherwise get out the question
int main()
{
    mon[0]=1;//after answer 0 question,the index begin with 1
    for(int i=1;i<=30;i++)
    {
        mon[i]=mon[i-1]*2;
    }
    while(scanf("%d%lf",&n,&t)!=EOF&&(n>0))
    {
        ex[n]=mon[n];
        //from ex[i+1] get the ex[i],ex[0] is our answers
        for(int i=n-1;i>=0;i--)
        {
            bp=mon[i]/ex[i+1];// 2^i/ex[i+1] is the boundary probability ==>  bp * ex[i+1] > 2^i
            if(bp<=t)//bp is not in [t,1) range, all p in [t,1) will let the p * ex[i+1] >2^i
            {
                ex[i]=(1+t)/2 * ex[i+1];
            }
            else// E = p*x + (1-p)*y
            {
                ex[i]=(bp-t)/(1-t) * mon[i] + (1-bp)/(1-t) * (1+bp)/2 * ex[i+1];
            }
        }
        printf("%.3lf\n",ex[0]);
    }
    return(0);
}
