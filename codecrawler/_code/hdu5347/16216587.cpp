#include <stdio.h>
#include <string.h>
int a[200];

int main()
{
    memset(a,0,sizeof(a));
    a[1]=1100,a[2]=1101;
    for(int i=3;i<=10;i++)
        a[i]=i*100;
    for(int k=11;k<=18;k++)
        a[k]=k;
    a[35]=15,a[36]=16;
    a[53]=12,a[54]=13;
    a[83]=10,a[84]=11;
    a[4]=500,a[5]=400,a[7]=800,a[8]=700;
    a[12]=13,a[13]=12,a[15]=16,a[16]=15;
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        if(a[n]>a[m])
            printf("FIRST BIGGER\n");
        else
            printf("SECOND BIGGER\n");
    }
    return 0;
}