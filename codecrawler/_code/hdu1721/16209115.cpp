#include"stdio.h"
int main()
{
    int num[8];
    int i;
    while(scanf("%d",&num[0]),num[0]!=-1)
    {
        for(i=1;i<8;i++)    scanf("%d",&num[i]);


        for(i=1;i<4;i++)    {num[i]-=num[i-1];num[i-1]=0;}
        num[7]-=num[3];
        num[3]=0;
        for(i=6;i>3;i--)    {num[i]-=num[i+1];num[i+1]=0;}


        if(num[4])    printf("Sorry,it can't be cleared away!\n");
        else        printf("All the seeds can be cleared away!\n");
    }
    return 0;
}