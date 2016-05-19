#include <stdio.h>
#include <algorithm>
using namespace std;
int T[1002],K[1002],n,win,lose;
void read()
{
    for(int i=0;i<n;i++)
        scanf("%d",&T[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&K[i]);
    sort(T,T+n);
    sort(K,K+n);
}
void race()
{
    win = lose =0;
    int t_slow=0,t_fast=n-1;
    int k_slow=0,k_fast=n-1;
    while(t_slow <= t_fast)
    {
        if(T[t_slow] > K[k_slow])        //æåµ1
        {
            win++;
            t_slow++;
            k_slow++;
        }
        else if(T[t_slow] < K[k_slow])   //æåµ2
        {
            lose++;
            t_slow++;
            k_fast--;
        }
        else                             //æåµ3
        {
            if(T[t_fast] > K[k_fast])    //åå«æ¾æ°´ï¼è®©å¥æ¯å®è¿åº
            {
                win++;
                t_fast--;
                k_fast--;
            }
            else                         //1ã2ã3ãæ¾
            {
                if(T[t_slow] < K[k_fast])//å¥ä¸ä¸å®ä¼è¾å¦~~~
                    lose++;
                t_slow++;
                k_fast--;
            }
        }
    }
}
int main()
{
    //freopen("1","r",stdin);
    //freopen("2","w",stdout);
    while(scanf("%d",&n),n)
    {
        read();
        race();
        printf("%d\n",200*(win-lose));
    }
    return 0;
}
