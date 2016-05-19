#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
    int a,b;
    double k = (sqrt(5)-1.0)/2.0;
    while(~scanf("%d%d",&a,&b))
    {
        if(a>b)
            swap(a,b);
        int j = a*k;
        if(a != (int)(j*(1+k)))
            j++;
        if(a+j == b)
            printf("0\n");
        else
            printf("1\n");

    }

    return 0;
}
