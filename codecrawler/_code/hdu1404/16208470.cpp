/*
HDU 1404
*/
#include<stdio.h>
#include<math.h>
#include<iostream>
#include<string.h>
using namespace std;

const int MAXN=1000000;
int sg[MAXN];
int get_length(int n)//å¾å°æ´æ°nçä½æ°
{
    if(n/100000) return 6;
    if(n/10000) return 5;
    if(n/1000)  return 4;
    if(n/100)   return 3;
    if(n/10)  return 2;
    return 1;
}

void _extend(int n)//sg[n]=0;è¡¨ç¤ºnä¸ºåèå¿è
                   //é£ä¹æä»¥å¯ä»¥ä¸æ­¥åænçé½æ¯åèå¿è
{
    int len=get_length(n);
    int i;
    for(i=len;i>=1;i--)//æ¯ä¸ä¸ªä½ä¸å ä¸ä¸ä¸ªæ°
    {
        int m=n;
        int base=1;
        for(int j=1;j<i;j++)  base*=10;
        int tmp=(m%(base*10))/base;
        for(int j=tmp;j<9;j++)
        {
            m+=base;
            sg[m]=1;//mä¸ºåèå¿èç¹
        }
    }
    if(len!=6)//é¿åº¦å°äº6ï¼åå¯ä»¥å¨åé¢å 0å¼å¤´ç
    {
        int m=n;
        int base=1;
        for(int i=len;i<6;i++)
        {
            m*=10;
            for(int b=0;b<base;b++)
                sg[m+b]=1;
            base*=10;
        }
    }
}
void fun()
{
    memset(sg,0,sizeof(sg));
    sg[0]=1;
    for(int i=1;i<MAXN;i++)
    {
        if(!sg[i])  _extend(i);
    }
}
int main()
{
    char str[8];
    int n;
    fun();
    while(scanf("%s",&str)!=EOF)
    {
        if(str[0]=='0')  //ç¬¬ä¸ä¸ªæ°å­æ¯0ï¼ååèå¿è
        {
            printf("Yes\n");
            continue;
        }
        int len=strlen(str);//ç¬¬ä¸ä¸ªæ°å­é0ï¼åè½¬åææ´åæ°
        n=0;
        for(int i=0;i<len;i++)
        {
            n*=10;
            n+=str[i]-'0';
        }
        if(sg[n]) printf("Yes\n");
        else  printf("No\n");
    }
    return 0;
}
