#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int t,n;
    while(cin >> t)
    {
        while(t--)
        {
            cin >> n;
            cout << (int)pow(2,n)-1  << endl;
        }
    }

    return 0;
}
