#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
    int t;
    string a,b;
    cin>>t;
    getchar();
    while(t--)
    {
       cin>>a>>b;
       a.insert(a.size()/2,b);
       cout<<a<<endl;
    }
    return 0;
}