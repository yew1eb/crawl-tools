#include<cstdio>
int main()
{
    int i,j;
    int f[33]={-1};
    for(i=1;i<=30;i++) f[i]=f[i-1]*2;
    while(~scanf("%d",&i))
    {
        puts("99 87");
        for(i=1;i<30;i++)
        {
            printf("%d %d 0\n",i,i+30);
            printf("%d %d %d\n",i,i+1,f[29-i]);
            printf("%d %d %d\n",i+30,i+1,f[30-i]);
        }
    }
    return 0;
}
