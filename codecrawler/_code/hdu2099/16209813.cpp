#include<stdio.h>
int main()
{
    int n,m,i,k,count,a[101];
    while(~scanf("%d %d",&n,&m)&&(n,m))
    {
        count=0;
        for(k=0,i=0;i<100;i++)
        {
            if((n*100+i)%m==0)
            {
                a[k++]=i;
                count++;
                continue;
            }
        }
        for(i=0;i<=count-1;i++)
        {
            if(i==0) printf("%02d",a[0]);
            else printf(" %02d",a[i]);
        }
        printf("\n");
    }
    return 0;
}