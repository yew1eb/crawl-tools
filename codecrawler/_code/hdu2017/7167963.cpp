#include<stdio.h>
int main()
{
    int n, i, sum;
    char c;
    scanf("%d\n",&n);
    for(i=1;i<=n;i++)
    {
       sum=0;              
       scanf("%c",&c);
       while(c!='\n') {if(c>=48&&c<=57) sum++;scanf("%c",&c);}
       printf("%d\n",sum);
    }
    return 0;
}
  
