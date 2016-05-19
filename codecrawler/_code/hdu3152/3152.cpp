/**
 * ID: ping128
 * LANG: C++
 */

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <math.h>
#include <algorithm>
#include <map>
#include <string.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;
typedef pair<PII, int>PII2;

int n;
int in[150][150];
int dp[150][150];

int cx[] = {0, 0, 1, -1}, cy[] = {1, -1, 0, 0};

class Solve
{
 public:
 void main2()
 {
 for(int i = 0; i < n; i++ )
 for(int j = 0; j < n; j++ )
 cin >> in[i][j];
 for(int i = 0; i < n; i++ )
 for(int j = 0; j < n; j++ )
 dp[i][j] = 1000000000;
 dp[0][0] = in[0][0];
 queue<PII>Q;
 Q.push(PII(0, 0));
 while(!Q.empty())
 {
 int ii = Q.front().first;
 int jj = Q.front().second;
 Q.pop();
 for(int i = 0; i < 4; i++ )
 {
 int iii = ii + cx[i];
 int jjj = jj + cy[i];
 if(iii >= 0 && iii < n && jjj >= 0 && jjj < n && dp[iii][jjj] > dp[ii][jj] + in[iii][jjj])
 {
 dp[iii][jjj] = dp[ii][jj] + in[iii][jjj];
 Q.push(PII(iii,jjj));
 }
 }
 }
 cout << dp[n - 1][n - 1] << endl;
 }
};

int main()
{
 // freopen("c.in", "r", stdin);
 // freopen(".out", "w", stdout);
 int t= 0 ;
 while(1)
 {
 t++;
 cin >> n;
 if(n == 0) break;
 Solve ___test;
 printf("Problem %d: ", t);
 ___test.main2();
 }
//while(1);
return 0;
}