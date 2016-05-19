#include<iostream>
using namespace std;
typedef long long inta;

int gcd(int a,int b)
{
  if(b==0)
  return a;
  else return gcd(b,a%b);

}
int main()
{
   int k,a;
   while(cin>>k>>a)
   {
      if(k==0&&a==0)  break;
      inta ans=1;
      int temp;
      for(int i=0;i<k;i++)
       {
           cin>>temp;
           ans=ans/gcd(ans,temp)*temp;

       }
       cout<<ans-a<<endl;
   }


}
