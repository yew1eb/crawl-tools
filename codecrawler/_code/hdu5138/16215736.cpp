#include<stdio.h>
int main()
{
    int n,f;
    while(~scanf("%d",&n))
    {
        f=0;
        if(n-15>0) {if(f!=0) printf(" ");printf("%d",n-15);f++;}
        if(n-7>0) {if(f!=0) printf(" ");printf("%d",n-7);f++;}
        if(n-4>0) {if(f!=0) printf(" ");printf("%d",n-4);f++;}
        if(n-2>0) {if(f!=0) printf(" ");printf("%d",n-2);f++;}
        if(n-1>0) {if(f!=0) printf(" ");printf("%d",n-1);f++;}
        printf("\n");
    }
    return 0;
}