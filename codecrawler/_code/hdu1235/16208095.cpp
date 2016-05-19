#include<stdio.h>
int a[1100];
int main()
{
    int n,t,i,temp;
    while(scanf("%d",&n),n)
    {
        temp=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        scanf("%d",&t);
        for(i=0;i<n;i++)
        {
            if(a[i]==t)
            temp++;
        }
        printf("%d\n",temp);
    }
    
    
    return 0;
}
