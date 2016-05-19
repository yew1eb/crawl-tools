#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int f[1005], a[1005];

int main()
{
    int i, n, m, MAX, j;
    while (cin >> n, n) {
        for (i = 0; i < n; i++)
            cin >> a[i];
        cin >> m;
        if (m < 5) {
            cout << m << endl;
            continue;
        }
        sort(a, a + n);
        MAX = a[n - 1];
        memset(f, 0, sizeof(f));
        m -= 5;
        for (i = 0; i < n - 1; i++) {
            for (j = m; j >= a[i]; j--)
                f[j] = max(f[j], f[j - a[i]] + a[i]);
        }
        cout << m + 5 - f[m] - MAX << endl;
    }
    return 0;
}
