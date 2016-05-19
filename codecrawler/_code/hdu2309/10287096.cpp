#include<iostream>
const int MAX=101;
const int Max=999999;
int s[MAX];
using namespace std;
int main()
{
    int n,m,i,j,minn,maxn,sum;
    while(cin>>n,n)
    {
        minn=Max;
        maxn=-1;
        sum=0;
        for(i=0;i<n;i++)
        {
         cin>>s[i];
         if(s[i]<minn)
         minn=s[i];
         if(s[i]>maxn)
         maxn=s[i];
         sum+=s[i];
        }
        sum-=(minn+maxn);
        cout<<sum/(n-2)<<endl;
    }
    return 0;
}