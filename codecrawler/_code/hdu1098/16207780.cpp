#include<iostream>
using namespace std;
int main()
{
    int k,i;
    while(scanf("%d",&k)!=EOF)
    {
        for(i=1;i<=10000;i++)
        {
            if((18+k*i)%65==0){printf("%d\n",i);break;}
        }
        if(i>10000)printf("no\n");
    }
    return 0;
}