#include<stdio.h>
int a[40000];
void get()
{
    int i,cnt=0;
    a[0]=a[1]=0;
    for(i=2;i<=20000;i++)
    {
        ++cnt;
          a[i]=a[i-1]+cnt;
    }
}
int main()
{
    int n;
    get();
    while(scanf("%d",&n)!=EOF)
    {
        if(n%2==0)
        {
            printf("%d\n",2*a[n/2]);
        }
        else printf("%d\n",a[n/2]+a[n/2+1]);
    }
    return 0;
}