/*
 * 如果面对a==b 或者a>=2*b则先手比赢
 * 如果b<a<2*b.那么只有一条路，变成a-b,b;
 * 这个时候互换大小变成b,a-b.
 * 这样一直循环，看谁面对a==b || a>=2*b的情况
 */

#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)==2)
    {
        if(a==0||b==0)break;
        if(a<b)swap(a,b);
        bool flag=true;
        while(1)
        {
            if(a==b || a/b>=2)break;
            a=a-b;
            swap(a,b);
            flag=!flag;
        }
        if(flag)printf("Stan wins\n");
        else printf("Ollie wins\n");
    }
    return 0;
}