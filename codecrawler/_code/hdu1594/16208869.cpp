#include<stdio.h>
#include<math.h>
int main()
{
    int n,i,SlopeMax,x1=1,y1,y2;
    while(scanf("%d",&n)!=EOF)
    {
        SlopeMax=(-2147483647 - 1);//INT_MIN
        scanf("%d",&y2);
        for(i=1;i<n;++i)
        {
            y1=y2;
            scanf("%d",&y2);
            if( abs(y1-y2) > SlopeMax)
            {
                x1=i;
                SlopeMax=abs(y2-y1);
            }
        }
        printf("%d %d\n",x1,x1+1);
    }
    return 0;
}