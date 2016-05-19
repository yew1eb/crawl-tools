#include <iostream>
#include <algorithm>
using namespace std;
int a[9000010]= {0};
int main()
{
    int n,m,b[3001]= {0},k;
    while((cin>>n>>m)>0)
    {
        for(int i=0; i<n; i++)
            cin>>b[i];
        k=0;
        sort(b,b+n);
        for(int i=0; i<n; i++)
            for(int j=0; j<i; j++)
                a[k++]=b[i]+b[j];
        sort(a,a+k);
        for(int i=0; i<m-1; i++)
            cout<<a[k-1-i]<<" ";
        cout<<a[k-m]<<endl;
    }
    return 0;
}