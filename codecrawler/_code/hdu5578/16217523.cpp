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
#include<stdlib.h>
#include<cmath>
#include<string>
#include<algorithm>
#include<iostream>
#define exp 1e-10
#define MAX(a,b) ((a)>(b)?(a):(b))
using namespace std;
const int N = 1005;
const int M = 2010;
const int inf = 2147483647;
const int mod = 2009;
char s[N];
int main()
{ 
    int t,i,j,Min,p=1;
    scanf("%d",&t);
    while(t--)
    {
        Min=inf;
        scanf("%s",s);
        for(i=0;s[i]!='\0';i++)
            for(j=i+1;s[j]!='\0';j++)
                if(s[i]==s[j])
                    Min=min(Min,j-i);
        printf("Case #%d: ",p++);                    
        if(Min!=inf)
            printf("%d\n",Min);
        else
            puts("-1");
    }
    return 0; 
}