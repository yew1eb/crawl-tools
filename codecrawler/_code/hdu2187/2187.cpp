#include <stdio.h>
#include <stdlib.h>
struct node
{
    int cost,weight;
};
int cmp (const void *a, const void *b)
{
    return (*(node *)a).cost - (*(node *)b).cost;
}
int main()
{
    int n;
    int kinds,i;
    double ans,temp,money;
    node data[1000];
    scanf("%d",&n);
    while(n--)
    {
        ans=0;
        scanf("%lf%d",&money,&kinds);
        for(i=0;i<kinds;i++)
        scanf("%d%d",&data[i].cost,&data[i].weight);
        qsort(data,kinds,sizeof(node),cmp);
        for(i=0;i<kinds;i++)
        {
            if(money>=data[i].cost*data[i].weight)
            {
                ans+=(double)data[i].weight;
                money-=(double)data[i].cost*data[i].weight;
            }
            else
            {
                temp=(double)money/data[i].cost;
                ans+=temp;
                money-=(double)temp*data[i].cost;
            }
        }
        printf("%.2lf\n",ans);
    }
    return 0;
}