
#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

int fact(int i)
{
    if (i == 1)
        return 1;
    else if (i == 0)
        return 1;
    else
        return fact(i - 1) * i;
}
int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    /* */
    int farr[10];
    for (int j = 0; j < 10; ++j)
        farr[j] = fact(j);
    cout << "n e" << endl;
    cout << "- -----------" << endl;
    for (int k = 1; k < 11; ++k) {
        double e = 0.0;
        for (int i = 0; i < k; ++i)
        {
            e += 1.0 / farr[i];
        }
        cout << k - 1 << ' ';
        if (k == 1)
            cout << 1 << endl;
        else if (k == 2)
            cout << 2 << endl;
        else if (k == 3)
            cout << 2.5 << endl;
        else
            printf("%.9lf\n", e);
    }
    return 0;
}