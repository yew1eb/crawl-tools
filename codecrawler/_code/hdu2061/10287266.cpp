#include<stdio.h>
int main()
{
    char s[100];
    double cre,si;
    int t,n,i;
    int f;
    double g,p;
    scanf("%d",&t);
    while(t--)
    {
        g=0;p=0;f=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s%lf%lf",s,&cre,&si);
            g=g+cre*si;p=p+cre;
            if(si<60)
            f=1;
        }
        if(f)
        printf("Sorry!\n");
        else
        printf("%.2lf\n",g/p);
        if(t!=0)
        {
            printf("\n");
        }
    }
    return 0;
}