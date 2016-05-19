#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    double b[120], c[60];
    int flag[60];
    int n, i, j, T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i = 0; i < n; i++)
            scanf("%lf",&c[i]);
        sort(c, c+n);
        int m = 0;
        for(i = 1; i < n; i++)
        {
            b[m++] = c[i] - c[i-1];
            b[m++] = (c[i] - c[i-1]) / 2;
        }
        sort(b, b+m);
        double ans;
        for(i = m - 1; i >= 0; i--)
        {
            memset(flag, 0, sizeof(flag));
            flag[0] = 1;
            double tmp = b[i];
            for(j = 1; j < n - 1; j++)
            {
                if(c[j] - tmp < c[j-1] && c[j] + tmp > c[j+1])  //å¾å·¦å¾å³é½ä¸è¡
                    break;
                if(c[j] - tmp >= c[j-1])
                {
                    if(flag[j-1] == 2) // åä¸ä¸ªå¾å³
                    {
                        if(c[j] - c[j-1] == tmp) flag[j] = 1;  //ä¸¤ä¸ªç¹ä½ä¸ºçº¿æ®µçä¸¤ä¸ªç«¯ç¹
                        else if(c[j] - c[j-1] >= 2 * tmp) flag[j] = 1; //ä¸ä¸ªå¾å·¦ï¼ä¸ä¸ªå¾å³
                        else if(c[j] + tmp <= c[j+1]) flag[j] = 2; //åªè½å¾å³
                        else break;
                    }
                    else flag[j] = 1;
                }
                else if(c[j] + tmp <= c[j+1])
                    flag[j] = 2;
            }
            if(j == n - 1)
            {
                ans = tmp;
                break;
            }
        }
        printf("%.3lf\n", double(ans));
    }
    return 0;
}