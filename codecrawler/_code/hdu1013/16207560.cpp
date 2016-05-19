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
        if(sum > 9)//åªéå¤çä¸æ¬¡å³å¯ï¼å ä¸ºå¯¹sumå¤ççåæ¶ï¼æä»¥sumä¸å¯è½å¤§äº18 
        {
            sum = sum%10 + sum/10;
        }
    }    
    return 0;
}