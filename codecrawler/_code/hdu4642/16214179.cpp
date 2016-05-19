#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

int main()
{
   int ncase;
   scanf("%d",&ncase);
   while(ncase--)
   {
       int n,m;
       scanf("%d%d",&n,&m);
       int i,j,x;
       for(i=0;i<n;i++)
       {
           for(j=0;j<m;j++)
           {
               scanf("%d",&x);
           }
       }
       if(x)
       printf("Alice\n");
       else
       printf("Bob\n");
   }
    return 0;
}
