#include<iostream>
#include<map>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
const int mm=1000000007;
long long a[1010],b[1010][1024],c[1010][1024];
int n;
void in()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
}
void work()
{
    memset(b,0,sizeof(b));
    for(int i=1;i<n;i++)
    {
        int j=i-1;
        b[i][a[j]]=1;
        for(int k=0;k<1024;k++)
        {
            b[i][k]+=b[j][k];
            b[i][k^a[j]]+=b[j][k];
            b[i][k]%=mm;
            b[i][k^a[j]]%=mm;
        }
    }
    memset(c,0,sizeof(c));
    reverse(a,a+n);
    for(int i=1;i<n;i++)
    {
        int j=i-1;
        c[i][a[j]]=1;
        for(int k=0;k<1024;k++)
        {
            c[i][k]+=c[j][k];
            c[i][k&a[j]]+=c[j][k];
            c[i][k]%=mm;
            c[i][k&a[j]]%=mm;
        }
    }
    long long ans=0;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<1024;j++)
        {
            ans=(ans+(b[i][j]-b[i-1][j]+mm)%mm*c[n-i][j])%mm;
        }
    }
    cout<<ans<<endl;
}
int main()
{
    int exp;
    cin>>exp;
    while(exp--)
    {
        in();
        work();
    }
}
