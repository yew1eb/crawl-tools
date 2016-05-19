#include<stdio.h>
int main()
{
    int n,i,a,b,t;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d%d",&a,&b,&t);
        if(t%a>t%b)
            printf("Xiangsanzi!\n");
        else if(t%a<t%b)
            printf("Sempr!\n");
        else
            printf("Both!\n");
    }
    return 0;
}
