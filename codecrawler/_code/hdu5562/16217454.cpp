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
const int M = 100005;
const int inf = 100000000;
const int mod = 2009;
int s[N];
int main()
{
    int t,n,V,i,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&V);
        for(k=i=0;i<n;i++)
            scanf("%d",&s[i]);
        sort(s,s+n);
        for(i=0;i<n;i++)
            if(V-s[i]>=0)
            {
                k++;
                V-=s[i];
            }
            else
                break;
        printf("%d\n",k);
    }
    return 0;
}