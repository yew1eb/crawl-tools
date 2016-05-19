#include<stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int n;
    double sum;
    while (scanf("%d",&n) && n)
    {
        sum=0;
        for (int i=2; i<=n; i++)
        {
            sum+=1.0/i*(n-i+1);
        }
        printf("%.2f\n",sum*2+n);
    }
    return 0;
}