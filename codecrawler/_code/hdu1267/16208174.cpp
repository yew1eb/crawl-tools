#include <iostream>
using namespace std;

int H,D;
__int64 dp[100][100];            //dp[m][n]

void DP()
{
    int i,j;
    for(i=0; i<=20; ++i)
    {
        dp[i][0] = 1;
    }
    for(i=1; i<=20; ++i)
    {
        for(j=1; j<=i; ++j)
        {
            dp[i][j] = dp[i-1][j]+dp[i][j-1];
        }
    }
}
int main()
{
    DP();
    while(cin >> H >>D)
    {
        cout << dp[H][D] << endl;
    }
    return 0;
}