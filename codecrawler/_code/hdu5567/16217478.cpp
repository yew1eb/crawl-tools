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
#define exp 1e-4
using namespace std;
const int N = 105;
const int M = 15005;
const int inf = 1000000007;
const int mod = 2009;
int s[N];
int main()
{
    int n,b,c,i,j,t;
    while(~scanf("%d%d%d",&n,&b,&c))
    {
        t=0;
        for(i=0;i<n;i++)
            scanf("%d",&s[i]);
        for(j=0;j<n;j++)
            for(i=0;i<j;i++)
                if(abs(s[i]-s[j])%b==c)
                    t++;
        printf("%d\n",t);
    }
    return 0;
}