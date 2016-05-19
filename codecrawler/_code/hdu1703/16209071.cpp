#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
   int f[20000];
   f[1]=0;
   f[2]=1;
   f[3]=3;
   f[4]=4;
   for(int i=5;i<=10000;i++)
    f[i]=f[i-1]+2;
    int n;
    while(scanf("%d",&n)&&n)
    {
        printf("%d\n",f[n]*5);
    }
    return 0;
}
