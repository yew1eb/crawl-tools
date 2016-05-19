#include<stdio.h>

main()
{
    int m1,m2,i,r1,r2,r3;
    char str[201];
    while(scanf("%d %d",&m1,&m2)!=EOF)
    {
        r1=r2=r3=0;
    scanf("%s",&str);
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]=='A')
        {
            r1=m1;
        }
        if(str[i]=='B')
        {
            r2=m2;
        }
        if(str[i]=='C')
        {
            m1=r3;
        }
        if(str[i]=='D')
        {
            m2=r3;
        }
        if(str[i]=='E')
        {
            r3=r1+r2;
        }
        if(str[i]=='F')
        {
            r3=r1-r2;
        }
    }
    printf("%d,%d\n",m1,m2);
    }
}