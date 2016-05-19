#include <iostream>

using namespace std;
typedef unsigned long long LL;

const LL MOD = 1000003;
LL arr[1000100];

int main()
{
    LL t,n,i;
    arr[0]=0;arr[1]=2;
    for(i=2;i<=MOD;i++)
        arr[i]=(arr[i-1]*2*i)%MOD;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n>=MOD)
        {
            cout<<"0"<<endl;
            continue;
        }
        cout<<arr[n]<<endl;
    }
    return 0;
}
