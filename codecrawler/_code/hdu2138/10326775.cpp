#include<stdio.h>
#include<math.h>
int main()
{
    int i,j,k,n,m,p;
    while(scanf("%d",&n)!=EOF)
    {
        p=0;
        while(n--)
        {
            scanf("%d",&m);
            k=sqrt(m);
            j=1;
            for(i=2;i<=k;i++)
                if(m%i==0) j=0;
            if(j) p++;
        }
        printf("%d\n",p);
    }
    return 0;
}