#include<stdio.h>
main()
{
    int n,a,b,c,m;
    while(scanf("%d",&n)!=EOF)
    {
        m=0;
        for(a=1;a<=100;a++)
        {
            for(b=a;b<=100;b++)
            {
                for(c=b;c<=100;c++)
                {
                    if(n==a*a+b*b+c*c)
                    {
                        printf("%d %d %d\n",a,b,c);
                        m=1;
                        break;
                    }    
                }
                if(m==1) break;
            }
            if(m==1) break;
        }
    }
}