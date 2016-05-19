/*å1907å ä¹å®å¨ä¸æ ·ï¼ä¸è§£é*/
#include <iostream>  
using namespace std;  
int value[101];  
int main ()  
{  
    int n,sum,temp, i, cnt; 
    while (cin>>n)  
    {
        sum = 0;cnt = 0;
        for(i = 0; i < n; i++)
        {
            cin>>temp;
            sum = sum^temp;
            if(temp > 1)
                cnt = 1;
        }
        if(cnt == 0)
            sum = ( (n-1) % 2 );
        if(sum == 0)
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;
    }  
    return 0;  
}