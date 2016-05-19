#include<iostream>
#include<string>
#include<map>
using namespace std;

map<char, int> ma;

int main()
{
    for(int i = 0; i < 10; ++i)
        ma['0' + i] = i;
    int T;
    int h, H, m, M, s, S;
    string s1, s2;
    cin >> T;
    while(T--)
    {
        cin >> s1 >> s2;
        h = ma[s1[0]] * 10 + ma[s1[1]];
        H = ma[s2[0]] * 10 + ma[s2[1]];
        H %= 12;
        m = ma[s1[3]] * 10 + ma[s1[4]];
        M = ma[s2[3]] * 10 + ma[s2[4]];
        s = ma[s1[6]] * 10 + ma[s1[7]];
        S = ma[s2[6]] * 10 + ma[s2[7]];
        s -= S;
        if(s < 0)
        {
           s = 60 + s;
           --m;
        }
        m -= M;
        if(m < 0)
        {
           m += 60;
           --h;
        }
         h -= H;
        if(h < 0)
           h += 11;
        if(h / 10 == 0)
          cout << 0;
        cout << h << ':';
        if(m / 10 == 0)
           cout << 0;
        cout << m << ':';
        if(s / 10 == 0)
           cout << 0;
        cout << s << endl;
    }
    return 0;
}