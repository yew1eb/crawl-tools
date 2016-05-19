#include"stdio.h"
#include"math.h"
#include"string.h"


int main()
{
    int x1,y1,x2,y2,c1,c2;
    int len;
    int i;
    int min,max;
    double t;
    int ans;


    while(scanf("%d",&len),len)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        c1=(y1-y2)*x1;
        c2=(x1-x2)*y1;


        if(abs(x2)>len || abs(y2)>len)    {printf("Out Of Range\n");continue;}
        if(x1==x2 || y1==y2)            {printf("No\n");continue;}


        min=x1>x2?x2:x1;
        max=x1>x2?x1:x2;
        ans=0;
        for(i=min+1;i<max;i++)
        {
            t=((y1-y2)*i-c1+c2)*1.0/(x1-x2);
            if((int)t==t)    {ans=1;break;}
        }
        if(ans)    printf("No\n");
        else    printf("Yes\n");
    }
    return 0;
}