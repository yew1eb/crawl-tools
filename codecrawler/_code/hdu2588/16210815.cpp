#include<stdio.h>
#include<math.h>
int Euler(int n)
{
    if(n==1)
        return 1;
    int i=2,m=n,root=(int)sqrt(n);
    while(i<=root)
    {
        if(m%i==0)
        {
            n-=n/i;
            while(m%i==0)
                m/=i;
            root=(int)sqrt(m);
        }
        i++;
    }
    if(m!=1)
    {
        n-=n/m;
    }
    return n;
}
int solve(int n,int m)
{
    int nn = sqrt(n),ans=0;
    for(int i=1;i<=nn;i++)
    {
        if(n%i) continue;
        if(i>=m&&i!=nn)
            ans += Euler(n/i);
        if(n/i>=m)
            ans += Euler(i);
    }
    return ans;
}
int main()
{
    int n,t,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        printf("%d\n",solve(n,m));
    }
    return 0;
}
