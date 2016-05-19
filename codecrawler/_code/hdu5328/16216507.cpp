#include <iostream>
#include<stdio.h>
#include<cstring>
#include<math.h>
using namespace std;
const int MAX=1e6+10;
int T,n,a[MAX],b[MAX];
double c[MAX];
int get_max()
{
    int num=1,f=1;
    int m=b[0];
    for(int i=1;i<n-1;i++)
    {
        if(b[i]==b[i-1])
            f++;
        else
        {
            m=b[i];
            num=max(num,f);
            f=1;
        }
    }
    num=max(num,f);

    int num1=1,f1=1;
    double m1=c[0];
    for(int i=1;i<n-1;i++)
    {
        if(c[i]==c[i-1])
            f1++;
        else
        {
            m1=c[i];
            num1=max(num1,f1);
            f1=1;
        }
    }
    num1=max(num1,f1);
    num=max(num,num1);
    return num+1;
}
int main()
{
    int i,j;
    scanf("%d",&T);
    while(T--)
    {
       scanf("%d",&n);
       scanf("%d",&a[0]);
       for(i=1;i<n;i++)
       {
           scanf("%d",&a[i]);
           b[i-1]=a[i]-a[i-1];
           c[i-1]=double(a[i])/double(a[i-1]);
       }
       if(n==1)
        printf("1\n");
       else
       {
           int len=get_max();
        printf("%d\n",len);
       }
        }
    return 0;
}