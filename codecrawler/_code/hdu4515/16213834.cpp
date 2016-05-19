#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
#define M (31+28+24)
int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
bool is_ok(int n)
{
    if((n%4==0&&n%100!=0)||n%400==0)
    return true;
    return false;
}
int main()
{
    int t,n;
    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int q=n+M;
        int now=2013;
        int s=now,s1=0;
        while(1)
        {
            if(is_ok(s))
            {
                if(q<=366)
                break;
                else
                {
                    s++;
                    q-=366;
                }
            }
            else
            {
                if(q<=365)
                break;
                else
                {
                    s++;
                    q-=365;
                }
            }
        }
        int mo=0;
        if(is_ok(s))
        a[1]=29;
        while(q>a[mo])
        {
            q-=a[mo];
            mo++;
        }
        a[1]=28;
        printf("%04d/%02d/%02d ",s,mo+1,q);

        int g=now,p;
        if(n<=M-1)
        {
            n=M-n;
            int y,r;
            if(n>31+28)
            {
                y=3;
                r=n-31-28;
            }
            else if(n>31)
            {
                y=2;
                r=n-31;
            }
            else
            {
                y=1;
                r=n;
            }
            printf("2013/%02d/%02d\n",y,r);
        }
        else
        {
            p=n-M+1;
            g=2012;
            while(1)
            {
                if(is_ok(g))
                {
                    if(p<=366)
                    break;
                    else
                    {
                        p-=366;
                        g--;
                    }
                }
                else
                {
                    if(p<=365)
                    break;
                    else
                    {
                        p-=365;
                        g--;
                    }
                }
            }
            if(is_ok(g))
            {
                a[1]=29;
            }
            mo=11;
            while(p>a[mo])
            {
                p-=a[mo];
                mo--;
            }
            a[1]=28;
            printf("%04d/%02d/%02d\n",g,mo+1,a[mo]-p+1);
        }
    }
}
