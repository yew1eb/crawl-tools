#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
struct Hero
{
    int DPS;
    int HP;
}hero[21];
bool cmp(const Hero &a,const Hero &b)
{
    return a.HP*b.DPS<a.DPS*b.HP;
}
int main()
{
    int N;
    while(scanf("%d",&N)!=EOF)
    {
        int sum=0;
        int zsum=0;
        for(int i=0;i<N;++i)
        {
            cin>>hero[i].DPS>>hero[i].HP;
            zsum+=hero[i].DPS;
        }
        sort(hero,hero+N,cmp);
        for(int i=0;i<N;++i)
        {
            sum+=zsum*hero[i].HP;
            zsum-=hero[i].DPS;
        }
        cout<<sum<<endl;
    }
    return 0;
}