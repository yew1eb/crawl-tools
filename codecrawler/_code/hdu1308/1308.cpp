#include <iostream>
#include <string>
using namespace std;
const string MonthName[]={"January", "February", "March", "April", "May", "June", "July",
	"August", "September", "October", "November", "December"};
const string WeekName[]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
const int DayNum[]={31,0,31,30,31,30,31,31,30,31,30,31};
bool isLeap(int y)
{
	if(y>1752)
		return (y%400==0 || ((y%4==0)&&(y%100!=0)));
	else return y%4==0;
}
int YearDays(int y)
{
	return (isLeap(y) ? 366 : 365);
}
int MonthDays(int y,int m)
{
	if(m != 2) return DayNum[m-1];
	else //m==2
	{
		if(isLeap(y)) return 29;
		else return 28;
	}
}
bool isValid(int y, int m, int d)
{
	if(m<1 || m>12) return false;
	if(d<1 || d>MonthDays(y,m)) return false;
	if(y==1752 && m==9 && d>=3 && d<=13) return false;
	return true;
}
struct Date
{
	int Y,M,D;
	Date():Y(0),M(0),D(0){}
	Date(int y,int m,int d):Y(y),M(m),D(d){}
};
istream& operator>>(istream& in, Date& date)
{
	in>>date.M>>date.D>>date.Y;
	return in;
}
ostream& operator<<(ostream& out, const Date& date)
{
	out<<MonthName[date.M-1]<<' '<<date.D<<", "<<date.Y;
	return out;
}
bool operator<(const Date& lh,const Date& rh)
{
	if(lh.Y != rh.Y) return (lh.Y < rh.Y);
	else
	{
		if(lh.M != rh.M) return (lh.M < rh.M);
		else return (lh.D < rh.D);
	}
}
int main()
{
	Date date;
	while(cin>>date)
	{
		if(date.Y==0 && date.M==0 && date.D==0) break;
		if(!isValid(date.Y,date.M,date.D))
		{
			cout<<date.M<<'/'<<date.D<<'/'<<date.Y<<" is an invalid date.\n";continue;
		}
		int days=-1,i; //1 1 1到底是星期几？
		for(i=1;i<date.Y;++i) days += YearDays(i);
		for(i=1;i<date.M;++i) days += MonthDays(date.Y, i);
		days += (date.D-1);
		if(Date(1752,9,2) < date) days -= 11;
		cout<<date<<" is a "<<WeekName[days%7]<<endl;
	}
	return 0;
}