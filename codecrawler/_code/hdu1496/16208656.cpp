#include"stdio.h"
#include"string.h"
#include"stdlib.h"
int hash[2000011];
int main()
{
    int i,l;
    int a,b,c,d;
    int ans;
    while(scanf("%d%d%d%d",&a,&b,&c,&d)!=-1)
    {
        if(a*b>0 && b*c>0 && c*d>0)    {printf("0\n");continue;}
        memset(hash,0,sizeof(hash));
        for(i=1;i<=100;i++)
        for(l=1;l<=100;l++)
            hash[a*i*i+b*l*l+1000000]++;
        ans=0;
        for(i=1;i<=100;i++)
        for(l=1;l<=100;l++)
            ans+=hash[-c*i*i-d*l*l+1000000];
        printf("%d\n",16*ans);
    }
    return 0;
}