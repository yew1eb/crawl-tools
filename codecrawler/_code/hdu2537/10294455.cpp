#include<iostream>
using namespace std;
int main()
{
    int n, i, y, r;
    char str[20];

    while (cin >> n && n)
    {
        cin >> str;
        r = y = 0;
        for (i = 0; i < n - 1; i++)
        {
            if (str[i] == 'R')    r++;
            else y++;
        }
        if (r >= 7 && str[n - 1] == 'B')    cout << "Red" << endl;
        else if (y < 7 && str[n - 1] == 'L')    cout << "Red" << endl;
        else cout << "Yellow" << endl;
    }
    return 0;
}