#include"stdio.h"
#include"string.h"
int prime[100],k;
int num[151];
int main()
{
    int T;
    int n;
    int i,l,j;
    int c1[151],c2[151];

    k=0;
    memset(num,-1,sizeof(num));
    num[0]=num[1]=0;
    for(i=2;i<=150;i++)
    {
        if(num[i])
        {
            prime[k++]=i;
            for(j=2*i;j<=150;j+=i)
            {
                num[j]=0;
            }
        }
    }

    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        for(i=0;i<=n;i+=prime[0])    c1[i]=1;
        for(i=1;i<k;i++)
        {
            if(prime[i]>n)    break;
            for(l=0;l<=n;l++)
            {
                if(c1[l]==0)    continue;
                for(j=0;j+l<=n;j+=prime[i])    c2[l+j]+=c1[l];
            }
            for(l=0;l<=n;l++)
            {
                c1[l]=c2[l];
                c2[l]=0;
            }
        }
        printf("%d\n",c1[n]);
    }
    return 0;
}