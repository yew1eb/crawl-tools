#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;



bool is_prime(int n)
{
    if(n<=2) return false;
    if(n%2==0) return false;
    for(int i=3; i<=sqrt(n); i +=2)
        if(n % i == 0) return false;
    return true;
}
int main()
{
    int n;
    int cas = 1;
    while(scanf("%d",&n)&&n>0)
    {
        printf("%d: ",cas++);
        if(is_prime(n)) printf("yes");
        else printf("no");
        printf("\n");
    }
    return 0;
}
