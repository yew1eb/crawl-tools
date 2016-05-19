#include <stdio.h>
#include <stdlib.h>
#define tt int
#define bt __int64
typedef struct {
    int x;
    int y;
}ppp;

ppp pp[10005];
inline bt max(bt a,bt b) 
{
    return a>b?a:b;
}

inline tt min(tt a,tt b)
{
    return a<b?a:b;
}

tt cmp(const void *p,const void *q)
{
    ppp *p1,*p2;
    p1=(ppp *)p;
    p2=(ppp *)q;
    return p1->x - p2->x;
}

int main()
{
    int n,i,j,k,t;
    bt m;
    bt tm;
    int lf,rf;
    int pos,pos2;
     bt sum;
     bt temp;
     bt temp2;
    while(scanf("%d%I64d",&n,&m)!=EOF)
    {
        sum=0;
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&pp[i].x,&pp[i].y);
        }
        qsort(pp,n,sizeof(pp[0]),cmp);
        for(i=0;i<n;i++)
        {    
            temp=pp[i].y;
            tm=m;
            lf=i-1;
            rf=i+1;
            while((lf!=-1 || rf!=n) && tm!=0)
            {
                if(lf==-1) 
                {
                    pos=rf;
                    if(tm>((bt)(pp[pos].x-pp[i].x))*pp[pos].y)
                    {
                        temp+=pp[pos].y;
                        tm-=((bt)(pp[pos].x-pp[i].x))*pp[pos].y;
                    }
                    else
                    {
                        temp+=tm/(pp[pos].x-pp[i].x);
                        break;
                    }
                    rf++;
                }
                else if(rf==n)
                {
                    pos=lf;
                    if(tm>((bt)(pp[i].x-pp[pos].x))*pp[pos].y)
                    {
                        temp+=pp[pos].y;
                        tm-=((bt)(pp[i].x-pp[pos].x))*pp[pos].y;
                    }
                    else
                    {
                        temp+=tm/(pp[i].x-pp[pos].x);
                        break;
                    }
                    lf--;
                }
                else 
                {
                    if(pp[rf].x-pp[i].x > pp[i].x - pp[lf].x)
                    {
                        pos=lf;
                        if(tm>((bt)(pp[i].x-pp[pos].x))*pp[pos].y)
                        {
                            temp+=pp[pos].y;
                            tm-=((bt)(pp[i].x-pp[pos].x))*pp[pos].y;
                        }
                        else
                        {
                            temp+=tm/(pp[i].x-pp[pos].x);
                            break;
                        }
                        lf--;
                    }
                    else 
                    {
                        pos=rf;
                        if(tm>((bt)(pp[pos].x-pp[i].x))*pp[pos].y)
                        {
                            temp+=pp[pos].y;
                            tm-=((bt)(pp[pos].x-pp[i].x))*pp[pos].y;
                        }
                        else
                        {
                            temp+=tm/(pp[pos].x-pp[i].x);
                            break;
                        }
                        rf++;
                    }
                }
            }
            sum=sum>temp?sum:temp;
        }
        printf("%d\n",sum);
    }
    return 0;
}