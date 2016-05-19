#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    int a, b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        int x = (a+b)/2;
        int y = (a-b)/2;
        if(a>=b && x*2 == a+b && y*2 == a- b)
        {
            printf("%d %d\n",x, abs(y));
        }
        else
            printf("impossible\n");
    }
    return 0;
}
