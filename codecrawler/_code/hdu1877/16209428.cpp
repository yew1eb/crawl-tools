#include <stdio.h>
int m;
void Ck(int n)
{
    if(n>=m)
        Ck(n/m);
    printf("%d",n%m);
}
int main()
{
    int A,B;
    unsigned int C;
    while(scanf("%d",&m),m)
    {
        scanf("%d%d",&A,&B);
        C = A+B;
        Ck(C); 
        printf("\n");
    }
    return 0;
}
