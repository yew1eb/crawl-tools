#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;

int main() {
    int n, s, t;
    while (cin >> n>>s >> t) {
        if (n == 1)
            cout << 0<< endl;
        else {
            if (s == t)
                cout << -1<< endl;
            else if ((s == 1 && t == n) || (s == n && t == 1))
                cout << 0<< endl;
            else if ((s == 1 || s == n) || abs(s-t) == 1)
                cout << 1<< endl;
            else
                cout << 2<< endl;
        }
    }
    return 0;
}