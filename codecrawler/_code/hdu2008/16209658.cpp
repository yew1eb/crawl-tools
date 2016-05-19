#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
        int ans1=0,ans2=0,ans3=0;
        double d;
        for(int i=0;i<n;i++)
        {
            scanf("%lf",&d);
            if(d<0)ans1++;
            else if(d==0)ans2++;
            else ans3++;
        }
        printf("%d %d %d\n",ans1,ans2,ans3);
    }
    return 0;
}