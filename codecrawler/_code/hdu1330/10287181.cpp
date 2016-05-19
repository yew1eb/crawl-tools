#include<stdio.h>
#include<math.h>
int main()
{
    int n,i,flag=0;
    double sum;
//getchar();
        if(flag==0)
            printf("# Cards  Overhang\n");
    while(scanf("%d",&n)!=EOF)
{
    
        sum=0.0;
        for(i=1;i<=n;i++)
            sum=sum+1.0/(2*i);
    
    
   printf("%5d     %0.3lf\n",n,sum);
}
return 0;
}