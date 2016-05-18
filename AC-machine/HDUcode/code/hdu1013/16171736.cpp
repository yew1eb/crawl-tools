#include <iostream>
using namespace std;

int main()
{
    //freopen("E:\\in.txt","r",stdin);
    char c;
    int sum = 0;
    
    while(c = getchar())
    {            
        if(c == '\n')
        {
            cout << sum << endl;
            
            c = getchar();
            if(c == '0')
                break;
            else
                sum = c - '0';
            
            continue;
        }
        sum += c - '0';
        if(sum > 9)//只需处理一次即可，因为对sum处理的及时，所以sum不可能大于18 
        {
            sum = sum%10 + sum/10;
        }
    }    
    return 0;
}