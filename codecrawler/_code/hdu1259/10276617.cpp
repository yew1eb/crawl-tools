#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    int t, n;
    int x, y, ans;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans = 2;
        while(n--)
        {
            cin>>x>>y;
            if(ans == x)
                ans = y;
            else if(ans == y)
                ans = x;
        }
        cout<<ans<<endl;
    }

    return 0;
}
