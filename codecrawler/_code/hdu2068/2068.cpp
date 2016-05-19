#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<set>
#include<ctype.h>
#include<algorithm>
#include<string>
#define PI acos(-1.0)
#define maxn 1000
#define INF 1<<25
#define mem(a, b) memset(a, b, sizeof(a))
typedef long long ll;
using namespace std;
ll D[13];
ll C[26][26];
void init()
{
    D[1] = 0, D[2] = 1;
    for (ll i = 3; i <= 13; i++)
        D[i] = (i - 1) * (D[i - 1] + D[i - 2]);
    C[1][0] = C[1][1] = 1;
    for (int i = 1; i <= 25; i++)
        C[i][0] = 1;
    for (ll i = 2; i <= 25; i++)
        for (ll j = 1; j <= i; j++)
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
}

int main ()
{
    int n;
    init();
    while(~scanf("%d", &n) && n)
    {
        ll sum = 0;
        for (ll i = 1; i <= n / 2; i++)
        {
            sum += D[i] * C[n][i];
        }
        sum += 1;
        cout<<sum<<endl;
    }
    return 0;
}