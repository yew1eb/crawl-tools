#include <cstdlib>
#include <iostream>

using namespace std;

long long dp[1010];

int main(int argc, char *argv[])
{
    dp[0]=1;
    dp[1]=1;
    dp[2]=5;
    //dp[3]=11;
    for(int i=3;i<=1000;i++)
     {
         dp[i]=dp[i-1]+4*dp[i-2];
         for(int j=3;j<=i;j++)
          if(j&1) dp[i]+=2*dp[i-j];
          else dp[i]+=3*dp[i-j];
     }
    int n,cas=1,ca;
    cin>>ca;
    while(ca--) 
    {
       cin>>n;     
       cout<<cas++<<" "<<dp[n]<<endl;              
    }
   //system("PAUSE");
    return EXIT_SUCCESS;
}