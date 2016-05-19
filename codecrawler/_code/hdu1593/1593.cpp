#include <iostream>
#define PI 3.1415926
using namespace std;


int main()
{
    int  R,v1,v2;

    while(cin>>R>>v1>>v2)
   {
      double t1,t2;
      t2=R*1.0*PI/v2;
      t1=(R-v1*1.0/(v2*1.0/R))*1.0/v1;



      if(t1<t2)
      cout<<"Yes"<<endl;
      else
      cout<<"No"<<endl;
   }

return 0;
}