#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 102

int cmp(const void *x,const void *y)
{
    return *(int *)x-*(int *)y;
}

int main()
{
    int test,n,v,w,i,sum,cnt;
    int pi[MAXN];
    scanf("%d",&test);
    while(test--)
    {
        sum=cnt=0;
        memset(pi,0,sizeof(pi));
        scanf("%d %d %d",&n,&v,&w);
        for(i=0;i<n;++i)
            scanf("%d",&pi[i]);
        qsort(pi,n,sizeof(pi[0]),cmp);//æµåº¦ä»å°å°å¤§
        for (i=0;i<n;++i)
        {
            if(1.0*(sum+pi[i])/(cnt+1)<=1.0*w)
            {
                sum+=pi[i];
                cnt++;
            }
            else
                break;
        }
        if(sum==0)
            printf("0 0.00\n");
        else
            printf("%d %.2lf\n",cnt*v,0.01*sum/cnt);
    }
    return 0;
}
