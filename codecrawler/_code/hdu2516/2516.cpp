#include<iostream>
using namespace std;

int num[50];
void init()
{
    int i;
    num[1]=1;num[2]=2;
    for(i=3;i<=45;i++)    num[i]=num[i-1]+num[i-2];
    
}

int main()
{
    init();
    int i,j;
    while(scanf("%d",&i),i)
    {
        for(j=1;j<=45;j++)
            if(i==num[j])
                break;
        if(j!=46)    printf("Second win\n");
        else        printf("First win\n");
    }
    
    return 0;
}