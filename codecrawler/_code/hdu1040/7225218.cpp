#include<stdio.h>
#define MAXN 1003

int f[MAXN];
int m;

void input()
{
     int i;
     scanf("%d",&m);
     for(i=1;i<=m;i++)
        scanf("%d",&f[i]);
     int temp, k, j;
     for(i=1;i<m;i++)
     {
        k =i;
        for(j=i+1;j<=m;j++)
           if(f[j]<f[k]) k =j;
        if(k!=i){ temp = f[i]; f[i] =f[k]; f[k] =temp;}
     }
}

void output()
{
     int i;
     for(i=1;i<m;i++)
       printf("%d ",f[i]);
     printf("%d\n",f[m]);
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
       input();
       output();       
    }
    return 0;
} 
