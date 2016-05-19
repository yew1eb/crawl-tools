#include<iostream>
using namespace std;
int main()
{
   double v,d;
   while(cin>>v>>d)
   {
      double dishu=v/d;
      int numdi=dishu;
      if(dishu-numdi!=0.0)numdi++;
      int i,x=1;
      while((x+1)*x/2<numdi)
      {
         x++;
      }
      x--;
      cout<<x+numdi<<endl;
   }
   return 0;
}