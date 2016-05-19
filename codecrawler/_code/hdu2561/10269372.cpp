#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, t, f[20], i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0; i<n; ++i) cin>>f[i];
        sort(f, f+n);
        cout<<f[1]<<endl;
    }
}
