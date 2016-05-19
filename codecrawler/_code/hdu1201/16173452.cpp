//Problem:hdu1201
//Data:2011 11 1

#include <iostream>
using namespace std;

bool isleapYear(int year)
{
    if(year%4==0 && year%100!=0 || year%400==0)
        return true;
    else
        return false;
}

int main()
{
    //freopen("E:\\in.txt","r",stdin);
    int t;
    int year,month,day;    
    cin >> t;
    while(t--)
    {
        cin >> year;
        cin.get();        
        cin >> month;
        cin.get();
        cin >> day;
        int leapyear = 0;
        //åç®åºä¸­é´å±æå ä¸ªé°å¹´ 
        for(int i=year; i<=year+18; i++)
            if(isleapYear(i))
                leapyear++;
        //æä¸¤ç§æåµï¼åå¼è®¨è®º
        //æåµä¸ï¼å¦æåºçé£å¹´æ¯é°å¹´ 
        if(isleapYear(year))
        {
            if(month == 2 && day == 29){
                cout << -1 << endl;
                continue;
            }
            if(month > 2)
                leapyear--;
        }
        
        //æåµäºï¼å¦æ18å²é£å¹´æ¯é°å¹´ 
        if(isleapYear(year+18))
        {
            if(month <= 2)
                leapyear--;            
        }
        cout << 6570 + leapyear;
        cout << endl;
    }
    return 0;
}
