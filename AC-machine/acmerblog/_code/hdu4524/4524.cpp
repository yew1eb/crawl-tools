#include<stdio.h>
int main()
{
    int n,i,t,a,b,flag;
    scanf("%d",&t);
    while(t--)
    {
        flag=1;
        scanf("%d",&n);
        scanf("%d",&a);
        for(i=1;i<n;i++)
        {
            scanf("%d",&b);
            if(a>b)flag=0;
            else a=b-a;
        }
        if(flag==0||a!=0)printf("I will never go out T_T\n");
        else if(a==0)printf("yeah~ I escaped ^_^\n");
    }
    return 0;
}
