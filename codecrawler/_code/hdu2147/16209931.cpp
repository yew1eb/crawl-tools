#include<iostream>
using namespace std;
int main()
{
    int n,m;
    while(cin>>n>>m,m+n)
    {
        puts((n%2&&m%2)?"What a pity!":"Wonderful!");
    }
    return 0;
}