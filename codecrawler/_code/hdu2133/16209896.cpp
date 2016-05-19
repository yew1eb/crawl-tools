#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

int a[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
int b[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
char s[8][10] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
bool IsRunNian(int year)
{
    if((year%4==0 && year%100!=0) || year%400==0)
        return true;
    return false;
}
int main()
{
    int year,month,day;
    while(cin >> year >> month >> day)
    {
        if(IsRunNian(year))
        {
            if(day > a[month] || month == 0 || day == 0)
            {
                cout << "illegal" << endl;
                continue;
            }
        }
        else
        {
            if(day > b[month] || month == 0 || day == 0)
            {
                cout << "illegal" << endl;
                continue;
            }
        }
        int sum = 0;
        for(int i = 1; i < year; ++i)
        {
            if(IsRunNian(i))
                sum += 366;
            else
                sum += 365;
            sum %= 7;
        }
        for(int i = 0; i < month; ++i)
        {
            if(IsRunNian(year))
                sum += a[i];
            else
                sum += b[i];
            sum %= 7;
        }

        sum += day;
        sum %= 7;
        cout << s[sum] << endl;
    }

    return 0;
}
