#include <iostream>
#include <stdio.h>
using namespace std;
int f[5843],n;
int i,j,k,l;

int min(int a,int b,int c,int d)
{
    int min=a;
    if(b<min) min=b;
    if(c<min) min=c;
    if(d<min) min=d;

    if(a==min) i++;
    if(b==min) j++;
    if(c==min) k++;
    if(d==min) l++;

    return min;
}

int main()
{
    i=j=k=l=1;
    f[1]=1;
    for(int t=2;t<=5842;t++)
    {
        f[t]=min(2*f[i],3*f[j],5*f[k],7*f[l]);
    }
    while(scanf("%d",&n)&&n!=0)
    {
        if(n%10==1&&n%100!=11)
            printf("The %dst humble number is %d.\n",n,f[n]);
        else if(n%10==2&&n%100!=12)
            printf("The %dnd humble number is %d.\n",n,f[n]);
        else if(n%10==3&&n%100!=13)
            printf("The %drd humble number is %d.\n",n,f[n]);
        else
            printf("The %dth humble number is %d.\n",n,f[n]);
    }

    return 1;
}

