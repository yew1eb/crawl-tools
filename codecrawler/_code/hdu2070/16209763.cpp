#include <iostream>
#include <cstring>
using namespace std;

long long a[51];
void initial()
{
    a[0]=0;
    a[1]=1;
    for(int i=2;i<=50;i++)
    {
        a[i]=a[i-1]+a[i-2];
    }
}

int main()
{
    int n;
    initial();
    while(cin>>n&&n!=-1)
    {
        cout<<a[n]<<endl;
    }
    return 0;
} 