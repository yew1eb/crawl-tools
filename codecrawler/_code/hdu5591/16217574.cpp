#include <iostream>

using namespace std;

int main()
{
    int t , n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << (n & 1 ? 1 : 0) << endl;
    }
    return 0;
}
