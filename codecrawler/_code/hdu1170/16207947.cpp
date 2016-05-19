#include<stdio.h>
int main()
{
    int n,s,q,p;
    char ch;
    scanf("%d",&n);
    while(n--)
    {
        getchar();
        scanf("%c%d%d",&ch,&p,&q);
        if(ch=='+')
        {
            s=p+q;
            printf("%d\n",s);
        }
        else if(ch=='-')
        {
            s=p-q;
            printf("%d\n",s);
        }
        else if(ch=='*')
        {
            s=p*q;
            printf("%d\n",s);
        }
        else if(ch=='/')
        {
            if(p%q==0)
                printf("%d\n",p/q);
            else
                printf("%.2f\n",(float)p/q);
        }
        
    }
    
    return 0;
} 