#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <vector>
#include <stack>
using namespace std;
#define M 105
#define ll long long
#define int64 __int64

int s , c , num[105][105];

int main()
{
    int i , j , t;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d%d",&s,&c);
        for (i = 0 ; i < s ; i++)scanf("%d",&num[0][i]);
        for (i = 1 ; i < s ; i++)
        {
            for (j = 0 ; j+i < s ; j++)
            {
                num[i][j] = num[i-1][j+1]-num[i-1][j];
            }
        }
        for (i = 1 ; i <= c ; i++)num[s-1][i] = num[s-1][0];
        for (i = s-2 ; i >= 0 ; i--)
        {
            for (j = 0 ; j < c ; j++)
            {
                num[i][s-i+j] = num[i+1][s-i+j-1]+num[i][s-i+j-1];
            }
        }
        for (i = s ; i < s+c-1 ; i++)printf("%d ",num[0][i]);
        printf("%d\n",num[0][s+c-1]);
    }
    return 0;
}