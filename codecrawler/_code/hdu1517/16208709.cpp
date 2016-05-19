#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n>=1 && n<=9) {printf("Stan wins.\n"); continue;}
        bool flag=true;
        int temp=1;
        while(temp<n)
        {
            if(flag)
            {
                temp*=9;
                flag=false;
            }
            else 
            {
                temp*=2;
                flag=true;
            }
        }
        if(flag) printf("Ollie wins.\n");
        else  printf("Stan wins.\n");
    }
    return 0;
}
