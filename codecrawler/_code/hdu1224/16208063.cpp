#include"stdio.h"
#include"string.h"
struct A
{
    int ans;
    int flag;
    int pre;
}E[102];
int main()
{
    int T,Case;
    int n,m;
    int k,i;
    int map[102][102];
    int point[102];
    int a,b;
    int temp;
    int temp1,temp2;
    int max;
    int ans[10011];
    scanf("%d",&T);
    for(Case=1;Case<=T;Case++)
    {
        scanf("%d",&n);
        temp=n+1;
        max=0;
        for(i=1;i<=n;i++)    {scanf("%d",&point[i]);max=max>point[i]?max:point[i];}
        point[n+1]=max+1;


        memset(map,0,sizeof(map));
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d%d",&a,&b);
            temp1=a>b?b:a;
            temp2=a>b?a:b;
            map[temp1][temp2]=point[temp2];
        }


        for(i=1;i<=temp;i++)
        {
            E[i].ans=0;
            E[i].flag=1;
            E[i].pre=i;
        }


        k=1;
        while(k)
        {
            E[k].flag=0;
            for(i=k+1;i<=temp;i++)
            {
                if(map[k][i]==0)    continue;
                if(E[k].ans+map[k][i]>E[i].ans)
                {
                    E[i].ans=E[k].ans+map[k][i];
                    E[i].pre=k;
                }
            }


            k=0;
            for(i=1;i<=n;i++)    if(E[i].flag&&E[i].ans)    {k=i;break;}
        }


        printf("CASE %d#\n",Case);
        printf("points : %d\n",E[n+1].ans-max-1);
        printf("circuit : ");


        k=E[n+1].pre;
        i=0;
        ans[i]=k;
        while(k!=1)
        {
            k=E[k].pre;
            ans[++i]=k;
        }
        for(;i>=0;i--)    printf("%d->",ans[i]);
        printf("1\n");


        if(Case<T)    printf("\n");
    }
    return 0;
}