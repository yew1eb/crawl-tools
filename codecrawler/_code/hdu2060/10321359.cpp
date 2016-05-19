#include<stdio.h>
int a[6]={7,6,5,4,3,2};
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int s,m,n,i;
        scanf("%d%d%d",&n,&s,&m);
        if(n>6)
        {
            s+=(n-6)+(n-6)*7;
            n=6;
        }
        for(i=0;i<n;i++) s+=a[i];
        if(s>=m) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}