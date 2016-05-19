#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int prime[100000];
bool isprime[1000005]={0};
int l=1;


void creatprime()//åå»ºä¸ä¸ªç´ æ°è¡¨
{
    int i,j;
    prime[0]= 2;
    for(i=4;i<1000005;i+=2)
        isprime[i] = 1;
    for(i=3; i<1000005; i+= 2)
        if(isprime[i] == 0)
        {
            prime[l++]  = i;
            for(j=2*i;j<1000005; j+= i)
                isprime[j] = 1;
        }
}
bool is(string a,int b)//å¯¹å¤§æ°æ±ä½ï¼æ­¤é¢æ³¨éçæ¯ä½æ°æ¯å¦ç­äº0
{
    int len = a.length()-1;
    int result= (a[0]-'0')%b;
    for(int i=1;i<=len;i++)
    {
        result = (10*result+(a[i]-'0'))%b;
    }
    if(result == 0) return 1;
    else return 0;
}

int solve(string a,int b)//æ±è§£ï¼ç±äºæ­¤é¢åè¯ä½ æ¯ä¸ä¸ªä¸¤ç´ æ°çç§¯çaï¼æä»¥å¤æ­ç¸å½å®¹æ
{
    for(int i=0;i<l&&prime[i]<b;i++)
    {
        if(is(a,prime[i])) return prime[i];
    }
    return 0;
}
int main()
{
    string b;
    int a;
    creatprime();
    while(true)
    {
        char s[1000];
        scanf("%s%d",s,&a);
        b = s;
        if(b.compare("0")==0&&a==0)break;
        int k = solve(b,a);
        if(k==0) puts("GOOD");
        else printf("BAD %d\n",k);
    }
    return 0;
}