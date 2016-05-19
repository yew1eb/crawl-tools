#include<stdio.h>
#include<math.h>
#define max 302
int num1[300];
int num2[300];
void init()
{
    for(int i=0; i<max; i++)
    {
        num1[i]=1;
        num2[i]=0;
    }
    for(int i=2; i<=17; i++)
    {
        for(int j=0; j<max; j++)
            for(int k=0; k+j<max; k+=i*i)//æ³¨æ:è¿éæ¯å¹³æ¹ã
            {
                num2[k+j]+=num1[j];
            }
        for(int i=0; i<max; i++)
        {
            num1[i]=num2[i];
            num2[i]=0;
        }
    }

}
int main()
{
    int n;
    init();
    while(scanf("%d",&n),n)
    {
        printf("%d\n",num1[n]);
    }
    return 0;
}
