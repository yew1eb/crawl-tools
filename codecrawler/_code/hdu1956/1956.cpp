//DFS+剪枝优化
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;
int numbers[25];
bool used[25];
int side;
int num;
bool cmp(int a,int b)
{
    return a>b;
}
bool dfs(int tsum,int cur,int leave)    //tsum:这个边已经组了多长；cur：正在组的是第几条边；leave:组这条边已经用了几根棒
{
    if(tsum==side)
    {
        cur++;
        tsum=0;
    }
    if(cur==4)return true;

    for(int i=leave; i<num; i++)   //i从leave开始。因为对棒已经降序排过序了，再搜索只需要对leave之后的棒进行搜索，它之前的肯定是不会符合的。
    {
        if(i&&numbers[i]==numbers[i-1]&&!used[i-1])//相邻的相等的前者没有加入，则这个也不行。
            continue;

        if(used[i]==0)
        {
            if(tsum+numbers[i]<side)
            {
                used[i]=1;
                if(dfs(tsum+numbers[i],cur,i+1))return true; //搜索的起始点很重要。i+1传入了下层递归搜索的起始点
                used[i]=0;
            }
            if(tsum+numbers[i]==side)
            {
                used[i]=1;
                if(dfs(0,cur+1,0))
                return true;

                used[i]=0;
            }
            if(tsum==0)break;
        }
    }

    return false;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int sum=0;
        scanf("%d",