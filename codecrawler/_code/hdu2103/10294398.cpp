#include "stdio.h"
#include "math.h"
int main()
{
    int t;
    int n,m;
    int count;
    int num;
    int flag;
    int i;
    double sum;
    scanf("%d",&t);
    while(t--)
    {
        count=0;
        flag=0;
        sum=0;
        scanf("%d%d",&n,&m);
        for(i=1;i<=m;i++)
        {
            scanf("%d",&num);
            if(flag)
                count++;//sum+=pow(2,count);
            else if(i>n)
                count++; //sum+=pow(2,count);
            if(i<=n&&num)
                flag=1;
        }
            sum=pow(2,count)-1;
        printf("%.lf RMB\n",sum*10000);
    }
    return 0;
}
