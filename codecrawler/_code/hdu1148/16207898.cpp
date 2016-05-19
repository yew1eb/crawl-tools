#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
using namespace std;
int n=0,k=0,cases=0;;//n people (begin with 1)  k  games
typedef struct pe
{
    int w;
    int l;
    pe()
    {
        w=0;
        l=0;
    }
}pe,* pelink;
pe peos[100+5];//begin with 1
int duel(char c1,char c2)
{
    int val=c1-c2;
    switch((int)fabs(val))
    {
        case 0:
            return(0);
        case 3:
            return(val);
        default:
            return(-val);
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF&&n>0)
    {
        cases++;
        memset(peos,0,sizeof(peos));
        scanf("%d",&k);
        for(int i=1;i<=k;i++)
        {
            char cs1[10],cs2[10];
            int num1,num2;
            scanf("%d%s%d%s",&num1,cs1,&num2,cs2);
            int flag=duel(cs1[0],cs2[0]);
            if(flag>0)
            {
                peos[num1].w++;
                peos[num2].l++;
            }
            else if(flag<0)
            {
                peos[num1].l++;
                peos[num2].w++;
            }
        }
        if(cases>1)//PE: the empty line is between cases
            printf("\n");
        for(int i=1;i<=n;i++)
        {
            if(peos[i].w+peos[i].l==0)
            {
                printf("-\n");
            }
            else
            {
                printf("%.3lf\n",(double)peos[i].w/(peos[i].w+peos[i].l));
            }
        }
    }
    return(0);
}
