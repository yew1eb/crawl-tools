

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

const int N = 10010;
int main()
{
    long arr1[2*N],arr2[N];
    int n,m;
    while(cin>>n>>m)
    {
        int k,j,i;
        for(i=0; i<n; i++)
            cin>>arr1[i];
        for(i=0; i<m; i++)
            cin>>arr2[i];
        for(i=0,k=n; i<m; i++)
        {
            bool flag = true;
            for(j=0; j<k; j++)
                if(arr1[j]==arr2[i])
                    flag = false;
            if(flag) arr1[k++] = arr2[i]; 
        }
        sort(arr1,arr1+k);
        for(i=0; i<k; i++)
        {
            cout<<arr1[i];
            if(i!=k-1) 
                cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}