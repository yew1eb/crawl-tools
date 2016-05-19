#include<iostream>
#include<string.h>
#include<stdio.h>
#include<math.h>
using namespace std;
int a[1111111]={0};
int look(int k,int m)
{
    m++;
    if(k==1)
    return m;
    if(k%2==1)
    return look(3*k+1,m);
    else
    return look(k/2,m);
}
int main()
{
    int i,j,m,n,k,t;
    while(cin>>m>>n)
    {
        t=0;
        if(m>n)
        {
            t=1;
            j=m;
            m=n;
            n=j;
        }
        for(k=0,i=m;i<=n;i++)
        {
            if(a[i]==0)
            {
                a[i]=look(i,0);
            }
            if(a[i]>k)
            k=a[i];
        }
        if(t)
        {
            j=m;
            m=n;
            n=j;
        }
        printf("%d %d %d\n",m,n,k);
    }
}
