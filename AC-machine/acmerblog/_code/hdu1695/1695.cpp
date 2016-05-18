/*

第一个区间：[1,2,...,b/k]  第二个区间：[b/k+1,b/k+2,...,d/k]
读第一个区间我们只要利用欧拉函数雷家没个数的质因数的个数即可，第二个区间我们任取x，
要求[1,2,...,b/k]中所有与x互质的数的个数，这里我们用到容斥原理：先将x质因数分解，
求得[1,2,...,b/k] 里所有能被x的质因数整除的数的个数，然后用b/k减去即可。 
*/ 
#include<iostream>
#include<string.h>
#define size 100010
using namespace std;
struct Num
{
   int count;
   int prime[20];
}N[size];
__int64 elur[size];

void Elur()
{
    elur[1]=1;
    for(int i=0;i<size;i++) N[i].count=0;
    for(int i=2;i<size;i++)
    {
        if(!elur[i])    //首先求素数 
        {
            for(int j=i;j<size;j+=i)
            {
                if(!elur[j]) elur[j]=j;
                elur[j]=elur[j]*(i-1)/i; //欧拉函数公式 
                N[j].prime[N[j].count]=i;
                N[j].count++;
            }
        }
        elur[i]+=elur[i-1];  //elur[i]表示前i个数的质因数的累加。
    }  
}

__int64 Inclusion_exclusion(int index , int b , int n)
{  //index表示此刻算到哪个质因数，b表示在1~b中计算被质因数整除的个数，指第二个区间的哪一个数。 
    __int64 r=0 , t;
    for(int i=index;i<N[n].count;i++)  //x与y的最大公约数为k*p(p为质数) 
    {
        t=b/N[n].prime[i];  
        r+=t-Inclusion_exclusion(i+1,t , n);  //因为防止有数被重复计算，所以根据容斥定理 
    }
    return r;
} 
int main()
{
    int a , b, c, d , k;
    int t ,tt=0;
    Elur();
    __int64 ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        if(k==0)
        {
            printf("Case %d: 0\n",++tt);
            continue;
        }
        if(b>d)
        {
           b^=d;
           d^=b;
           b^=d;
        }
        b=b/k;
        d=d/k;
        ans=elur[b];
        for(int i=b+1;i<=d;i++)
        {
            ans+=b-Inclusion_exclusion(0,b,i);
        } 
        printf("Case %d: %I64d\n",++tt,ans);
    } 
    return 0;
}