
#include <set>
#include <map>
#include <cstdio>
using namespace std;

int main()
{
    int n, i, t;
    set <int> s;
    set <int>::iterator it;
    map <int, int> m;
    map <int, int>::iterator iter;
    
    while (scanf("%d", &n), n)
    {
          s.clear();
          m.clear();
          for (i = 0; i<n; ++i)
          {
              scanf("%d", &t);
              s.insert(t);
              m[t]++;
          }
          for (it = s.begin(); it != s.end(); ++it)
          {
              if (m[*it] == 1)
              {
                  printf("%d\n", *it);
                  break;
              }
          }
    }
    
    return 0;
}
