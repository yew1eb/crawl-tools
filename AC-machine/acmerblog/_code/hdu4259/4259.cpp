#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

long long gcd(long long a,long long b)
{
    return b?gcd(b,a%b):a;
}

int main()
{
    freopen("test.txt","r",stdin);
    int N,K;
    while (scanf("%d%d",&N,&K),N|| K)
    {
        static int rec[810][810];
        static int a[810];
        int num = 1;
       for (int i = 1;;i++)
        {
            for (int j = 1;j <= K;j++)
            {
                rec[i][j] = num++;
                if (num >N) break;
            }
            if (num > N) break;
        }
        num = 1;
        for (int i = 1;i <= K;i++)
        {
            for (int j = (N-i)/K+1;j >= 1;j--)
            {
                a[num++] = rec[j][i];
            }
        }

        static bool vd[810];
        memset(vd,0,sizeof(vd));
        long long ans = 1;
        for (int i = 1;i <= N;i++)
        {
            if (vd[i]) continue;
            num = i;
            long long count = 0;
            do
            {
                num = a[num];
                vd[num] = true;
                count++;
            }
            while (num != i);
            ans = ans/gcd(ans,count)*count;
        }
        printf("%I64d\n",ans);
    }

    return 0;
}
/*
        for (int i = 1;i <= K;i++)
        {
            for (int j = (N- i)/K *K + i;j > 0;j -= K)
            {
                a[num++] = j;
            }
        }
*/
