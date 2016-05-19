#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
long long int  stop[121212];
long long int  sum[121212];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(sum,0,sizeof(sum));
        sum[0]=0;
        long long int  n,m;
        cin>>n>>m;
        for(int i=1;i<=n-1;i++)
        {
            cin>>stop[i];
            sum[i]=sum[i-1]+stop[i];
        }
        for(int i=1;i<=m;i++)
        {
            long long int begin=(i-1)%n+1;
            long long int  a,b;
            cin>>a>>b;
            long long int output=0;
            if(a>b)//æåµ1
            {
                output+=sum[n-1]-sum[begin-1];
                output+=sum[n-1]-sum[b-1];
                cout<<output<<endl;
            }
            else
            {
                if(begin>a)//æåµ2
                {
                    output+=sum[n-1]-sum[begin-1];
                    output+=sum[n-1];
                    output+=sum[b-1];
                    cout<<output<<endl;
                }
                else//æåµ3
                {
                     output+=sum[b-1]-sum[begin-1];
                     cout<<output<<endl;
                }
            }
        }
    }
}