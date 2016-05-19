#include <iostream>
#include <cmath>
using namespace std;

const double pi = 3.1415926;
int main()
{
    int n;
    double x, y, area;
    cin>>n;
    for(int i=1; i<=n; ++i)
    {
        cin>>x>>y;
        int ans = (int)(pi*(x*x+y*y)/100 + 1.0);
        cout<<"Property "<<i<<": This property will begin eroding in year "<<ans<<"."<<endl;
    }
    cout<<"END OF OUTPUT."<<endl;
    return 0;
}
