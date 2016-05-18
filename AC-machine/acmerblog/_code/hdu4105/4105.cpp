#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <vector>
#include <queue>
#include <stack>
#include <fstream>
#include <map>
#include <set>
#define bug puts("here");

using namespace std;

typedef long long ll;

const int maxn = 2 * 101000;
const ll mod = 1e9+7;
const int inf = 0x3f3f3f3f;
const double PI = atan(1.0) * 4.0;
const double eps = 1e-8;

int dp[110][110][2];
char s[110];
int n;

int scmp(int a,int b,int x, int y){ // [a,b] < [x,y] : -1
    while(s[a]  == '0' && a <= b) a++;
    while(s[x]  == '0' && x <= y) x++;
    if(b-a > y-x) return 1;
    if(b-a < y-x) return -1;
    while(s[a]  == s[x]  && a <= b && x <= y){
        a ++;
        x ++;
    }
    if(a <= b && x <= y)
        return s[a]  < s[x]  ? -1 : 1;
    else if (x <= y) return -1;
    else if (a <= b) return 1;
    else return 0;
}

int main()
{
    while(~scanf("%d",&n))
    {
        scanf("%s",s);
        memset(dp, -0x3f, sizeof dp);
        for(int i=0;i<n;i++) dp[i][0][0] = 1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                for(int k=0;k<j;k++)
                {
                    if(scmp(k,j-1,j,i) == 1) dp[i][j][0] = max(dp[i][j][0] , dp[j-1][k][1] + 1);
                    if(scmp(k,j-1,j,i) == -1) dp[i][j][1] = max(dp[i][j][1] , dp[j-1][k][0] + 1);
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++)
            ans = max(ans , max(dp[n-1][i][0] , dp[n-1][i][1]));
        printf("%d\n",ans - 1);
    }
}<strong>
</strong>