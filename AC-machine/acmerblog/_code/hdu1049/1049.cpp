#include <iostream>
using namespace std;

int n,u,d;

int height;
int _time;
int main()
{
    while(cin>>n>>u>>d)
    {
         if((n&&u&&d)==0)
             break;
         height = 0;
         _time = 0;
         while(height < n)
         {
             height += u;
             _time++;
             if(height >= n)
             {
                  cout<<_time<<endl;
                  break;
             }
             height -= d;
             _time++;
         }
    }
    return 0;
}