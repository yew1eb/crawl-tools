#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    int tian[1005],king[1005],i,j,sum;

    while(~scanf("%d",&n),n)
    {
        sum = 0;
        for(i = 0; i<n; i++)
            scanf("%d",&tian[i]);
        for(i = 0; i<n; i++)
            scanf("%d",&king[i]);
        sort(king,king+n);
        sort(tian,tian+n);
        int t_max,t_mid,t_min,k_max,k_min,k_mid;
        t_max = k_max = n-1;
        t_min = k_min = 0;
        while(t_min <= t_max && k_min <= k_max)
        {
            if(tian[t_max] > king[k_max])//ç°å¿çæå¿«ä¸é½çæå¿«æ¯ï¼ç°å¿å¿«åPKæ;
            {
                sum+=200;
                k_max--;
                t_max--;
            }
            else if(tian[t_max] < king[k_max])//ç°å¿æ¢åç¨ç°å¿ææ¢çPKé½çæå¿«;
            {
                sum-=200;
                t_min++;
                k_max--;
            }
            else//å¿«é©¬ç¸ç­çè¯ï¼ç¨ç°å¿çææ¢ä¸é½çææ¢æ¯ï¼ç°å¿å¿«åPKæï¼ç°å¿æ¢åPKé½çæå¿«;
            {
                if(tian[t_min] > king[k_min])
                {
                    t_min++;
                    k_min++;
                    sum+=200;
                }
                else if(tian[t_min] < king[k_min])
                {
                    t_min++;
                    k_max--;
                    sum-=200;
                }
                else//æå¿«ä¸ææ¢é½ç¸ç­ï¼åç¨ç°å¿ææ¢PKæé½çæå¿«;
                {
                    if(tian[t_min] < king[k_max])
                        sum-=200;
                    t_min++;
                    k_max--;
                }
            }
        }
        printf("%d\n",sum);
    }

    return 0;
}
