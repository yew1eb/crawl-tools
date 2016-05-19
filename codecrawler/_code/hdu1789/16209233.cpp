#include"stdio.h"
#include"string.h"
#include"stdlib.h"
struct A
{
    int dead,score;
}E[1011];
int hash[1011];
int cmp(const void *a,const void *b)
{
    A *c,*d;
    c=(A *)a;
    d=(A *)b;
    if(c->score!=d->score)    return d->score-c->score;
    else                    return c->dead-d->dead;
}
int main()
{
    int T;
    int n;
    int i,l;
    int ans;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        E[0].dead=-1;
        E[0].score=11111111;
        for(i=1;i<=n;i++)    scanf("%d",&E[i].dead);
        for(i=1;i<=n;i++)    scanf("%d",&E[i].score);
        qsort(E,n+1,sizeof(E[0]),cmp);

        ans=0;
        memset(hash,0,sizeof(hash));
        for(i=1;i<=n;i++)
        {
            for(l=E[i].dead;l>0;l--)    if(hash[l]==0)    {hash[l]=1;break;}
            if(l<=0)    ans+=E[i].score;
        }
        printf("%d\n",ans);
    }
    return 0;
}