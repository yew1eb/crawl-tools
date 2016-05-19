#include"stdio.h"
#include"string.h"
struct A
{
    char name[33];
}E[33];
int main()
{
    double map[31][31];
    double ans[31][31];
    double t;
    char temp[33];
    int k;
    int k1,k2;
    int i,l;
    int n,m;
    int Case=1;
    while(scanf("%d",&n),n)
    {
        for(i=1;i<=n;i++)    scanf("%s",E[i].name);
        ///map
        scanf("%d",&m);
        for(i=1;i<=n;i++)
        for(l=1;l<=n;l++)
        {
            if(i==l)map[i][l]=1;
            else    map[i][l]=0;
        }
        for(i=1;i<=m;i++)
        {
            scanf("%s",temp);
            for(k1=1;k1<=n;k1++)    if(strcmp(E[k1].name,temp)==0)    break;
            scanf("%lf",&t);
            scanf("%s",temp);
            for(k2=1;k2<=n;k2++)    if(strcmp(E[k2].name,temp)==0)    break;
            map[k1][k2]=t;
        }
        ///ansçåå§å
        for(i=1;i<=n;i++)
        for(l=1;l<=n;l++)
            ans[i][l]=map[i][l];
        ///ä¸»ä½
        for(k=1;k<=n;k++)
        {
            for(i=1;i<=n;i++)
            for(l=1;l<=n;l++)
            {
                if(ans[i][l]<ans[i][k]*ans[k][l])
                    ans[i][l]=ans[i][k]*ans[k][l];
            }
        }

        if(ans[1][1]>1)    printf("Case %d: Yes\n",Case);
        else            printf("Case %d: No\n",Case);

        Case++;
    }
    return 0;
}