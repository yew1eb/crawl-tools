#include <cstdio>
#include <cstring>
const int MAXN = 40000;
bool isprim[MAXN];
int prim[MAXN];
int main()
{
    for(int i = 2; i < MAXN; i++)
    if(!isprim[i])
    {
        for(int j = i * i; j < MAXN; j += i)
        {
            isprim[j] = 1;
        }
    }
    int num = 0;
    for(int i = 2; i < MAXN; i++)
    if(!isprim[i])  prim[++num] = i;//ç´ æ°çç­é
    //printf("%d\n",num);

    int T;
    scanf("%d", &T);
    int cas = 1;
    while(T--)
    {
        int n;
        scanf("%d", &n);
        long long sum = 1;
        int fir = 1;
        while(fir <= num && prim[fir] <= n)
        {
            int cnt = 0;
            if(n % prim[fir] == 0)
            {
                while(n % prim[fir] == 0)
                {
                    cnt ++;
                    n = n / prim[fir];
                }
                sum = sum * (1 + 2 * cnt);
            }
            fir ++;
        }
        if(n > 1)  sum = sum * 3;
        printf("Scenario #%d:\n",cas++);
        printf("%I64d\n\n",(sum + 1) >> 1);
    }
    return 0;
}
