#include "stdio.h"
#include "stdlib.h"
#include "math.h"

typedef struct point{
    double start,end;
}points;

points p[120];
int s_x,s_y;

double get_x(int x,int y)
{
    if(x==s_x)
        return (double)x;
    else
        return (double)(y*s_x-s_y*x)/(double)(y-s_y);
}

int cmp(const void *p1,const void *p2)
{
 return ((*(points *)p1).end)>((*(points *)p2).end)?1:-1;
}

int main()
{
    int T;
    int n;
    int count,k,i,j;
    int x_s,x_e,y_s,y_e;
    double x1,x2,last;
    scanf("%d",&T);

    while(T--)
    {
        scanf("%d",&n);
        scanf("%d%d",&s_x,&s_y);
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d%d",&x_s,&y_s,&x_e,&y_e);
            x1=get_x(x_s,y_s);
            x2=get_x(x_e,y_e);
            if(x1<x2)
            {
                p[i].start=x1;
                p[i].end=x2;
            }
            else
            {
                p[i].start=x2;
                p[i].end=x1;
            }
        }
        qsort(p,n,sizeof(points),cmp);
        /*for(i=0;i<n;i++)
        {
            for(j=0;j<n-i-1;j++)
            {
                if(p[j].end>p[j+1].end)
                {
                    temp=p[j].end;
                    p[j].end=p[j+1].end;
                    p[j+1].end=temp;
                    temp=p[j].start;
                    p[j].start=p[j+1].start;
                    p[j+1].start=temp;
                }
            }
        }*/

        k=0;
        count=0;
        for(i=0;i<n&&k<n;i++)
        {
            last=p[k].end;
            for(j=k+1;j<n;j++)
            {
                if(p[j].start<last)
                {
                    last=p[j].end;
                    k=j;
                }
            }
                k++;
                count++;
        }

        printf("%d\n",count+1);
    }

    return 0;
}