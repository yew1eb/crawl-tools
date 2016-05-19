#include <iostream>
using namespace std;
int main()
{
    int n,a,sum,i;
    while(cin>>n&&n)
    {
        sum=1;
        for(i=0;i<n;i++)
        {
            sum=sum*n%9;
        }
        if(sum==0)
        cout<<"9"<<endl;
        else
        cout<<sum<<endl;
        
    }
    return 0;
}