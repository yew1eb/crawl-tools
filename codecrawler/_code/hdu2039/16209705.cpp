#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    int n, i;
    double a[3];
    cin >> n;

    for (i = 0; i < n; i ++)
    {
        cin >> a[0] >> a[1] >> a[2];
        if ((a[0] + a[1]) > a[2] && (a[0] + a[2] > a[1]) && (a[1] + a[2]) > a[0])
            cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    system ("pause");
    return 0;
}
