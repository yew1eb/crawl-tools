#include <iostream>
#include <string.h>
using namespace std;
const int N = 105;
const int INF = 9999999;
int dp[N];
int a[N];
int p[N];

int sum(int x, int y, int p)
{
    int num = 0; 
    for(int i = x; i <= y; i++)
        num += a[i];
    return (num + 10) * p;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        memset(dp, INF, sizeof(dp));
        memset(a, 0, sizeof(a));
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i] >> p[i];
        }
        dp[0] = 0;
        //dp[1] = (a[1] + 10) * p[1];
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                dp[i] = min(dp[i], dp[j] + sum(j+1, i, p[i]));
            }
        }
        cout << dp[n]  << endl;
    }
    return 0;
}