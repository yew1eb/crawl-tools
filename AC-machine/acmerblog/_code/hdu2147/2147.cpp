#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
#ifdef test
    freopen("input.txt", "r", stdin);
#endif
    int n, m;
    while(scanf("%d%d", &n, &m))
    {
        if(!n && !m)
            break;
        if(!(n%2) || !(m%2))
            printf("Wonderful!\n");
        else
            printf("What a pity!\n");
    }
    return 0;
}