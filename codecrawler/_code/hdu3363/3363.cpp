#include<stdio.h>
#define N 100001
int n;
char ice[N];

void solve()
{
    int i,t_tol=0,h_tol=0,h=0,t=0,m=n>>1;
    for(i=0;i<n;++i)
        if(ice[i]=='H')
            h_tol++;
        else
            t_tol++;

    if((h_tol%2)||(t_tol%2))
    {
        printf("-1\n");
        return ;
    }
    for(i=0;i<m;++i)
        if(ice[i]=='H')
            ++h;
        else
            ++t;
    if(h*2==h_tol&&t*2==t_tol)
    {
        printf("1\n%d\n",m);
        return ;
    }
    for(;i<n;++i)
    {
        if(ice[i]=='H')
            h++;
        else
            t++;
        if(ice[i-m]=='H')
            --h;
        else
            --t;
        if(h*2==h_tol && t*2==t_tol)
        {
            printf("2\n%d %d\n",i-m+1,i+1);
            return ;
        }
    }
    printf("-1\n");
}
int main()
{
    while(scanf("%d",&n)==1&&n)
    {
        scanf("%s",ice);
        solve();
    }
    return 0;
}
/**
解题大意：
给你一个串，串中有H跟T两种字符，然后切任意刀，使得能把H跟T各自分为原来的一半。
解题思路：
把串想象成一个环，只要满足H跟T都为偶数个，那么就可以做一条过圆心的直线把H跟T平分掉，
过直线，只要考虑平分H或者T中的一个就可以了，因为直线本来就把环平分，而此时平分了H或者T，
那么剩下的那个也是平分掉的。

代码：枚举每个位置

*/