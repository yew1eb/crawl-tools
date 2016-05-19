#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define LL __int64
int main()
{
    int m,n;
    while(cin>>m>>n)
    {
        cout<<(m-1)*n-m<<" "<<(n-1)*(m-1)/2<<endl;
    }
    return 0;
}