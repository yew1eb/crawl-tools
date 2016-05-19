#include<stdio.h>
int main()
{
    int i,j,c,n; 
    scanf("%d",&c);
    while(c--)
    {
        scanf("%d",&n);
        if(n==1) printf("1\n");
        else
        {
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=n;j++)
                {
                    if(j==1) printf("%d",i*j);
                    else  printf(" %d",i*j); 
                }
            printf("\n"); 
            } 
        } 
    } 
    return 0; 
}