#include<iostream>
using namespace std;
int main()
{
    int n ;double i;int flag=1;
    while(cin>>n)
    {double sum=0;
        for(i=1;i<=n;i++)
            sum+=1/i;
        sum/=2;
        if(flag)
        {
            cout<<"# Cards  Overhang"<<endl;
            flag=0;
        }
        printf("%5d     %.3lf\n",n,sum);
    }
    return 0;
}