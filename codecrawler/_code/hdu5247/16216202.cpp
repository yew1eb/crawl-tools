#include<stdio.h>
#include<string.h>

int main ()
{
    bool mark[1001];
    short int num[10001] ,mkans[1005];

    int n ,m ,i ,j ,k;
    scanf("%d %d" ,&n ,&m);
    for(i = 1 ;i <= n ;i ++)
    scanf("%d" ,&num[i]);
    memset(mkans ,0 ,sizeof(mkans));
    for(i = 1;i <= n ;i ++)
    {
        memset(mark ,0 ,sizeof(mark));
        int max = num[i] ,min = num[i];
        mkans[1] ++;
        mark[num[i]] = 1;
        for(j = i + 1 ;j <= n;j ++)
        {
            if(max < num[j]) max = num[j];
            if(min > num[j]) min = num[j];
            if(mark[num[j]]++) break;
            if(max-min+1 > 1000) break;
            if(max - min == j - i) mkans[max-min+1]++;
        }
    }
    printf("Case #1:\n");
    while(m--)
    {
        scanf("%d" ,&k);
        printf("%d\n" ,mkans[k]);
    }
    return 0;
}
