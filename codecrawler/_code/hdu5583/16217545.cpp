#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define maxn 100005
#define ll long long
struct node
{
    ll flag;
    ll len;
}p[maxn];
char s[maxn];
ll max(ll a, ll b)
{
    return a>b?a:b;
}
int main()
{
    ll up, sum;
    int t, n, r, k, len, i;
    scanf("%d", &t);
    k = 1;
    while(t--)
    {
        scanf("%s", s);
        len = strlen(s);
        r = 0;
        p[r].flag = s[0] - 48;
        p[r].len = 1;
        for(i = 1;i < len;i++)
        {
            if(s[i]-48==p[r].flag)
                p[r].len++;
            else
            {
                r++;
                p[r].flag = s[i]-48;
                p[r].len = 1;
            }
        }
        up = 0;
        for(i = 0;i <= r;i++)
            up += p[i].len*p[i].len;
        sum = up;
        //printf("--%lld\n", up);
        for(i = 0;i <= r;i++)
        {
            {
                if(p[i].len - 1 > 0)//å·¦å³éä¸ä¸ª
                {
                    if(i - 1 >=0)
                    {
                        ll New = (p[i].len-1)*(p[i].len-1)+(p[i-1].len+1)*(p[i-1].len+1);
                        ll old = (p[i].len)*(p[i].len)+(p[i-1].len)*(p[i-1].len);
                        up = max(up, sum-old+New);
                    }
                    else if(i + 1 <= r)
                    {
                        ll New = (p[i].len-1)*(p[i].len-1)+(p[i+1].len+1)*(p[i+1].len+1);
                        ll old = (p[i].len)*(p[i].len)+(p[i+1].len)*(p[i+1].len);
                        up = max(up, sum-old+New);
                    }
                }
                else //å·¦å³å¨é
                {
                    //printf("%lld\n", up);
                    ll New = 1;
                    ll old = (p[i].len)*(p[i].len);
                    //printf("----%lld %lld\n", New, old);
                    if(i - 1 >= 0)
                    {
                        New += (p[i-1].len);
                        old += (p[i-1].len)*(p[i-1].len);
                    }
                    //printf("--%lld %lld\n", New, old);
                    if(i + 1 <= r)
                    {
                        New += (p[i+1].len);
                        old += (p[i+1].len)*(p[i+1].len);
                    }
                    //printf("%lld\n", New);
                    up = max(up, sum-old+New*New);
                    //printf("---%lld\n", up);
                }
            }
        }
        printf("Case #%d: %lld\n",k++, up);
    }
}
