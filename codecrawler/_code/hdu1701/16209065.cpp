#include <iostream>
using namespace std;
int main()
{
    int t,i;double a,b;
    cin>>t;
    while (t--)
    {
        cin>>a>>b;        
        for(i=1;;i++)
        {
            if ((int)(a*i/100)<(int)(b*i/100))
                break;
        }
        cout<<i<<endl;
    }
    return 0;
}