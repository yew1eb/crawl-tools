#include<cstdio>
#include<iostream>
using namespace std;
double t,res;
double tmp,mo;
int n;

double dfs(int k,int money)
{
    if(k==n)
    {
        mo=0.5,tmp=2*money;
        if(t>mo) return (1+t)/2*tmp;
        return (1-mo)/(1-t)*(1+mo)/2*tmp+(mo-t)/(1-t)*money;
    }
    tmp=dfs(k+1,money*2);

    mo=money/tmp;  //是为了找出平衡点
    if(t>mo) return (1+t)/2*tmp;
    return (1-mo)/(1-t)*(1+mo)/2*tmp+(mo-t)/(1-t)*money;
}

int main()
{
    while((scanf("%d%lf",&n,&t))!=EOF)
    {
        if(n==0&&t==0) break;
        res=dfs(1,1);
        printf("%.3lf\n",res);
    }
    return 0;
}