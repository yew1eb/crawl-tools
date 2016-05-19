#include <iostream>
using namespace std;
int gcd(int a, int b)
{   return b? gcd(b, a%b):a;
}
int main()
{
   int n, a, b, c, i;
   cin>>n;
   while(n--)
{
   cin>>a>>b;
   for(i=b+1; ; ++i)
     if(gcd(i, a) == b)
        {    c = i; break;}
   cout<<c<<endl;
}
return 0;
}