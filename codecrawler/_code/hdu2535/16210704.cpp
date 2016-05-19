#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int num[200];
    int i;
    int n;
    int sum;
    while(cin>>n,n!=0)
    {
        sum=0;
        for(i=0;i<n;i++)
        cin>>num[i];
        
        sort(num,num+n);
        /*for(i=0;i<n;i++)
        cout<<num[i];
        cout<<endl;*/
        
        for(i=0;i<=n/2;i++)//è§å¯ä¸ä¸å°±ç¥éäº
        {
            sum=sum+num[i]/2+1;
            
        }
        cout<<sum<<endl;
    }
    return 0;
}