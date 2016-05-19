#pragma warning(disable:4996)  
#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
#include <string>  
#include <cstring> 
#include <queue>
using namespace std;

const int maxn = 1005;

int n, m;
double val[maxn][maxn];

int main()
{
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
    

    while (scanf("%d%d", &n, &m) != EOF)
    {
        for (int i = 1; i <= n; i++)
        {
            double sum = 0;
            for (int j = 1; j <= m; j++)
            {
                scanf("%lf", &val[i][j]);
                sum += val[i][j];
            }
            for (int j = 1; j <= m; j++)
            {
                val[i][j] = val[i][j] / sum;
            }
        }
        double ans = 0;
        for (int i = 1; i <= m; i++)
        {
            double sum = 0;
            for (int j = 1; j <= n; j++)
            {
                sum += val[j][i];
                ans += val[j][i];
                ans -= val[j][i] * val[j][i];
            }
            ans += (sum*sum);
        }
        printf("%.2lf\n", ans);
    }
    //system("pause");
    return 0;
}
