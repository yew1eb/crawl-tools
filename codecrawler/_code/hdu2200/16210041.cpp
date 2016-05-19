#include <iostream>

using namespace std;

int main()
{
    long long m;
    while(cin>>m)
    {
        long long ans=(m-2)*(1<<(m-1))+1;
        cout<<ans<<endl;
    }
    return 0;
}
