#include <iostream>
#include <cstdio>
#include <cmath>


using namespace std;

int main()
{
    int n,m;
    int test;
    cin>>test;
    while(test--)
    {
        cin>>n>>m;
        cout<<n*(n+1)*m*(m+1)/4<<endl;
    }
    return 0;
}