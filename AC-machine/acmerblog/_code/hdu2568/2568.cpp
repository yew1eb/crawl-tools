#include <iostream>
long degui(long m);
using namespace std;

int main()
{
    int n,i;
    long sum,a;
    cin>>n;
    for(i=1;i<n+1;i++)
    {
        cin>>a;
        sum=degui(a);
        cout<<sum<<endl;

    }


    return 0;
}

long degui(long m)  //简单的递归
{
    if(m==1 || m==2)
    {
        return 1;
    }
    else
    {
        if(m%2==0)
        {
            return degui(m/2);
        }
        else
        {
            return (degui(m/2)+1);
        }
    }
}