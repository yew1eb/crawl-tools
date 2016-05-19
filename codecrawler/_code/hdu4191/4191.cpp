#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define DB double
using namespace std;

const int MAXN = 20;
DB dp[MAXN][MAXN];
void init(){
    for(int i = 0;i <= 10; i++)
        for(int j = 0; j <= 10; j++)
            dp[i][j] = 0.0;
}
int main()
{
 //   freopen("test.txt","r",stdin);
    DB p;
    while(scanf("%lf",&p) != EOF){
        if(p == -1.0) break;
        init();
        for(int i = 0; i < 3; i++) dp[4][i] = 1.0;
        dp[3][3] = p * p / (1 - p * (1 - p) * 2);
        for(int i = 3; i >= 0; i--)
            for(int j = 3; j >= 0;j--){
                if(i == 3 && j == 3) continue;
                dp[i][j] = p * dp[i+1][j] + (1 - p) * dp[i][j + 1];
            }
        DB gp = dp[0][0];
        init();
        for(int i = 0; i < 6; i++) dp[7][i] = 1.0;
        dp[6][6] = p * p / (1 - p * (1 - p) * 2);
        for(int i = 6; i >= 0; i--)
            for(int j = 6; j >= 0;j--){
                if(i == 6 && j == 6) continue;
                dp[i][j] = p * dp[i+1][j] + (1 - p) * dp[i][j + 1];
            }
        DB p7 = dp[0][0];
    //    cout<<"p7:"<<p7<<endl;
        init();
        dp[6][6] = p7;
        dp[6][5] = gp + (1.0 - gp) * dp[6][6];
        dp[5][6] = gp * dp[6][6];
        for(int i = 0; i <= 4;i++) dp[6][i] = 1.0;
        for(int i = 5; i >= 0; i--)
            for(int j = 5;j >= 0;j--){
         //       DB p1,p2;
                dp[i][j] = gp * dp[i+1][j] + (1.0 - gp) * dp[i][j+1];
            //    if(i + 1 >= j + 2 && i + 1 >= 6) p1 = 1.0;
           //     else if(i + 3 <= j && j <= 6) p1 = 0.0;
          //      else p1 = dp[i+1][j];

           //     if(i  >= j + 3 && i >= 6) p2 = 1.0;
           //     else if(i + 2 <= j + 1 && j + 1 >= 6) p2 = 0.0;
           //     else p2 = dp[i][j+1];
           //     dp[i][j] = gp * p1 + (1.0 - gp) * p2;
            }
        DB sp = dp[0][0];
        init();
        for(int i = 0; i < 2; i++) dp[2][i] = 1.0;
        for(int i = 1; i >= 0; i--)
            for(int j = 1; j >= 0; j--){
                dp[i][j] = dp[i+1][j] * sp + dp[i][j+1] * (1.0 - sp);
            }
        DB mp = dp[0][0];
        printf("%.11f %.11f %.11f\n",gp,sp,mp);
    }
    return 0;
}