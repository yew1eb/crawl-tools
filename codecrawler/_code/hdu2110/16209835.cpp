#include <iostream>
#include <cstring>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
int N,n[100],v[100],i,j,k,last,last2,sum;
int a[5000],b[5000];
int main()
{
    while ((cin>>N)&&N!=0)
    {
        sum=0;
        for (i=0;i<N;i++)
        {
            cin>>v[i]>>n[i];
            sum+=(v[i]*n[i]);
        }
        if (sum%3!=0)
        {
            cout<<"sorry"<<endl;
            continue;
        }
        sum/=3;
        a[0]=1;
        last=0;
        for (i=0;i<N;i++)
        {
            last2=min(last+n[i]*v[i],sum);
            memset(b,0,sizeof(int)*(last2+1));
            for (j=0;j<=n[i]&&j*v[i]<=last2;j++)
                for (k=0;k<=last&&k+j*v[i]<=last2;k++)
                {
                    b[k+j*v[i]]+=a[k];
                    b[k+j*v[i]]%=10000;
                }
            memcpy(a,b,sizeof(int)*(last2+1));
            last=last2;
        }
        if (a[sum]>0)
            cout<<a[sum]<<endl;
        else
            cout<<"sorry"<<endl;
    }
    return 0;
}