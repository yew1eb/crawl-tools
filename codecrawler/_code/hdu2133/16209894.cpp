#include<stdio.h>
int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
char s[7][10]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
struct date
{
    int year,month,day;
};
int leap(int year)
{
    return (year%4==0&&year%100!=0)||year%400==0;
}
int date2int(date a)//æ±å½åæ¥æå°å¬å1å¹´,1æï¼0æ¥çå¤©æ°
{
    int ret=a.year*365+(a.year-1)/4-(a.year-1)/100+(a.year-1)/400,i;
    days[1]+=leap(a.year);
    for(i=0;i<a.month-1;ret+=days[i++]);
    days[1]=28;
    return ret+a.day;
}
int judge(date b)
{
    if(b.month<=0||b.month>12)
        return 0;
    if(b.month==2)
        return b.day>0&&b.day<=28+leap(b.year);
    return b.day>0&&b.day<=days[b.month-1];
}
int main()
{
    date a,b;
    int i,n,m;
    while(scanf("%d%d%d",&a.year,&a.month,&a.day)!=-1)
    {
        if(judge(a)==0)
        {puts("illegal");continue;}
        m=date2int(a)-365;//è®¡ç®çæ¶åå ä¸äº0å¹´çå¤©æ°ï¼æä»¥è¦åå»
        //printf("%d\n",m);
        m=m%7;
        puts(s[m]);
    }
return 0;
}