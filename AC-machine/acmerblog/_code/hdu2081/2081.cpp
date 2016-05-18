#include<stdio.h>
int main()
{
    int n,i;
    char a[12];
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",a);
        printf("6%s\n",a+6);
    }
}