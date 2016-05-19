/*é¢æï¼ ä¸¤ä¸ªç´ æ° p, q å¹¶ä¸ pq <= m and a / b <= p / q <= 1,
4 < m <= 100000 and 1 <= a <= b <= 1000.æ±æå¤§çq,på¼
*/

#include <stdio.h>
#include <string.h>
const int N = 10005;
int prime[N],p,q,l = 0,s[N];

void set()
{
    int i,j;
    memset(prime,0,sizeof(prime));
    for(i = 2; i<N; i++)
    {
        if(prime[i])
            continue;
        for(j = i+i; j<N; j+=i)
            prime[j] = 1;
        s[l++] = i;
    }
}


int main()
{
    int m,tp,tq,t;
    double a,b,max,lim;
    set();
    while(~scanf("%d%lf%lf",&m,&a,&b),m!=0||a!=0||b!=0)
    {
        max = 0;
        lim = a/b;
        for(p = l-1; p>=0; p--)
        {
            for(q = p; q>=0; q--)
            {
                if(s[p]>m || s[q]>m || s[q]*s[p]>m || (double)s[q]/s[p]<lim)
                    continue;
                if(s[p]*s[q]>max)
                {
                    max = s[p]*s[q];
                    tp = s[p];
                    tq = s[q];
                }
            }
        }
        if(tp>tq)
        {
            t = tp;
            tp = tq;
            tq = t;
        }
        printf("%d %d\n",tp,tq);
    }

    return 0;
}
