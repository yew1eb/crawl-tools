#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
#define MAXN 1010
bool is_prime[MAXN];
int prime[170];

void pre() //ç´ æ°æè¡¨
{
    int i, j, k = 0;
    memset(is_prime, 1, sizeof(is_prime));
    for(i = 2; i < 35; ++i)
    {
        if(is_prime[i])
            for(j = i; j * i < MAXN; ++j)
                is_prime[i * j] = 0;
    }
    for(i = 2; i < MAXN; ++i)
        if(is_prime[i])
            prime[k++] = i;
}

int main()
{
    int m, n, i,t = 1,count;
    int sum;
    pre();
    while(scanf("%d%d", &m, &n) != EOF)
    {
        sum = 1;
        for(i = 0; i < 169; ++i) //ç®æ°åºæ¬å®çæ¨è®º
        {
            count = 0;
            while(m % prime[i] == 0 && m != 1)
            {            
                m /= prime[i];
                count++;
            }
            count =( count * n + 1) % 10007;
            count=count * (count + 1) / 2 % 10007;
            sum = sum * (count * count % 10007) % 10007;
            if(m == 1) break;           
        }
        if(m != 1)
        {
            count=(n + 1) % 10007;
            count=count * (count + 1) / 2 % 10007;
            sum = sum * (count * count % 10007) % 10007;
        }
        printf("Case %d: %d\n", t++, sum);
    }
    return 0;
}
        