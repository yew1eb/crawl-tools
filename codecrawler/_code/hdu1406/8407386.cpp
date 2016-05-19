#include <stdio.h>
#include <math.h>
int mark[10002];
void sieve()
{
    int i, j, k, sum;
    for(i=2;i<=10000; i++)
    {
        k = (int)sqrt(i);
        sum = 1;
        for(j=2;j<=k; j++)
        if(i%j==0)
        {
            if(j*j==i) sum +=j;
            else sum +=j + i/j;
        }
        if(sum == i) mark[i] = 1;
    }
}
int main()
{
    int T, num1, num2,tmp;
    sieve();
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&num1, &num2);
        if(num1>num2) {tmp=num1;num1=num2;num2 = tmp;}
        int tot = 0;
        for(int i=num1;i<=num2; i++)
            if(mark[i]) tot++;
        printf("%d\n",tot);
    }
    return 0;
}



