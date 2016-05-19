#include<iostream>
#include<algorithm>
const int MAX=100;
int s[MAX];
int t[MAX];
using namespace std;
int main()
{
    int n,i,j,sum1,sum2;
    while(cin>>n,n>0)
    {
        sum1=0;
        sum2=0;
        for(i=0;i<n;i++)
        {
            cin>>s[i];
        }
        for(i=0;i<n;i++)
        {
            cin>>t[i];
        }
        sort(s,s+n);
        sort(t,t+n);
        for(i=0;i<n;i++)
        {
            if(s[i]>t[i])
            sum1+=2;
            else if(s[i]==t[i])
            sum1+=1,sum2+=1;
            else
            sum2+=2;
        }
        cout<<sum1<<" vs "<<sum2<<endl;
    }
    return 0;
}