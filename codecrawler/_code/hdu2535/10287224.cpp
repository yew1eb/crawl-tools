#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
int cmp(const void *_a,const void *_b)
{
    int *a=(int*)_a;
    int *b=(int*)_b;
    return *a-*b;
}
int main()
{
    int n;
    int num[MAX];
    while(scanf("%d",&n)>0&&n)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&num[i]);
        }
        qsort(num,n,sizeof(int),cmp);
        int len=(n/2)+1;
        int sum=0;
        for(int i=0;i<len;i++)
        {
            sum+=((num[i]/2)+1);
        }
        printf("%d\n",sum);
    }
}