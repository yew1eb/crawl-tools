#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int x,h;
}node;
node kk[110000];
int cmp(const void*a,const void*b)
{
    return (*(node*)a).x-(*(node*)b).x;
}
int main()
{
    int n,i;
    int A,T;
    while(scanf("%d",&n),n)
    {
        for(i=0;i<n;i++)
            scanf("%d%d",&kk[i].x,&kk[i].h);
        scanf("%d%*c%d",&A,&T);
        qsort(kk,n,sizeof(node),cmp);
        double max=0;
        double temp;
        int ans=0;
        for(i=0;i<n;i++)
        {
            temp=kk[i].x+kk[i].h*T*1.0/A;
            if(max<temp){max=temp;ans++;}
        }
        printf("%d\n",ans);
    }
    return 0;
}