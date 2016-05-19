#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<ctime>

using namespace std;

int INT_cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}
int compare(int n, int m)
{
    int ct = 0;
    int num_n, num_m;
    while(n || m)
    {
        num_n = n % 2;
        num_m = m % 2;
        m /= 2;
        n /= 2;
        if(num_n != num_m)
            ++ct;
    }
    return ct;
}
int main()
{
#ifdef test
    freopen("in.txt", "r", stdin);
#endif
    int t, m, n;
    int M[102], N[102];
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &m, &n);
        for(int i = 0; i < m; i++)
            scanf("%d", &M[i]);
        for(int i = 0; i < n; i++)
            scanf("%d", &N[i]);
        qsort(M, m, sizeof(M[0]), INT_cmp);
        for(int i = 0; i < n; i++)
        {
            int min = 0x7FFFFFFF,min_num;
            for(int j = 0; j < m; j++)
            {
                int ans = compare(N[i], M[j]);
                if(ans < min)
                {
                    min = ans;
                    min_num = M[j];
                }
            }
            printf("%d\n",min_num);
        }
    }
    return 0;
}