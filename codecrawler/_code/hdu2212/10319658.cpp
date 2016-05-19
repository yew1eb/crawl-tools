#include <iostream>
using namespace std;
int f(int a);
int main()
{
    for(int i=1;i<=50000;i++)
    {
        int sum=0,j,k;
        k=i;
        while(k!=0)
        {
            j=k%10;
            sum=sum+f(j);
            k=k/10;
        }
        if(sum==i)
            cout<<i<<endl;
    }
    return 0;
}
int f(int a)
{
    int g=1;
    for(int j=1;j<=a;j++)
        g=g*j;
    return g;
}