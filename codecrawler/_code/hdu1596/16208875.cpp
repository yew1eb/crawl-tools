#include"stdio.h"
struct A
{
    double ans;
    int pre;
    int flag;
}E[1001];
double map[1001][1001];
int main()
{
    int n;
    int s,e,q;
    int i,l;
    int k;
    while(scanf("%d",&n)!=-1)
    {
        for(i=1;i<=n;i++)
        for(l=1;l<=n;l++)
            scanf("%lf",&map[i][l]);
        
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d%d",&s,&e);


            for(i=1;i<=n;i++)
            {
                E[i].ans=0;
                E[i].flag=1;
                E[i].pre=i;
            }


            k=s;
            E[k].ans=1;
            while(k)
            {
                E[k].flag=0;
                if(E[k].ans<=E[e].ans)    break;


                for(i=1;i<=n;i++)
                {
                    if(map[k][i]==0)    continue;
                    if(E[i].ans<E[k].ans*map[k][i])
                    {
                        E[i].ans=E[k].ans*map[k][i];
                        E[i].pre=k;
                    }
                }


                k=0;
                for(i=1;i<=n;i++)    if(E[i].flag)    {k=i;break;}
                for(i++;i<=n;i++)    if(E[i].flag&&E[i].ans>E[k].ans)    k=i;
            }


            if(E[e].ans==0)    printf("What a pity!\n");
            else            printf("%0.3lf\n",E[e].ans);
        }
    }
    return 0;
}