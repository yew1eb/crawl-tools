#include<iostream>
using namespace std;
int main()
{
    int n,k;
    while(cin>>n>>k&&n&&k)
    {
        int x=n,re=0;
        while(x>=k)
        {
            n+=x/k;//å ä¸éçé± 
            x=x%k+x/k;
        }
        cout<<n<<endl;
    }
    return 0;
} 