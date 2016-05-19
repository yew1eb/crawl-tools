#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#include<set>
#include<bitset>
#define ll __int64
using namespace std;
#define N 1005
int num[N];//区间数值
int f[N][20];//f[i,j]表示从第i个数起连续2^j个数中的最小值,所以第二维大小应至少log(N)/log(2)
void initRMQ(int n)//初始化RMQ (nlogn)
{
    for(int i=1;i<=n;i++)
    {f[i][0]=num[i];}
    for(int j=1;j<=log(n)/log(2);j++)
    for(int i=1;i<=n+1-(1<<j);i++)
    {f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);}
}
int RMQ(int i,int j)//查询RMQ
{
    int k=log(j-i+1)/log(2);
    return min(f[i][k],f[j-(1<<k)+1][k]);
}
int find(int from,int to,int x)//num[from,to]区间找最左边的值x
{
    for(int i=from;i<=to;i++)
    {
        if(num[i]==x)
        {return i;}
    }
}
int main()
{
    int i,j,k;
    int n,m,t;
    char ch[N];
    while(scanf("%s%d",ch,&m)!=EOF)
    {
        for(i=0;i<strlen(ch);i++)
        {num[i+1]=ch[i]-'0';}
        if(m==strlen(ch))
        {
            printf("0\n");
            continue;
        }
        initRMQ(strlen(ch));
        queue<int>Q;
        int from=1,to=m+1;
        for(i=1;i<=strlen(ch)-m;i++)
        {
            int now=RMQ(from,to);
            Q.push(now);
            int index=find(from,to,now);
            from=index+1;
            to=from+m-(index-i);
        }
        int judge=0;
        while(!Q.empty())
        {
            int now=Q.front();
            Q.pop();
            if(now==0)
            {
                if(judge==1)
                {printf("0");}
            }
            else
            {
                printf("%d",now);
                judge=1;
            }
        }
        if(judge==0)
        {printf("0");}
        printf("\n");
    }
}
/*
input:
178543 4
1000001 1
100001 2
12345 2
54321 2
output:
13
1
0
123
321
*/