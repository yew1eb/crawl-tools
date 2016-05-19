#include"stdio.h"

__int64 f[26],k;

int main()
{
    int T;
    int Case=1;
    int n;
    int i,l;

    f[0]=1;
    f[1]=1;
    for(i=2;i<=24;i++)
    {
        f[i]=f[i-1]+4*f[i-2];
        for(l=i-3;l>=0;l--)
        {
            if((i-l)%2)    f[i]+=2*f[l];
            else        f[i]+=3*f[l];
        }
    }

    scanf("%d",&T);
    for(Case=1;Case<=T;Case++)
    {
        scanf("%d",&n);
        printf("%d %I64d\n",Case,f[n]);
    }
    return 0;
}