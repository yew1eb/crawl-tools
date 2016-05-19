#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main()
{
    int y, n;
    double t1, t2;
    while(scanf("%d",&y),y)
    {
        t1  = 1<<((y-1960)/10 + 2);
        n = 0;
        t2  = 0.0;
        while(t1>=t2)
        {
            t2 +=log(++n)/log(2);
        }
        printf("%d\n",n-1);
    }
    return 0;
}
