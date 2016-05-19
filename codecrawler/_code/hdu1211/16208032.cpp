#include<stdio.h>
#include<math.h>
int main()
{
    int p,q,e,n,d,m,c,fn,i,j,t;
    while(scanf("%d %d %d %d",&p,&q,&e,&t)!=EOF)
    {
            n=p*q;
            fn=(p-1)*(q-1);
            d=fn/e+1;
            while((d*e)%fn!=1) d++;
            for(i=0;i<t;i++)
            {
                scanf("%d",&c);
                m=1;
                for(j=0;j<d;j++)
                {
                    m*=c;
                    m%=n;
                }
                printf("%c",m);
            }
            printf("\n");
    }
    return 0;
}