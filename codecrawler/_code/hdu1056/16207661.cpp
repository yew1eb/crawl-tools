#include<iostream>
using namespace std;
double f[10000];
int main()
{
    double n;
    int i;
    for(i=2;i<=10000;i++)
    {
        double temp=1.0/i;
        f[i-1]=f[i-2]+temp;
    }

    while(cin>>n&&n)
    {
        for(i=1;i<=10000;i++)
            if(f[i]>=n)
                break;
         printf("%d card(s)\n",i);
        
    }

    return 0;

}
