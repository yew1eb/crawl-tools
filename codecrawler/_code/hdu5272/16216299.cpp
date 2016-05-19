#include <iostream>

using namespace std;
int main()
{
    int t;
    long long m;
    cin>>t;
    while(t--)
    {
        cin>>m;
        int sum=0;
        while(m)
        {
            if(m&1==1)
            {
                sum++;
                while(m)
                {
                    if(m&1==1)
                        m/=2;
                    else
                        break;
                }
            }
            m/=2;
        }
        cout<<sum<<endl;
    }
    return 0;
}
