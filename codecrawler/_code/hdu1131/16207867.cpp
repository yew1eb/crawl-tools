#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <map>
using namespace std;
#define INF 0x3f3f3f3f
#define maxn 20010
#define g 9.8
int a[110][1100];
void Catalan()
{
    int yu,len = 1;
    a[2][0]=1;
    a[2][1]=2;
    a[1][0]=1;
    a[1][1]=1;
    for(int i = 3; i <= 100; i++)
    {
        yu = 0;
        for(int j = 1; j <= len; j++)
        {
            int t = a[i-1][j]*(4*i-2)+yu;
            yu = t / 10;
            a[i][j] = t % 10;
        }
        while(yu)
        {
            a[i][++len] = yu % 10;
            yu /= 10;
        }
        for(int j = len; j >= -1; j--)
        {
            int t = a[i][j] + yu * 10;
            a[i][j] = t / (i+1);
            yu = t % (i+1);
        }
        while(!a[i][len])
            len--;
    }
    for(int i = 2; i <= 100; i++)
    {
        for(int k = 2; k <= i; k++)
        {
            yu = 0;
            for(int j = 1; j <= len; j++)
            {
                int t = a[i][j]*k+yu;
                yu = t / 10;
                a[i][j] = t % 10;
            }
            while(yu)
            {
                a[i][++len] = yu % 10;
                yu /= 10;
            }
            while(!a[i][len])
                len--;
        }
        a[i][0] = len;
    }
}
int main()
{
    int n;
    Catalan();
    while(scanf("%d",&n) && n)
    {
        for(int i = a[n][0]; i > 0; i--)
            printf("%d",a[n][i]);
        printf("\n");
    }
    return 0;
}