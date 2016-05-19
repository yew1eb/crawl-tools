#include <stdio.h>
#include <string.h>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
#define inf 0xfffff
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {   int s=0,t;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {scanf("%d",&t);s+=t;}
        printf("%d\n",s+1-n);
    }
}