#include <stdio.h>
#include <math.h>
#define N 1000000
int mark[1001];
void init()
{
    int i, j , s, k;
    for(i=2; i<=N; i++)
    {
        s = 1;
        k = (int)sqrt(i);
        for(j=2;j<=k; j++)
        if(i%j==0)
        {
            if(j*j==i ) s +=j;
            else s+=j + i/j;
            if(s>1000) break;
        }
        if(s<1001) mark[s]=1;
    }
}
int main()
{
    int T, n;
    init();
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        if(mark[n])printf("no\n");
        else printf("yes\n");
    }
    return 0;
}
