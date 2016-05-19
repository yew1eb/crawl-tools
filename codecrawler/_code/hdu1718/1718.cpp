#include<stdio.h>
#include<math.h>
#include <queue>
#include<algorithm>
#include <iostream>
#include <string.h>
using namespace std;

int num[1001];

int main()
{
    int dir;
    while(~scanf("%d",&dir))
    {
        memset(num,0,sizeof(num));
        int a,b,score=-1,t=0,ans=0;
        while(~scanf("%d%d",&a,&b))
        {
            if(a==0&&b==0)break;
            if(score!=-1)
            {
                if(b>score)ans++;
            }
            else
            {
                if(a==dir)score=b;
                else num[t++]=b;
            }
        }
        for(int i=0;i<t;i++)
        {
            if(num[i]>score)ans++;
        }
        printf("%d\n",ans+1);
    }
    return 0;
}