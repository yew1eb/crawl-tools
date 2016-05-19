#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;
const int mod = 100000;
int a[1003][50];
int main()
{
    int n,i,j;
    a[1][1] = 1;
    a[2][1] = 2;
    a[3][1] = 4;
    a[4][1] = 7;
    for(i = 5; i <= 1000; i ++)
    {
        for(j = 1; j < 50; j ++)
        {
            a[i][j] += a[i-1][j] + a[i-2][j] + a[i-4][j];
            a[i][j+1] += a[i][j]/mod;
            a[i][j] %= mod;
        }
    }
    while(~scanf("%d",&n))
    {
        j = 49;
        while(!a[n][j])
        j--;
        printf("%d",a[n][j]);
        for(--j; j >=1; j--)
        printf("%05d",a[n][j]);
        printf("\n");
    }
    return 0;
}