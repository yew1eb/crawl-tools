#include <stdio.h>
#include <string.h>

int main()
{
    int t;
    double n,m;
    char str[20];
    scanf("%d",&t);
    for(int i = 1;i<=t;i++)
    {
        scanf("%lf %s",&n,str);
        if(!strcmp(str,"kg"))
        {
            m = n*2.2046;
            printf("%d %.4lf lb\n",i,m);
        }
        else if(!strcmp(str,"g"))
        {
           m = n*3.7854;
           printf("%d %.4lf l\n",i,m);
        }
        else if(!strcmp(str,"lb"))
        {
            m = n*0.4536;
            printf("%d %.4lf kg\n",i,m);
        }
        else if(!strcmp(str,"l"))
        {
            m = n*0.2642;
            printf("%d %.4lf g\n",i,m);
        }
    }

    return 0;
}