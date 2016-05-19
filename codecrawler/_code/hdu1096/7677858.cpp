#include<stdio.h>
int main()
{
    int n, m, i, x, sum;
    //freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
    scanf("%d",&n);
    int first=1;
    while(n--)
    {
         scanf("%d",&m);
         sum = 0;
         for(i=1;i<=m;i++)
         {
             scanf("%d",&x);
             sum+=x;
         }
         if(first) first =0;
         else printf("\n");
         printf("%d\n",sum);
   }
   return 0;
}
         
