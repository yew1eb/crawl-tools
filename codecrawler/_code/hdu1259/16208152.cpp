#include<iostream>
using namespace std;
int main()
{
    int a[8],t,n,p,q,k,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=7;i++)
        a[i]=i;
        while(n--)
        {
            cin>>p>>q;
            k=a[p];a[p]=a[q];a[q]=k;
        }
        for(i=1;i<=7;i++)
        if(a[i]==2)
        {
            cout<<i<<endl;
            break;
        }
    }
}
