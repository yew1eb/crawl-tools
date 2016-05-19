#include"stdio.h"
#include"string.h"
#include"stdlib.h"

int tot[3];
int x[511];
int y[511];
int z[511];
int d[251111],k;

int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int main()
{
    int Case=1,n;
    int i,l;
    int aim,temp,flag;
    int low,up,mid;

    while(scanf("%d%d%d",&tot[0],&tot[1],&tot[2])!=-1)
    {
        qsort(tot,3,sizeof(tot[0]),cmp);
        for(i=0;i<tot[0];i++)    scanf("%d",&x[i]);
        for(i=0;i<tot[1];i++)    scanf("%d",&y[i]);
        for(i=0;i<tot[2];i++)    scanf("%d",&z[i]);
        qsort(x,tot[0],sizeof(x[0]),cmp);

        k=0;
        for(i=0;i<tot[1];i++)
        for(l=0;l<tot[2];l++)
            d[k++]=y[i]+z[l];
        qsort(d,k,sizeof(d[0]),cmp);

        scanf("%d",&n);
        printf("Case %d:\n",Case++);
        while(n--)
        {
            scanf("%d",&aim);
            flag=0;
            for(i=0;i<tot[0];i++)
            {
                temp=aim-x[i];

                low=0;up=k-1;mid=(low+up)>>1;
                while(up-low>1)
                {
                    if(d[mid]>temp)        up=mid;
                    else if(d[mid]<temp)low=mid;
                    else                {flag=1;break;}
                    mid=(low+up)>>1;
                }
                if(d[low]==temp || d[up]==temp)    flag=1;

                if(flag)    break;
            }
            if(flag)    printf("YES\n");
            else        printf("NO\n");
        }
    }
    return 0;
}