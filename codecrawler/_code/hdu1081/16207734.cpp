#include"stdio.h"
#include"string.h"
int main()
{
    int num[105][105];
    int i1,i2,i_temp,l;
    int temp[105];
    int n;
    int max;
    int temp0;
    while(scanf("%d",&n)!=-1)
    {
        for(i1=0;i1<n;i1++)
        for(l=0;l<n;l++)
            scanf("%d",&num[i1][l]);


        max=0;
        for(i2=0;i2<n;i2++)
        {
            for(i1=0;i1<=i2;i1++)
            {
                /*****/                  //åç¼©
                for(l=0;l<n;l++)
                {
                    temp0=0;
                    for(i_temp=i1;i_temp<=i2;i_temp++)    temp0+=num[i_temp][l];
                    temp[l]=temp0;
                }
                /*****/


                if(temp[0]>max)    max=temp[0];
                for(l=1;l<n;l++)
                {
                    if(temp[l-1]>0)    temp[l]+=temp[l-1];
                    if(temp[l]>max)    max=temp[l];
                }
            }
        }


        printf("%d\n",max);
    }
    return 0;
}