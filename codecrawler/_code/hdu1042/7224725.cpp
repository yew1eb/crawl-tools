#include <stdio.h>
#include<string.h>
#define MAXN 50000

int a[MAXN];
int t;
void sub(int x)
{
     int i;
     int c;
     c = 0;
     for(i=1;i<=t;i++)
     {
        a[i]=a[i]*x+c;
        c=a[i]/10;
        a[i]=a[i]%10;
     }
     while(c>0){t++;a[t]=c%10;c/=10;}
}

void print()
{
     int i;
     for(i= t;i>=1;i--)
       printf("%d",a[i]);
     printf("\n");

}

int main()
{
    int n;
    int i;
    //freopen("out.txt","w",stdout);
    while(scanf("%d",&n)!=EOF)
    {
        memset(a,0,sizeof(a));
        t =1;
        a[1]=1;
        for(i=1;i<=n;i++)
          sub(i);
        print();
    }
    return 0;
}
