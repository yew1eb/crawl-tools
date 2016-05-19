#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int T, m, n, a[45];
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        int sum=0;
        sum += (100 - a[0])*(100 - a[0]);
        cout << sum << endl;
    }
    return 0;
}