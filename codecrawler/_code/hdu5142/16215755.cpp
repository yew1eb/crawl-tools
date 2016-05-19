#include<iostream>
using namespace std;
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[100],t=0;
        while(n)
        {
            a[t]=n%2;
            t++;
            n/=2;
        }
        int i,re=0,m=t;
        for(i=0;i<m;i++)
        {
            re+=(a[t-1]<<i);
            t--;
        }
        cout<<re<<endl;
    }
    return 0;
}