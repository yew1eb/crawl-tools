#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==1)
        printf("0\n");
        else
        {
            int temp=1;
            int u;
            while(m--)
            {
                temp*=10;
                u=temp/n;
                temp%=n;
            }
            printf("%d\n",u);
        }
    }
}