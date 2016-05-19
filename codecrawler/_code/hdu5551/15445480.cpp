#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <iostream>
using namespace std;

string a[20];
string s[5];
int main()
{
#ifdef LOCAL
    freopen("in.h","r", stdin);
    freopen("out.h", "w", stdout);
#endif // LOCAL
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; ++cas)
    {
        int n;
        scanf("%d", &n);
        printf("Case #%d: ", cas);
        printf("%d\n", n*2-1);
    }
    return 0;
}



