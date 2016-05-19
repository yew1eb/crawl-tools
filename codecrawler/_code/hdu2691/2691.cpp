#include <iostream>
#include <algorithm>
#include <map>
#define N 100010
#define M 50010
using namespace std;
struct data
{
    int r,l,v,d,b;                                  //r、l分别为区间的左右端点，v为查询的高度，d为输入时的顺序，b为答案
    void input(int k)
    {
        d=k;
        scanf("%d %d %d",&r,&l,&v);
    }
}p[M];
int a[N];
map<int,int>g;
bool cmp1(const data a,const data b)  //按照区间左端点排序的比较函数
{
    return a.r<b.r;
}
bool cmp2(const data a,const data b) //按照输入顺序排序的比较函数
{
    return a.d<b.d;
}
int main()
{
    int n,m,i,j,k;
    while(scanf("%d %d",&n,&m)==2)
    {
        for(i=0;i<n;i++)
            scanf("%d",a+i+1);
        for(i=0;i<m;i++)
            p[i].input(i);
        sort(p,p+m,cmp1);                       //按照区间左端点排序
        g.clear();
        map<int,int>::iterator pos;
        j=1;
        k=1;
        for(i=0;i<m;i++)
        {
            for(;j<=p[i].l&&j<=n;j++)         //将未入map的钉子加入，由于upper_bound返回的是大于等于，所以改成复数加入
                g[-a[j]]=j;
            while(1)
            {
                pos=g.lower_bound(-p[i].v);  //查询
                if(pos==g.end())                 //如果没有查到，则木板掉落到地上，输出0
                {
                    p[i].b=0;
                    break;
                }
                if(pos->second<p[i].r)      //如果查到的钉子位置在此区间以前，则删除掉
                    g.erase(pos);
                else
                {
                    p[i].b=-pos->first;     //此为查到了区间内第一个小于等于v的钉子
                    break;
                }
            }
        }
        sort(p,p+m,cmp2);         //按照输入顺序排序
        for(i=0;i<m;i++)
        {
            printf("%d\n",p[i].b);
        }
    }
    return 0;
}