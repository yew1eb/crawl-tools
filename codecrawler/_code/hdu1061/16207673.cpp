#include <iostream>
using namespace std;

int  main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n; 
        cin >> n;
        int a = n % 10;
        int b = a;
        int mod = 0;
        for(int i = 1; i < n; i++)
        {
            b = (b * a) % 10;
            if(b == a)
            {
                mod = i;
                break;
            }
        }
        if(1 == mod)
        {
            cout << a << endl;
            continue;
        }
        if(mod != 0)
            n =  n % mod + mod;
        b = a;
        for(int i = 1; i < n; i++)
                b = (b * a) % 10;
        cout << b << endl;
    }
    return 0;
}