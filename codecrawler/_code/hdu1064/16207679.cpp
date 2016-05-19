#include <stdio.h>

int main()
{
    float sum = 0;
    float aver = 0;
    float a;
    for(int i = 0; i < 12;i++)
    {
         scanf("%f",&a);
         sum += a;
    }
    aver = sum/12;
    printf("$%.2f\n",aver);
    return 0;
}
