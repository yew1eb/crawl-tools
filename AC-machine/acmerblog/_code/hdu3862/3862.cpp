#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#define eps 1e-6
using namespace std;

double a[100010];

int main()
{
    int cas;
    int n,i;
    bool flag;
    scanf("%d",&cas);
    while(cas--)
    {
        a[0]=0;
        flag=true;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            double b;
            scanf(