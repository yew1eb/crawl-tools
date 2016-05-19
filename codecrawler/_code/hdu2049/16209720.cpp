#include <stdio.h>

__int64 fact(int n)
{
    if (n <= 1)
        return 1;
    else
        return n*fact(n-1);
}

int main()
{
    int i, n, m, C;
    __int64 A[21] = {0, 0, 1},
            B[21] = {0, 0, 1};
    for (i=3; i<21; i++)
    {//å¦ææiä¸ªè·ªææ¿çæ°éï¼è¿äºæ°éæA[i]ç§éæ©
        B[i] = A[i-2] + (i-2) * B[i-1];
        A[i] = (i-1) * B[i];
    } 
    for (i=0; i<21; i++)
        B[i] = fact(i);//å­èµ·æ¥å¾ç¨
    scanf("%d", &C);
    for (i=0; i<C; i++)
    {
        scanf("%d%d", &n, &m);
        printf("%I64d\n", B[n]/(B[n-m]*B[m])*A[m]);//ä¸ç¥éè¿éç®ä¸ç®ä¸ªæå·§ï¼åæ­£æ¯ç´æ¥è°ç¨fact()å½æ°å¿«å¾å¤
    }
    return 0;
}