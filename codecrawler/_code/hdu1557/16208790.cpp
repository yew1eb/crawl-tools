#include"stdio.h"
#include"string.h"
int main()
{
    int T;
    int n;
    int num[22];
    int limit;
    int a,b,aim;
    int c1[100001],c2[100001];
    int ans[22];
    int z,i,j,k;
    int d;


    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        limit=0;
        for(i=1;i<=n;i++)    {scanf("%d",&num[i]);limit+=num[i];}
        aim=limit/2;
        aim++;




        if(n==1)    {printf("1\n");continue;}


        for(z=1;z<=n;z++)
        {
            for(j=0;j<=limit;j++)    c1[j]=c2[j]=0;
            c1[0]=1;
            if(z==1)    {c1[num[2]]=1;d=2;}
            else        {c1[num[1]]=1;d=1;}


            for(i=1;i<=n;i++)
            {
                if(i==d)    continue;
                if(i==z)    continue;
                for(j=0;j<=limit;j++)
                {
                    if(c1[j]==0)    continue;
                    for(k=0;k<2;k++)c2[k*num[i]+j]+=c1[j];
                }
                for(j=0;j<=limit;j++)
                {
                    c1[j]=c2[j];
                    c2[j]=0;
                }
            }


            a=aim-num[z];
            if(a<0)    a=0;
            b=aim-1;
            ans[z]=0;
            for(j=a;j<=b;j++)    ans[z]+=c1[j];
        }


        for(i=1;i<n;i++)    printf("%d ",ans[i]);
        printf("%d\n",ans[i]);
    }
    return 0;
}