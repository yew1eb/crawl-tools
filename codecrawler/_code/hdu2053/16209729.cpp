#include<stdio.h>
#include<math.h>
int main ()
{
    int n;
    double s;
    while(scanf("%d",&n) != EOF)
    {
        s = sqrt(n*1.0);
        if(s == (int)s ) printf("1\n");
        else printf("0\n");
    }
    return 0;
}
