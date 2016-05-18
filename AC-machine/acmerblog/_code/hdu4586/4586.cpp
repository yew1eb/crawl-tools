/**
hdu 4586  概率dp
题目大意：给定一个骰子，有n个面，掷得i面朝上获得a[i]的money，其中有m个面掷得其中之一朝上除了获得money外，并获得再掷一次的机会
          问掷一个回合获得money的期望
解题思路：（kuangbin）
          设所求期望为ans
          那么ans=1/N *(A[B[1]]+ans) + 1/N *(A[B[2]]+ans)  + ...1/N *(A[B[M]]+ans) + 1/N A[k]+....
          ans=M/N *ans+1/N*(A[1]+A[2]+A[3]+....+A[N]);
          (N-M)ans= A[1]+A[2]+...+A[N]=sum;
          如果sum==0,答案为0.00
          如果sum!=0,N-M==0  答案为inf
          否则答案就是sum/(N-M);
*/
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int a[1005],b[1005];

int main()
{
    while(~scanf("%d",&n))
    {
        double sum=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        scanf("%d",&m);
        for(int i=0;i<m;i++)
        {
            scanf("%d",&b[i]);
        }
        if(sum==0.0)printf("0.00\n");
        else if(n==m)printf("inf\n");
        else printf("%.2lf\n",sum/(n-m));
    }
    return 0;
}
