#include <stdio.h>
#include <string.h>
int main()
{
        int n, B, D, f, F, i, j, time_A, time_B, time_C, time_min;
        int time_sum[100];
        char menu[100];
        while(scanf("%d%d%d%d%d", &n, &B, &D, &f, &F)==5)
        {
                time_A = B + D + f;
                time_B = B + B + D +  D + F;
                time_C = B + B + B + D + D + D +  F + F;
                time_min = -1;
                for(i = 0; i < n; ++i)
                {
                        time_sum[i] = 0;
                        scanf("%s", menu);
                        for(j = 0; menu[j] != '\0'; ++j)
                        {
                                if(menu[j] == 'A')
                                time_sum[i] += time_A;
                                if(menu[j] == 'B')
                                        time_sum[i] += time_B;
                                if(menu[j] == 'C')
                                        time_sum[i] += time_C;
                        }
                        if(time_min == -1 || time_sum[i] < time_min)
                                time_min = time_sum[i];
                }
                printf("%d\n", time_min);
        }
        return 0;
}