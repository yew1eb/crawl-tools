#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<string>
#include<algorithm>
#include<iostream>
#define exp 1e-10
using namespace std;
const int N = 1005;
const int M = 10005;
const int inf = 1000000000;
const int mod = 2009;
char s[N];
int main()
{
    int i,sum,j;
    while(~scanf("%s",&s))
    {
        sum=0;j=strlen(s);
        for(i=0;s[i]!='\0';i++)
            sum+=(s[i]-'0');
        if((s[j-1]-'0')%2==0||(s[j-1]-'0')%5==0||sum%3==0)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}