#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    int sum;
    int i;
    int num[1100];
    while(cin>>n)
    {
        memset(num,0,sizeof(num));
        if(n==0)
        break;
        
        for(i=1;i<=n;i++)
        cin>>num[i];
        
        sort(num+1,num+n+1);
        /*for(i=1;i<=n;i++)
        cout<<num[i]<<" ";
        cout<<endl;*/
        
        sum=0;
        for(i=2;i<=n-1;i++)
        sum=sum+num[i];
        //cout<<sum<<endl;
        cout<<sum/(n-2)<<endl;
    }
    return 0;
}