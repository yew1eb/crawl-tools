#include<iostream>
#include<vector>
using namespace std;

int n,k;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n>>k;
        if(k%2)
        {
            if(n%2)
            {
                cout<<"1"<<endl;
            }
            else
            {
                cout<<"0"<<endl;
            }
        }
        else
        {
            if(n%(k+1)==k)
            {
                cout<<k<<endl;
            }
            else if((n%(k+1))%2)
            {
                cout<<"1"<<endl;
            }
            else
            {
                cout<<"0"<<endl;
            }
        }
    }
    return 0;
}
