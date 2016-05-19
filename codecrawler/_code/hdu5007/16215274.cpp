#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;


int main()
{
    char s[10010],t[10010];
    memset(s,0,sizeof(s));
    while(scanf("%s",t)!=EOF)
    {
        strcat(s,t);
    }
    int len=strlen(s);
    for(int i=0;i<len;i++)
    {
        if(i+3<len)
        {
            if(s[i]=='i'&&s[i+1]=='P'&&s[i+2]=='o'&&s[i+3]=='d') printf("MAI MAI MAI!\n");
            if(s[i]=='i'&&s[i+1]=='P'&&s[i+2]=='a'&&s[i+3]=='d') printf("MAI MAI MAI!\n");
            if(s[i]=='S'&&s[i+1]=='o'&&s[i+2]=='n'&&s[i+3]=='y') printf("SONY DAFA IS GOOD!\n");
        }
        if(i+4<len)
        {
            if(s[i]=='A'&&s[i+1]=='p'&&s[i+2]=='p'&&s[i+3]=='l'&&s[i+4]=='e') printf("MAI MAI MAI!\n");
        }
        if(i+5<len)
        {
            if(s[i]=='i'&&s[i+1]=='P'&&s[i+2]=='h'&&s[i+3]=='o'&&s[i+4]=='n'&&s[i+5]=='e') printf("MAI MAI MAI!\n");
        }
    }
    return 0;
}