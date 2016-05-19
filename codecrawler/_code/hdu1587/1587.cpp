#include<iostream>
#include<cstdio>
#define Max 100001
using namespace std;
int f[Max],bag,c[1001];
void MultiplePack(int cost,int weight)
{
     for(int i=cost;i<=bag;i++)
        if(f[i]<f[i-cost]+weight)
           f[i]=f[i-cost]+weight;
}
int main()
{
    int n;
    while(scanf("%d%d",&n,&bag)!=-1)
    {
         for(int i=1;i<=n;i++)
           scanf("%d",&c[i]);
         memset(f,0,sizeof(f));
         for(int i=1;i<=n;i++)
            MultiplePack(c[i],1);
         printf("%d/n",f[bag]);
    }
    return 0;
}