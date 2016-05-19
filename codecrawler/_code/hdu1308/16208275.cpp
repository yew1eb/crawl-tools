#include<stdio.h>
int month_day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};//begin with 1
int leap_month_day[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};//begin with 1
typedef struct date
{
    int year;
    int month;
    int day;
    int week;
}date,* date_link;
char week_map[8][10]={"","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};//begin with 1
char month_map[13][10]={"","January","February","March","April","May","June","July","August","September","October","November","December"};//begin with 1
int in_year,in_month,in_day;
date date_start;
bool is_leap(int year)
{
    if(year<=1582) return(year%4==0);
    else return((year%4==0&&year%100!=0)||(year%400==0));
}
int comp_date(date a,date b)
{
    int a_num=a.year*10000+a.month*100+a.day;//ip to number to compare ip easily
    int b_num=b.year*10000+b.month*100+b.day;
    return(a_num-b_num);
}
void walk_day(date &a,int growth)
{
    //week
    a.week+=growth;
    if(a.week==0) a.week=7;
    if(a.week==8) a.week=1;
    //date
    if((a.year==1582&&a.month==10&&a.day==4&&growth==1)) growth=11;
    if((a.year==1582&&a.month==10&&a.day==15&&growth==-1)) growth=-11;
    if((a.year==1752&&a.month==9&&a.day==2&&growth==1)) growth=12;
    if((a.year==1752&&a.month==9&&a.day==14&&growth==-1)) growth=-12;
    a.day+=growth;
    if(a.day<1)
    {
        a.month--;
        a.day=is_leap(a.year)?leap_month_day[a.month]:month_day[a.month];
        if(a.month<=0)
        {
            a.year--;
            a.month=12;
            a.day=is_leap(a.year)?leap_month_day[a.month]:month_day[a.month];
        }
    }
    int bound = is_leap(a.year)?leap_month_day[a.month]:month_day[a.month];
    if(a.day>bound)
    {
        a.month++;
        a.day=1;
        if(a.month>=13)
        {
            a.year++;
            a.month=1;
            a.day=1;
        }
    }
}
int start_walk_rear(date &start,date &rear,int cmp)
{
    int growth=0;
    if(cmp>0) growth=-1;
    if(cmp<0) growth=1;
    //walk to year's start or end
    while(comp_date(start,rear)) walk_day(start,growth);
    rear.week=start.week;
    return(0);
}
bool is_valid_date(date a)
{
    if(a.year<=0) return(false);
    if(a.month<=0||a.month>=13) return(false);
    if(!is_leap(a.year)&&(a.day<=0||a.day>month_day[a.month])) return(false);
    if(is_leap(a.year)&&(a.day<=0||a.day>leap_month_day[a.month])) return(false);
    return(true);
}
int main()
{
    date_start.year=2014;date_start.month=9;date_start.day=9;date_start.week=2;
    while(scanf("%d%d%d",&in_month,&in_day,&in_year)!=EOF&&(in_year+in_month+in_day)>0)
    {
        date date_end;date_end.year=in_year;date_end.month=in_month;date_end.day=in_day;
        if(is_valid_date(date_end))
        {
            start_walk_rear(date_start,date_end,comp_date(date_start,date_end));
            printf("%s %d, %d is a %s\n",month_map[date_end.month],date_end.day,date_end.year,week_map[date_end.week]);
        }
        else {printf("%d/%d/%d is an invalid date.\n",date_end.month,date_end.day,date_end.year);}
    }
    return(0);
}
