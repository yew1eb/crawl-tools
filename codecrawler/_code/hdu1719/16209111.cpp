#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int n;
    while (scanf("%d",&n) == 1)
    {
        if (n == 0)
        {
            printf("NO!\n");
            continue;
        }
        n++;
        while(n)
        {
            if (n % 2 == 0)
                n /= 2;
            else 
                break;
        }
        while(n)
        {
            if (n % 3 == 0)
                n /= 3;
            else 
                break;
        }
        if (n == 1)
            printf("YES!\n");
        else 
            printf("NO!\n");        
    }
    return 0;
}