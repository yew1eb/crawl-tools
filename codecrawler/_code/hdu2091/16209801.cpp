#include<stdio.h>
int main()
{
    int i,j,n;
    char ch[2];
    scanf("%s",ch);
    while(ch[0]!='@')
    {
        scanf("%d",&n);
        if(n>1)
        {
         for(j=1;j<n;j++)
             printf(" ");
         printf("%c\n",ch[0]);
         for(i=1;i<n-1;i++)
         {
             for(j=1;j<n-i;j++)
                 printf(" ");
             printf("%c",ch[0]);
             for(j=0;j<2*i-1;j++)
                 printf(" ");
             printf("%c\n",ch[0]);
         }
         for(j=0;j<2*n-1;j++)
             printf("%c",ch[0]);
         printf("\n");
         
        }
        else printf("%c\n",ch[0]);
        scanf("%s",ch);
         if(ch[0]!='@')
             printf("\n");
    }
    return 0;
}
