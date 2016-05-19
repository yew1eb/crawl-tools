#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
using namespace std;
int n,m;

int gcd(int a,int b)
{
   return b?gcd(b,a%b):a;
}

int main()
{
    while(cin>>n>>m)
    {
       int GCD=gcd(m*n,(n+m));
       printf("%d/%d\n",m*n/GCD,(n+m)/GCD);

    }
    return 0;
}
