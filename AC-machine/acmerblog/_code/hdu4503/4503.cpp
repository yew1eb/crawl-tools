#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        int i,j,k,s=0,a;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a);
            s+=a*(n-1-a);
        }
        int t=n*(n-1)*(n-2)/6;//C(n,3)
        printf("%.3lf\n",1-1.0*s/2/t);
    }
    return 0;
}
/*
    要求符合要求的概率，可以先求不符合的
    不符合就是，一个人a，与b是朋友，与c不是朋友，b和c随意
    则对于第i个人，其可能的朋友组合有ai*(n-ai-1),其中有重复的。
    取重复：由于选定的是一个人，对于上述a，b，c，重复的就是讨论选a，b，c三种时的重复关系
    上述(=为是朋友，!=为不是朋友)a=b,a!=c,b?c
    若b=c,选定人是b时不可以，因为b=a,b=c不符合；选定人是c时可以，c!=a,c=b符合
    若b!=c,选定人是b时可以，因为b=a,b!=c符合；选定人是c时不可以，c!=a,c!=b不符合
    综上可知，重复了一次，总数/2就是不符合的结果
*/