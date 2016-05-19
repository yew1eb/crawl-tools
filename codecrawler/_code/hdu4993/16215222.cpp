#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
    int T,a,b,c;
    cin>>T;
    while(T--)
    {
      cin>>a>>b>>c;
      int cnt=0;
      for(int i=1;c-a*i>0;i++)
      {
          if((c-a*i)%b==0)
            cnt++;
      }
      cout<<cnt<<endl;
    }
    return 0;
}
