#include <iostream>
#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;

stack<char> sta;//ç¨æ ååºå»ºç«ä¸ä¸ªæ 
char s1[100],s2[100],way[200];//s1å­ç»å®åºås2å­ç®æ åºåãwayè®°å½æä½
int cnt;
void print()//å¦ææç´¢å°æ»¡è¶³æ¡ä»¶çæ¹æ³åè¾åº
{
    int i;
    for(i=0; i<cnt; i++)
        printf("%c ",way[i]);//æ«å°¾ç©ºæ ¼å¤çäºè¿éäºãæï¼
    printf("\n");
}
void dfs(int p1,int p2)//p1è¡¨ç¤ºs1å¾å¥æ ä½ç½®.p2è¡¨ç¤ºs2å¾å¹éä½ç½®
{
    if(s2[p2]=='\0')//å¦æç®æ åºåå·²å®å¨å¹éè¾åºç­æ¡è¿å
    {
        print();
        return;
    }
    char c;
    if(s1[p1]!='\0')//å¦æs1è¿æ²¡æå®å¨è¿æ æé¢ç®è¦æ±å­å¸é¡ºåºï¼åè¿æ ååºæ æç´¢ï¼
    {
        c=s1[p1];
        sta.push(c);
        way[cnt++]='i';
        dfs(p1+1,p2);
        sta.pop();
        cnt--;
    }
    if(!sta.empty())//ååºæ ï¼å¦ææ ä¸ä¸ºç©ºï¼å¼å§æ²¡å¤æ­æ ç©ºï¼ç»ææ¾äºå¾ä¹bug
    {
        c=sta.top();
        if(c==s2[p2])//æ³¨æè¯¥å¤åªæ
        {
            sta.pop();
            way[cnt++]='o';
            dfs(p1,p2+1);
            cnt--;
            sta.push(c);
        }
    }
}
int main()
{
    while(~scanf("%s%s",s1,s2))
    {
        while(!sta.empty())
            sta.pop();
        cnt=0;
        printf("[\n");
        dfs(0,0);
        printf("]\n");
    }
    return 0;
}
