#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<string>
#include<algorithm>
#include<iostream>
#define exp 1e-10
using namespace std;
const int N = 25;
const int M = 710;
const int inf = 1000000000;
const int mod = 1000000007;
int main()
{
    int a,b,c,l,r,t,i,Max,Min,y;
    scanf("%d",&t);
    while(t--)
    {
        Max=-inf;
        Min=inf;
        scanf("%d%d%d%d%d",&a,&b,&c,&l,&r);
        for(i=l;i<=r;i++)
        {
            y=a*i*i+b*i+c;
            Max=max(Max,y);
            Min=min(Min,y);
        }
        printf("%d %d\n",Max,Min);
    }
    return 0;
}