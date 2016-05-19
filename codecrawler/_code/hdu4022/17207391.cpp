#include"stdio.h"
#include"string.h"
#include"stdlib.h"
struct A
{
    int x,y,index;
}x[100011],y[100011];
int hash[100011];
int cmp_x(const void *a,const void *b)
{
    struct A *c,*d;
    c=(struct A *)a;
    d=(struct A *)b;
    return c->x-d->x;
}
int cmp_y(const void *a,const void *b)
{
    struct A *c,*d;
    c=(struct A *)a;
    d=(struct A *)b;
    return c->y-d->y;
}
int main()
{
    int n,m;
    int i,l;
    int low,mid,up;
    int a,b,c,d;
    int ans;
    while(scanf("%d%d",&n,&m),n||m)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            x[i].x=a;
            y[i].y=b;
            x[i].index=y[i].index=i;
        }
        qsort(x,n,sizeof(x[0]),cmp_x);
        qsort(y,n,sizeof(y[0]),cmp_y);

        memset(hash,0,sizeof(hash));
        for(i=0;i<m;i++)
        {
            ans=0;
            scanf("%d%d",&c,&d);
            low=0;up=n-1;mid=(low+up)>>1;
            if(c==0)
            {
                while(low<=up)
                {
                    if(x[mid].x<d)    low=mid+1;
                    else            up=mid-1;
                    mid=(low+up)>>1;
                }
                for(l=low;l<n;l++)
                {
                    if(x[l].x!=d)    break;
                    if(hash[x[l].index])    continue;
                    hash[x[l].index]=1;
                    ans++;
                }
            }
            else
            {
                while(low<=up)
                {
                    if(y[mid].y<d)    low=mid+1;
                    else            up=mid-1;
                    mid=(low+up)>>1;
                }
                for(l=low;l<n;l++)
                {
                    if(y[l].y!=d)    break;
                    if(hash[y[l].index])    continue;
                    hash[y[l].index]=1;
                    ans++;
                }
            }
            printf("%d\n",ans);
        }

        printf("\n");
    }
    return 0;
}