#include<stdio.h>
#include<string.h>
const int N=100;
int a[N];
bool p[N];

int main()
{
    memset(p,true,sizeof(p));
    for(int i=0;i<N;i++)
    a[i]=i;
    for(int j=2;j<N;j++)
    {
        if(p[j])
        {
            for(int k=2;j*k<N;k++)
            if(p[j*k])p[j*k]=false;
            else p[j*k]=true;
        }
        for(int i=2;i<N;i++)
        if(p[i])printf("%d ",a[i]);
        else printf("  ");
        printf("\n");
    }
    return 0;
}