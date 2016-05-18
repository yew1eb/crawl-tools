#include<stdio.h>
/*
读题不慎，WA了一次
*/
int main()
{
    char name[101][100];
    int t,n,i,k=0;
    int a[101],b[101],bb[111];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        k=0;
        for(i=0;i<n;++i)
        {
            scanf("%s%d%d",name[i],&a[i],&b[i]);
            if(b[i]<200)
                continue;
            bb[i]=b[i]/200;
            if(bb[i]>5)
                bb[i]=5;
            if(a[k]*bb[i]>a[i]*bb[k]||(a[k]*bb[i]==a[i]*bb[k]&&b[i]>b[k]))
                k=i;
        }
        printf("%s\n",name[k]);
    }
    return 0;

}