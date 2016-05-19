#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<string.h>
#include<string.h>
#include<memory.h>
using namespace std;
int sg[50];
int num[7];
bool dfs(int sum)
{
    if(sum>=31) return 0;
    for(int i=1;i<=6;i++)
    {
        if(num[i]&&sum+i<=31)
        {
            --num[i];
            if(dfs(sum+i)==0) {++num[i];return 1;}
             ++num[i];//åæº¯
        }
    }
    return 0;
}
int main()
{
    char str[35];
    while(scanf("%s",str)!=EOF)
    {
        int sum=0;
        int l=strlen(str);
        for(int i=1;i<=6;i++)
        num[i]=4;
        for(int i=0;i<l;i++)
        {
            sum+=str[i]-'0';
            num[str[i]-'0']--;
        }
        if(sum>=31)
        {
            printf("%s ",str);
            if(l&1) puts("A");
            else puts("B");
            continue;
        }
        printf("%s ",str);
        if(dfs(sum))
        {
            if(l&1)  puts("B");
            else puts("A");
        }
        else
        {
         if(l&1)  puts("A");
         else puts("B");
       }
    }
}
/*
356656
35665
3566
111126666
552525
*/
