/*
    Author: ACb0y
    Date: 2010å¹´9æ6æ¥9:21:47
    Type: Water()
    ProblemIdï¼hdu 2094 äº§çå å
    Result: 2923032 2010-09-06 09:20:14 Accepted 2094 31MS 276K 643 B C++ ACb0y 
*/
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    int n;
#ifndef ONLINE_JUDGE
    freopen("2094.txt", "r", stdin);
#endif
    while (cin >> n) 
    {
        if (n == 0) {
            break;
        }
        string a, b;
        map<string, int> m;
        for (int i = 0; i < n; i++) 
        {
            cin >> a >> b;
            if (m.find(a) == m.end()) {
                m[a] = 0;
            }
            if (m.find(b) == m.end()) {
                m[b] = -1;
            } else {
                m[b]--;
            }
        }
        int c = 0;
        map<string, int>::iterator it;
        for (it = m.begin(); it != m.end(); it++) {
            if (it->second == 0) {
                c++;
            }
        }
        if (c == 1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}