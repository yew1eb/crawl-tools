#include <iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int a[10005];

int main()
{
    int n;
    int i;
    while ((scanf("%d", &n)) != EOF)
    {
        int temp;
        int flag = -1;
        memset(a, 0, sizeof(a));
        for (i = 1; i <= n; i++)
        {
            scanf("%d", &temp);
            a[temp]++;
            if (n - a[temp] < a[temp])
            {
                flag = temp;
            }
        }
        printf("%d\n", flag);
    }
    return 0;
}
