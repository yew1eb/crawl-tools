#include<iostream>
#include<stdio.h>
#include<string.h>
#include<queue>
#include<cmath>
#include<stack>
#include<algorithm>
#define LL long long

using namespace std;

const int N=901;
const int M=8101;
int digits[N][M];
int num[N][M];

int dp(int a,int b)
{
    if(digits[a][b]!=-1)
    return digits[a][b];
    if(a==0||b==0)
    {
        if(a==0&&b==0)
        digits[a][b]=0;
        else
        digits[a][b]=101;
        return digits[a][b];
    }
    if(a>b)
    {
        digits[a][b]=101;
        return digits[a][b];
    }
    digits[a][b]=101;
    int k;
    for(int i=1;i<=9;++i)
    {
        if(a-i>=0&&b-i*i>=0)
        {
            k=dp(a-i,b-i*i);
            if(k+1<digits[a][b])
            {
                num[a][b]=i;
                digits[a][b]=k+1;
            }
        }
    }
    return digits[a][b];
}
void print(int i,int a,int b)
{
    printf("%d",num[a][b]);
    if(i>1)
    print(i-1,a-num[a][b],b-num[a][b]*num[a][b]);
}
int main()
{
    memset(digits,-1,sizeof(digits));
    memset(num,-1,sizeof(num));
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        int k=101;
        if(n<=m&&n<N&&m<M)
        k=dp(n,m);
        if(k==101)
        printf("No solution");
        else
        {
            print(k,n,m);
        }
        printf("\n");
    }
    return 0;
}