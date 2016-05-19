#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    while (cin >> s)
    {
        int l = s.length();
        int k = 0;
        for (int i = 0; i < l; i++)
            k += s[i] - '0';
        if (k % 3 == 0 || (s[l - 1] - '0') % 2 == 0|| (s[l - 1] - '0') == 5)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}