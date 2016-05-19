#include <cmath>
#include <cstdio>
#include <iostream>
#include<string>
#include<sstream>
using namespace std;

int test,n,b,q;
double L,R,del;

string i2s(int x)
{
    string y;
    stringstream f;
    f << x; f >> y;
    return y;
}

bool check()
{
    string sn,sb;
    sn=i2s(n); sb=i2s(b);
    for (int i=0; i<sn.length(); i++)
        if (sn[i]!=sb[i]) return false;
    return true;
}

int main()
{
    cin >> test;
    for (int i=1; i<=test; i++)
    {
        cin >> n >> b >> q;
        if (q==1)
        {
            if (check()) printf("Case #%d: %.5lf\n",i,1.0);
                else printf("Case #%d: %.5lf\n",i,0.0);
            continue;
        }
        else if (q == 10 || q == 100 || q == 1000)
        {
            while (n % 10 == 0) n /= 10;
            if (check()) printf("Case #%d: %.5lf\n",i,1.0);
                else printf("Case #%d: %.5lf\n",i,0.0);
            continue;
        }
        printf("Case #%d: %.5lf\n",i,log10(n+1)-log10(n));
    }
    
    return 0;
}