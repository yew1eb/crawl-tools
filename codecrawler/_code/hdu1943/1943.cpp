#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

const double PI=4.0*atan(1.0);

int main()
{
    int n;
    double h,d,s;
    cin>>n;
    while(n--)
    {
        cin>>h>>d>>s;
        int res=PI/(asin((d+s)/(h-d)));
        cout<<res<<endl;
    }
    return 0;
}