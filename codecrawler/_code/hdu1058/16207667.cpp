#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long num[60000];
int b[4]={2,3,5,7};
long long  min(long long a,long long b,long long c,long long d)
{
    a=a>b?b:a;
    c=c>d?d:c;
    return a>c?c:a;
}
int main()
{
    num[1]=1;
    int i;
    int l1=1,l2=1,l3=1,l4=1;
    for(i=2;i<=5842;i++)
    {
        num[i]=min(num[l1]*2,num[l2]*3,num[l3]*5,num[l4]*7);
        if(num[i]==num[l1]*2) l1++;
        if(num[i]==num[l2]*3) l2++;
        if(num[i]==num[l3]*5) l3++;
        if(num[i]==num[l4]*7) l4++;
    }
    int n;
    while(scanf("%d",&n),n)
    {
        if(n % 10 == 1 && n % 100 != 11)
              printf("The %dst humble number is %lld.\n",n ,num[n]);
          else if(n % 10 == 2 && n % 100 != 12)
              printf("The %dnd humble number is %lld.\n",n ,num[n]);
          else if(n % 10 == 3 && n % 100 != 13)
              printf("The %drd humble number is %lld.\n",n ,num[n]);
          else
              printf("The %dth humble number is %lld.\n",n ,num[n]);
    }
    return 0;
}