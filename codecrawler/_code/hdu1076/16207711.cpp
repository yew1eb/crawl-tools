#include <iostream>
using namespace std;

bool isLeapYear(int year)
{
     if((year % 4 == 0 && year %100 != 0)|| year % 400 == 0)
              return true;
     else
              return false;
}

int main()
{
    int Y,N,T;
    int sum = 0;
    cin>>T;
    while(T--)
    {
          cin>>Y>>N;
          if(isLeapYear(Y))
              sum = 1;
          else 
              sum = 0;
          
          while(sum < N)
          {
               Y++;
               if(isLeapYear(Y))
                  sum ++;
          }
           
          cout<<Y<<endl;      
    }
    return 0;
}
