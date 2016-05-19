#include<stdio.h>
void show(int a)
{
    int i = 1,n = 0;
    while(i <= a && a != 1)
    {
        i++;
       while(a % i == 0)
       {
          a /= i; n += 1;
          printf(n == 1 ? "%d" : "*%d",i);
       }
       
    } 
    printf("\n");
}
int main()
{
    int x;
    while(~scanf("%d",&x))
        show(x);
    return 0 ;
}