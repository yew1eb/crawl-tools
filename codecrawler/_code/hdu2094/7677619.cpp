#include <set>
#include <map>
#include <string>
#include <iostream>
using namespace std;

int main(void)
{
    int n, i, t;
    string b, e;
    set <string> s;
    set <string>::iterator it;
    map <string, string> m;
    map <string, string>::iterator iter;

    while (cin >> n, n)
    {
        s.clear();
        m.clear();
        for (i = 0; i < n; i++)
        {
            cin >> b >> e;
            s.insert(b);
            s.insert(e);
            m[e] = b;
        }
        for (t = 0, it = s.begin(); it != s.end(); it++)
        {
            if (!m[*it].length())
                t++;
        }
        puts(t == 1 ? "Yes" : "No");
    }

    return 0;
}
    