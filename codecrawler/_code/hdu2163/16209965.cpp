#include<stdio.h>
#include<string.h>
char a[60];
int main()
{
    int t,len,i,j,m=1,b,c,d;
    while(scanf("%s",a)!=EOF)
    {
        if(!strcmp(a, "STOP")) break;
        printf("#%d: ",m++);
        b=c=d=0;
        len=strlen(a);
        if(len==1)    {printf("YES\n");continue;}
        t=len/2;
        if(len%2==0)
        {
            for(i=0;i<t;i++)
            {
                if(a[i]==a[len-1-i])
                b++;
            }
            if(b==t)  printf("YES");
            else    printf("NO");
        }
        
        
        else
        {
            for(i=0;i<=t;i++)
            {
                if(a[i]==a[len-1-i])
                c++;
            }
            if(c-1==t)   printf("YES");
            else   printf("NO");
        }
        printf("\n");
    }
    return 0;
}
