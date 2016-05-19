#include<iostream>
using namespace std;

int main()
{
    __int64 a;
    int T;
    cin >> T;
    while(T--)
    {
        cin >> a;
        cout << a*a*a << " " <<(a+1)*(a+1)*(a+1) << endl;
    }

    return 0;
}
