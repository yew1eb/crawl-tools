#include<stdio.h>
int main()
{
    int n, i;
    int f[60];
    f[1]=1;f[2]=2;f[3]=3;
    for(i=4;i<55;i++)f[i]=f[i-1]+f[i-3];
    scanf("%d",&n);
    while(n!=0)
    {
        printf("%d\n",f[n]);
        scanf("%d",&n);
    }
    return 0;
}
  
