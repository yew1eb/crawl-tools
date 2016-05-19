#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#define ll long long
using namespace std;
int main()
{
    //freopen("dd.txt","r",stdin);
    ll n,ncase;
    cin>>ncase;
    while(ncase--)
    {
        cin>>n;
        if(n==2)
        cout<<1<<endl;
        else
        {
            if(n%2)
            cout<<(n/2)*(n-n/2)<<endl;
            else
            {
                if((n/2)%2==0)
                cout<<(n/2-1)*(n/2+1)<<endl;
                else
                cout<<(n/2-2)*(n/2+2)<<endl;
            }
        }
    }
    return 0;
}
