#include <iostream>
#include <cstdio>
using namespace std;
int mod_exp(int a, int b, int c)        //快速幂取余a^b%c
{
    int res, t;
    res = 1 % c; 
    t = a % c;
    while (b)
    {
        if (b & 1)
        {
            res = res * t % c;
        }
        t = t * t % c;
        b >>= 1;
    }
    return res;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        cout << mod_exp(n, n, 10) << endl;
    }
    system("pause");
    return 0;
}