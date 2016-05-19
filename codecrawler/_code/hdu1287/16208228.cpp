#include<stdio.h>
int main()
{
   int n,i,j,a[1001];
   char c;
   while(scanf("%d",&n)!=EOF)
   {
      for(i=0;i<n;i++)
          scanf("%d",&a[i]);
      for(i=0+'A';i<=0+'Z';i++)
      {
         for(j=0;j<n;j++)
         {
            c=i^a[j];
            if(c<'A'||c>'Z') break;
         }
         if(j==n) break;
      }
      for(j=0;j<n;j++)
          putchar(a[j]^i);
      printf("\n");
   }
   return 0;
}