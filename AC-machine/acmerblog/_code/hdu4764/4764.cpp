#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main()
{
    int n,k;
    while (cin>>n>>k&&n+k)
    {
        n=n-1;
        k=k+1;
        n=n%k;
        if (n!=0)
            cout<<"Tang"<<endl;
        else
            cout<<"Jiang"<<endl;
    }
}
