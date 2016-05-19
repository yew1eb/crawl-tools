#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int maxm=1e3+10;
char s[maxm];
int main()
{
    while(scanf("%s",s)!=EOF)
    {
        int sum1=0,sum2=0,sum3=0;
        int len=strlen(s);
        for(int i=0;i<len;i++)
        {
            sum1=(sum1*10+s[i]-'0')%2;
        }
        for(int i=0;i<len;i++)
        {
            sum2=(sum2*10+s[i]-'0')%3;
        }
        for(int i=0;i<len;i++)
        {
            sum3=(sum3*10+s[i]-'0')%5;
        }
        if(sum1==0||sum2==0||sum3==0)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
