#include<stdio.h>
int F(int n)
{
    if(n==7)
        return 5;
    else
        return 5+(n-7)/2;

}
int main()
{
    int i,j,n,num,k,x1,x2,l,q=5,p,u1,u2;
    char str;
    scanf("%d",&n);
    while(n--)
    {
        p=2;
        scanf("\n%c %d",&str,&num);
        p=p+(num-6)/6;
        q=F(num);
        j=num-q;
        k=(num-3)/2;
        if((num-3)%2==0)
        {
            x1=k;x2=k;
        }
        else
        if((num-3)%2!=0)
        {
            x1=k;x2=k+1;
        }
        if(num!=6&&num!=5)
        {
            for(u1=0;u1<p;u1++)
            printf(" ");
            for(i=0;i<j;i++)
                printf("%c",str);
            puts("");
            for(i=0;i<x1;i++)
            {
                for(u1=0;u1<p;u1++)
                printf("%c",str,str);
                for(l=0;l<j;l++)
                printf(" ");
                for(u2=0;u2<p;u2++)
                printf("%c",str,str);
                puts("");
            }
            for(u1=0;u1<p;u1++)
            printf(" ");
            for(i=0;i<j;i++)
                printf("%c",str);
            puts("");;
            for(i=0;i<x2;i++)
            {
                for(u1=0;u1<p;u1++)
                printf("%c",str,str);
                for(l=0;l<j;l++)
                printf(" ");
                for(u2=0;u2<p;u2++)
                printf("%c",str,str);
                puts("");
            }
            for(u1=0;u1<p;u1++)
            printf(" ");
            for(i=0;i<j;i++)
                printf("%c",str);
            puts("");
        }
        else
        if(num==6)
        {
           printf("  ");
            for(i=0;i<2;i++)
                printf("%c",str);
            puts("");
            for(i=0;i<1;i++)
            {
                printf("%c%c",str,str);
                for(l=0;l<2;l++)
                printf(" ");
                printf("%c%c",str,str);
                puts("");
            }
            printf("  ");
            for(i=0;i<2;i++)
                printf("%c",str);
            puts("");;
            for(i=0;i<2;i++)
            {
                printf("%c%c",str,str);
                for(l=0;l<2;l++)
                printf(" ");
                printf("%c%c",str,str);
                puts("");
            }
            printf("  ");
            for(i=0;i<2;i++)
                printf("%c",str);
            puts("");
        }
        else
        if(num==5)
        {
           printf(" ");
            for(i=0;i<1;i++)
                printf("%c",str);
            puts("");
            for(i=0;i<1;i++)
            {
                printf("%c",str,str);
                for(l=0;l<1;l++)
                printf(" ");
                printf("%c",str,str);
                puts("");
            }
            printf(" ");
            for(i=0;i<1;i++)
                printf("%c",str);
            puts("");;
            for(i=0;i<1;i++)
            {
                printf("%c",str,str);
                for(l=0;l<1;l++)
                printf(" ");
                printf("%c",str,str);
                puts("");
            }
            printf(" ");
            for(i=0;i<1;i++)
                printf("%c",str);
            puts("");
        }
        if(n)
        puts("");
    }
    return 0;
}
