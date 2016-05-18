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
		//先算出中间共有几个闰年 
		for(int i=year; i<=year+18; i++)
			if(isleapYear(i))
				leapyear++;
		//有两种情况，分开讨论
		//情况一：如果出生那年是闰年 
		if(isleapYear(year))
		{
			if(month == 2 && day == 29){
				cout << -1 << endl;
				continue;
			}
			if(month > 2)
				leapyear--;
		}
		
		//情况二：如果18岁那年是闰年 
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