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
const int N = 100005;
const int M = 10005;
const int inf = 1000000000;
const int mod = 10007;
int gcd(int x,int y)
{
    if(x%y)
        return gcd(y,x%y);
    return y;
}
int main()
{
    int t,k,c,p=1,x,y;
    scanf("%d",&t);
    while(t--)
    {
        c=1;
        scanf("%d%d",&x,&y);
        if(x>y)
            swap(x,y);
        k=gcd(x,y);
        while(y%(x+k)==0)
        {
            c++;
            y=y/(x/k+1);
            if(x>y)
                swap(x,y);
            k=gcd(x,y);
        }
        printf("Case #%d: %d\n",p++,c);
    }
    return 0;
}