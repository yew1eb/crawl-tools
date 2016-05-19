#include<stdio.h>
int a[2000];
int b[2000];
int main()
{
    int i,j,n,m,k,flag1,flag2,x1,x2,v1,v2,count;
    while(scanf("%d %d %d",&n,&m,&k),n!=0&&m!=0)
    {
        x1=n,x2=m;flag1=0,flag2=0;
        count=k;v1=0,v2=0;
        while(count--)
        {
           a[v1++]=x1%10;
           b[v2++]=x2%10;
           x1/=10,x2/=10;
        }
        for(i=v1-1;i>=0;i--)
        {
           flag1=flag1*10+a[i];
           flag2=flag2*10+b[i];
        }
        if(flag1!=flag2)
        printf("%d\n",n+m);
        else
        printf("-1\n");
    }
    return 0;
}