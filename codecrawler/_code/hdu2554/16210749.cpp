#include<iostream>
using namespace std;

int main()
{
    int n;

    while(scanf("%d",&n) && n)
    {
        if(n%4==0 || (3*n-1)%4==0)
            puts("Y");        //printf("Y\n"); 
        else
            printf("N\n");   //puts("N");
    }

    return 0;
}
