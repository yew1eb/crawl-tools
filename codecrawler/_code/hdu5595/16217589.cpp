#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b,c,l,r;
        scanf("%d%d%d%d%d",&a,&b,&c,&l,&r);
        int cnta=a*l*l+b*l+c;
        int cntb=a*l*l+b*l+c;
        for(int i=l+1;i<=r;i++)
        {
            int sum=a*i*i+b*i+c;
            cnta=max(sum,cnta);
            cntb=min(sum,cntb);
        }
        printf("%d %d\n",cnta,cntb);
    }
}
