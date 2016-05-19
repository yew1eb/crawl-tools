#include<iostream>
#include<vector>
#include<map>
#include<stack>
#include<algorithm>
#include<queue>
#include<list>
#include<set>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stdio.h>
#include<ctype.h>
using namespace std;


int cal(int a,int b)
{
    int sum;
    sum=a;
    int t=1;
    while(b!=1)
    {
        if(b%2==0)
        {
            sum=sum*sum%1000;
            b/=2;
        }
        else
        {
            t=t*sum%1000;//ï¼ï¼ï¼ï¼ï¼ï¼ï¼ï¼ï¼ï¼ï¼
            b--;
        }
    }
    return t*sum%1000;
}

int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b) &&(a+b))
    {
        a%=1000;
        printf("%d\n",cal(a,b));
    }
    return 0;
}