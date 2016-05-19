#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;
typedef long long LL;
int main()
{
    int n,s,t;
    while(scanf("%d%d%d",&n,&s,&t)!=EOF)
    {
        if(n>1&&s==t)
            puts("-1");
        else if((s==1&&t==n)||(s==n&&t==1))
            puts("0");
        else if((s==1&&t!=n)||(t!=1&&s==n)||(s!=1&&s+1==t)||(s!=n&&t+1==s))
            puts("1");
        else
            puts("2");
    }
    return 0;
}
