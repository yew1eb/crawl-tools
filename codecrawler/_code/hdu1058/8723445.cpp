#include <stdio.h>
#include <string.h>
#define INF 0xfffffff
const int maxn =6000;
int f[maxn];

int min(int a, int b, int c, int d)
{
    if(a>b) a = b;
    if(a>c) a = c;
    if(a>d) a = d;
    return a;
}
void init()
{
    int i, x1, x2, x3, x4, num1, num2, num3, num4;
    f[1] = 1;
    x1 = x2 = x3 = x4 = 1;
    for(i=2; i<=maxn; i++)
    {
        num1 = 2*f[x1];
        num2 = 3*f[x2];
        num3 = 5*f[x3];
        num4 = 7*f[x4];
        f[i] = min(num1, num2, num3, num4);
        if(f[i]==num1) x1++;
        if(f[i]==num2) x2++;
        if(f[i]==num3) x3++;
        if(f[i]==num4) x4++;
    }
}

int main()
{
    int n;
    init();
    while(scanf("%d",&n),n)
    {
        if(n%10==1&&n%100!=11)
            printf("The %dst humble number is %d.\n",n,f[n]);
        else if(n%10==2&&n%100!=12)
            printf("The %dnd humble number is %d.\n",n,f[n]);
        else if(n%10==3&&n%100!=13)
            printf("The %drd humble number is %d.\n",n,f[n]);
        else
            printf("The %dth humble number is %d.\n",n,f[n]);
    }
    return 0;
}
