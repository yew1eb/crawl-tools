#include <iostream>
using namespace std;

int main()
{
    double a,sum;
    while(cin >> a)
    {
        sum = 0;
        sum+=a;
        int n = 11;
        while(n--)
        {
            cin >> a;
            sum+=a;
        }
        cout << "$" << sum/12.0 << endl;
    }

    return 0;
}
