#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
#define LL __int64
const LL mod=1e9+7;
LL a[1000001],b[1000001];
LL pows(LL a,LL b)
{
    LL s=1;
    a=a%mod;
    while(b)
    {
        if(b&1)
            s=(s*a)%mod;
        a=(a*a)%mod;
        b=b>>1;
    }
    return s;
}
int main()
{
    LL T;
    scanf("%I64d",&T);
    while(T--)
    {
        LL n,i,j,k,mul=1,p;
        scanf("%I64d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%I64d",&a[i]);
            mul=(a[i]*mul)%mod;
        }
        sort(a,a+n);
        for(i=0,j=0;i<n;i=i+2,j++)
            b[i]=a[j];
        for(i=(n%2==0?n-1:n-2),k=j;i>=0;k++,i=i-2)
            b[i]=a[k];
        LL s=0;
        for(i=1;i<n;i++)
        {
            p=(mul*pows(b[i]*b[i-1],mod-2))%mod;
            s=(s+min(b[i],b[i-1])*p%mod)%mod;
        }
        s=(mul*n-s+mod)%mod;
        printf("%I64d\n",s);
    }
    return 0;
}
/*
题意：
	输入一组n长的序列ai，表示n个格子的各自能涂的颜色数，颜色为1~ai。求找出ai的一种 
排列，使得所有颜色组合的sum和最大，sum表示一种颜色组合的片数，连续的相同颜色算一片，
输出最大的sum和 
例子：
	1,3,2
	颜色组合共6种，(1,1,1),(1,1,2),(1,2,1),(1,2,2),(1,3,1),(1,3,2)
			各自的片数 为1,2,3,2,3,3，共14片

方法：我是用找规律的方法。
	对于序列：a1,a2,a3,a4,a5，总的颜色组合有s=a1*a2*a3*a4*a5
	如果不计颜色连续，有s*5片
	其中重复的有p=min(a1,a2)*s/(a1*a2)+min(a2,a3)*s/(a2*a3)+... 
	要让s*5-p最大，p要尽可能小，所以将序列排序，然后排成一小一大一小。。顺序
	如a1<a3<a5<a4<a2

注意(a/b)%mod<-->(a%mod*pow(b,mod-2))%mod 
*/