#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    int x,y,w,n;
    while(scanf("%d%d%d%d",&x,&y,&w,&n)!=-1)
    {
        if(n==1)
        {
            puts("0");
            continue;
        }
        int time=0;
        int num=1;
        while(num<n)
        {
            int cnt=0;
            for(int i=1;i<=x;i++)
            {
                if(cnt+w<=x)
                {
                    cnt+=w;
                    num++;
                }
                if(num==n) break;
            }
            time+=cnt;
            if(num==n) break;
            time=time+(x-cnt)+y;
            num++;
        }
        printf("%d\n",time);
    }
    return 0;
}
