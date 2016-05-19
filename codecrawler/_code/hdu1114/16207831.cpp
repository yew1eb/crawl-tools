#include <iostream>
using namespace std;

const int M = 100000000;
const int W = 10001;
int dp[W];
int w[501], v[501];
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int E, F;
        cin >> E >> F;
        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> v[i] >> w[i];  //å¶å®å¯ä»¥ä¸éè¦ç¨è¿ä¸ªæ°ç»ï¼æ¯æ¬¡è¾å¥çæ¶åç´æ¥è¿è¡dp
        int maxw = F - E;
        for(int i = 0; i <= maxw; i++)
            dp[i] = M;
        dp[0] = 0;

        for(int i = 0; i < n; i ++)
        {
            for(int j = w[i]; j <= maxw; j++)
                dp[j] = min(dp[j], dp[j-w[i]] + v[i]);
        }
        if(dp[maxw] == M)
            cout << "This is impossible."<< endl;
        else
            cout << "The minimum amount of money in the piggy-bank is " << dp[maxw]<< "." << endl;
    }
    return 0;
}