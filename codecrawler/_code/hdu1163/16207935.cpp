#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    while(scanf("%d", &n) && n)
    {
        int temp;
        temp = n;
        for(int i = 2; i <= n; ++i)
            temp = temp * n % 9;
        if(temp == 0)
            printf("9\n");
        else
            printf("%d\n", temp);
    }
    return 0;
}