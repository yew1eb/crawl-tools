#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,n,m,a[100000];
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(a,0,sizeof(a));
        i=10,j=1;
        while(j<m)
        {
            if(!i)break;
            while(i<n)i*=10,j++;
            a[j]=i/n;
            i%=n;
            //printf("i==%d\nj==%d",i,j);
        }
        printf("%d\n",a[m]);
    }
    return 0;
}
