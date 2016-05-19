#include <iostream>
#include <string>
#include <queue>
#define M 30
using namespace std;

int a[M];

priority_queue <int, vector<int>, greater<int> > Q;
string s;

int f(char c)
{
    if (c=='_') return 0;
    else return (c-'A'+1);
}

int main()
{
    int b1, b2, n, m, i;
    while (cin>>s)
    {
        if (s=="END") break;
        n = s.length();
        b1 = n << 3;
        memset(a, 0, sizeof(a));
        for (i=0;i<n;++i)
        {
            a[f(s[i])]++;
        }
        for (i=0;i<M;++i)
        if (a[i]!=0)
        {
            Q.push(a[i]);
        }
        b2 = Q.size()==1 ? n : 0;
        while (Q.size()>1)
        {
          n = Q.top(), Q.pop();
          m = Q.top(), Q.pop();
          b2 += n+m;
          Q.push(n+m);
        }
        Q.pop();
        printf("%d %d %.1f\n", b1, b2, b1*1.0/b2);
    }
    return 0;
}
