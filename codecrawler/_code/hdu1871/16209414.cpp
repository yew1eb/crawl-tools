#include <stdio.h>
#include <stdlib.h>

int n;
struct node
{
    int No;
    int num;
    int price;
}hotel[1002];

int cmp(const void *a,const void *b)
{
    struct node *x=(node *)a;
    struct node *y=(node *)b;
    if(x->price-y->price) 
        return x->price-y->price;
    else
        return x->num-y->num;
}

void solve(int x)
{
    int i;
    for(i=0;i<n;i++)
        if (hotel[i].num>=x)
        {
            hotel[i].num-=x;
            printf("%d\n",hotel[i].No);
            return;
        }
    printf("sorry\n");
}

int main()
{
    int test,ind,t;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d %d %d",&hotel[i].No,&hotel[i].num,&hotel[i].price);
        qsort(hotel,n,sizeof(hotel[0]),cmp);
        scanf("%d",&t);
        while(t--)
        {
            scanf("%d",&ind);
            solve(ind);
        }
    }
    return 0;
}