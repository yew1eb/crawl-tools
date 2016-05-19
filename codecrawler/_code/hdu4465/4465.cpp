#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
double f[400008];
double C_m_n(int m,int n)
{

    return f[m]-f[n]-f[m-n];
}
int main()
{
     f[0]=0;
    for(int i=1;i<=400006;i++)
    f[i]+=f[i-1]+log(i*1.0);
   double sum,p;
   int n,test=0;
   while(cin>>n>>p)
   {
       sum=0;
       printf("Case %d: ",++test);
       for(int k=0;k<=n-1;k++)
       {
           sum+=(n-k)*(exp((C_m_n(n+k,k))+(n+1)*log(p)+k*log(1-p))+exp((C_m_n(n+k,k))+(n+1)*log(1-p)+k*log(p)));
       }
       printf("%.6f\n",sum);
   }
}
