#include <iostream>
using namespace std;

int main()
{
    int n,m,min,a;
    while(cin>> n >> m)
    {
        min = 10000000;
        while(n--)
        {
            cin >> a;
            if(min > a)
            min = a;
        }
        m = m/min;
        cout << m << endl;
    }

    return 0;
}
