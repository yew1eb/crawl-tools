#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
using namespace std;
const int maxn = 5000005;
int T, n, m;
char s[maxn];

int main()
{
    cin >> T;
    while (T--)
    {
        scanf("%s", s);
        int f[3] = {0};
        for (int i = 0; s[i]; i++)
        {
            if (s[i] == 'w') f[0] = 1;
            if (s[i] == 'v'&&s[i + 1] == 'v') f[0] = 1;
            if (s[i] == 'y'&&f[0]) f[1] = 1;
            if (s[i] == 'h'&&f[1]) f[2] = 1;
        }
        if (f[2]) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}