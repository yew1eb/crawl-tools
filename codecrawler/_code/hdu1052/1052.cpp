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
        if(T[t_slow] > K[k_slow])        //情况1
        {
            win++;
            t_slow++;
            k_slow++;
        }
        else if(T[t_slow] < K[k_slow])   //情况2
        {
            lose++;
            t_slow++;
            k_fast--;
        }
        else                             //情况3
        {
            if(T[t_fast] > K[k_fast])    //先别放水，让哥比完这场
            {
                win++;
                t_fast--;
                k_fast--;
            }
            else                         //1、2、3、放
            {
                if(T[t_slow] < K[k_fast])//哥不一定会输哦~~~
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