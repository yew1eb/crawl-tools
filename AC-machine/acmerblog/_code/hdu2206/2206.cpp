#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn=100+5;
char s[maxn];
int p[maxn];//统计.的位置
int main()
{
    while(gets(s)!=NULL)
    {
        int cnt=0;
        bool flag=true;
        for(int i=0;s[i];i++)
        {
            if(s[i]=='.') p[cnt++]=i;
            if(!(s[i]=='.'||(s[i]>='0'&&s[i]<='9'))) flag=false;//非法字符
        }
        if(p[0]>=4||p[0]==0) flag=false;//第一个.不能在第一位或第三位以后
        if(cnt!=3) flag=false;//.数量不等于3
        for(int i=1;i<=2;i++)
        {
            int t=p[i]-p[i-1];
            if(t>4||t==0) flag=false;//中间数字长度0<L<=4
        }
        int c=0;
        for(int i=0;s[i];i++)//所有出现的数字小于等于255
            if(s[i]!='.') c=c*10+s[i]-'0';
            else if(c>255) flag=false;
            else c=0;
        if(c>255) flag=false;
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}