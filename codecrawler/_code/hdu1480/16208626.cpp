#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <limits.h>
using namespace std;

int main()
{
    long long a[30];
    long long b[30]; ///end of 1 6
    long long c[30]; ///end of 2 3 4 5
    int i;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    a[3]=104;
    c[3]=72;
    b[3]=32;
    for(i=4; i<=25; ++i)
    {
        /// n-1æªææé¥å
        b[i]+=2*(6*(pow(2,i-1)-2)+4*(pow(2,i-2)-1));
        c[i]+=36*(pow(2,i-1)-2);
        /// n-1å·²ææé¥å
        c[i]+=4*a[i-1];
        b[i]+=c[i-1]*2+b[i-1];
        a[i]+=b[i]+c[i];
    }
    for(i=3; i<=25; i++)
        cout<<"N="<<i<<": "<<a[i]<<endl;
    return 0;
}
