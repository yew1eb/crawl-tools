#include"stdio.h"
#include"math.h"
struct A
{
    double ans;
    int flag;
    int pre;
    int step;
}E[102];
double map[102][102];
struct B
{
    int x;
    int y;
}cor[102];
int main()
{
    int n;
    double d;
    double temp;
    double min;
    int k,i,l;
    int flag;
    cor[0].x=0;
    cor[0].y=0;
    while(scanf("%d",&n)!=-1)
    {
        scanf("%lf",&d);


        if(n==0)
        {
            if(d>=42.5)    printf("42.50 1\n");
            else        printf("can't be saved\n");
            continue;
        }


        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&cor[i].x,&cor[i].y);
            for(l=1;l<i;l++)
            {
                temp=sqrt(pow(cor[i].x-cor[l].x,2)+pow(cor[i].y-cor[l].y,2));
                if(temp>d)    map[i][l]=map[l][i]=-1;
                else        map[i][l]=map[l][i]=temp;
            }
            map[i][i]=0;
        }
        map[0][0]=0;


        if(d>=42.5)    {printf("42.50 1\n");continue;}


        for(l=1;l<=n;l++)
        {
            temp=sqrt(pow(cor[0].x-cor[l].x,2)+pow(cor[0].y-cor[l].y,2))-7.5;
            if(temp>d)    map[0][l]=map[l][0]=-1;
            else        map[0][l]=map[l][0]=temp;
        }


        for(i=0;i<=n+1;i++)
        {
            E[i].ans=111111;
            E[i].flag=1;
            E[i].pre=i;
            E[i].step=111111;
        }
        E[0].ans=0;
        E[0].step=0;


        k=0;
        while(k!=-1)
        {
            if(E[k].ans==111111)    break;
            flag=0;
            min=111111;
            if(cor[k].x+d>=50)    {flag=1;min=min>50-cor[k].x?50-cor[k].x:min;}
            if(cor[k].x-d<=-50)    {flag=2;min=min>cor[k].x+50?cor[k].x+50:min;}
            if(cor[k].y+d>=50)    {flag=3;min=min>50-cor[k].y?50-cor[k].y:min;}
            if(cor[k].y-d<=-50)    {flag=4;min=min>cor[k].y+50?cor[k].y+50:min;}
            if(flag)
            {
                if(E[k].ans+min<E[n+1].ans)    {E[n+1].ans=E[k].ans+min;E[n+1].step=E[k].step+1;}
                else if(E[k].ans+min==E[n+1].ans&&E[k].step+1<E[n+1].step)    E[n+1].step=E[k].step+1;
            }
            if(E[k].ans>=E[n+1].ans)    break;


            E[k].flag=0;
            for(i=1;i<=n;i++)
            {
                if(i==k)            continue;
                if(map[i][k]==-1)    continue;
                temp=E[k].ans+map[i][k];
                if(E[i].ans>temp)
                {
                    E[i].ans=temp;
                    E[i].pre=k;
                    E[i].step=E[k].step+1;
                }
                else if(E[i].ans==temp&&E[k].step+1<E[i].step)
                {
                    E[i].step=E[k].step+1;
                    E[i].pre=k;
                }
            }


            k=-1;
            for(i=1;i<=n;i++)    if(E[i].flag)    {k=i;break;}
            for(i++;i<=n;i++)
            {
                if(E[i].flag)
                {
                    if(E[i].ans<E[k].ans)                            k=i;
                    else if(E[i].ans==E[k].ans&&E[i].step<E[k].step)k=i;
                }
            }
        }


        if(E[n+1].ans==111111)    printf("can't be saved\n");
        else                    printf("%0.2lf %d\n",E[n+1].ans,E[n+1].step);
    }
    return 0;
}