#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <set>
#include <algorithm>
using namespace std;
#define left Left
#define right Right
#define eps 1e-8
#define maxn 60000
double x[maxn],y[maxn],r[maxn];
int left[maxn],right[maxn],up[maxn],rank_up[maxn];
int n;
set<int> my_set;
double mid;
bool cmp_left(const int &a,const int &b)
{
    return x[a]-r[a] < x[b]-r[b];
}
bool cmp_right(const int &a,const int &b)
{
    return x[a]+r[a] < x[b]+r[b];
}
bool cmp_up(const int &a,const int &b)
{
    if(y[a]==y[b])
    return  x[a] < x[b];
    else return y[a] < y[b];
}
double my_sqr(double a)
{
    return a*a;
}
bool is_cross(int a,int b)//检测高度排名为a和b的圆是否相交
{
    a=up[a],b=up[b];
    double t1,t2;
    t1=my_sqr(x[a]-x[b])+my_sqr(y[a]-y[b]),t2=my_sqr(r[a]+r[b]+mid+mid);
    if(t1<=t2)
    return true;//表示相交
    return false;
}
/*
 * 这个函数插入的是当前在集合里面圆心y值，每次再插入
 * 的同时返回插入的位置，由于set是排序了的，所以前后相邻位置
 * 的大小关系也是相邻的，那么在检测当前插入的这个圆是否与当前集合里面的圆相交
 * 就只要判断当前插入的圆与其上下两个圆是否相交就OK了
 */
bool insert(int a)//这个函数在插入的同时检测是否发生相交的情况
{
    set<int>::iterator it=my_set.insert(a).first;//这个first指向当前插入的这个元素位置的迭代器
    if(it!=my_set.begin())
    {
        if(is_cross(a,*--it))//相交
        return true;
        it++;//恢复
    }
    //注意set开始位置是元素，结束位置是位置，所以处理起来就不同了
    if(++it!=my_set.end())
    {
        if(is_cross(a,*it))
        return true;
    }
    return false;
}
bool is_ok()
{
    my_set.clear();
    int i=0,j=0;
    while(i<n || j<n)
    {
        if(j==n ||(i!=n && x[left[i]]-r[left[i]]-mid<x[right[j]]+r[right[j]]+mid))
        {
            /*这里代码在处理的时候插入的是y坐标的排名，这样的好处是插入set是
             *排序的，这样就能保证set某个元素的前后位置就是在真实圆的上下相邻位置，所以这里每次插入的是排名
             *也就是插入的不是元素，是排名，在插的时候直接插你排第几
             */
            if(insert(rank_up[left[i++]]))
                return true;//
        }
        else
        my_set.erase(rank_up[right[j++]]);
    }
    return false;
}
double find_ans()
{
    double l=0,ri=sqrt(my_sqr(x[0]-x[1])+my_sqr(y[0]-y[1]))-r[0]-r[1];//求最小的距离嘛，左值为0，右边随便取一个两个圆距离就OK了
    while(l+eps<ri)//这里不加eps可能对于某些测试数据导致超时
    {
        mid=(l+ri)/2;
        if(is_ok())
        ri=mid;
        else
        l=mid;
    }
    printf("%.6lf\n",l+ri);
    return 0;
}
int main()
{
    int t,i,j,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        scanf("%lf%lf%lf",&x[i],&y[i],&r[i]);
        for(i=0;i<n;i++)
        {
            left[i]=i;
            right[i]=i;
            up[i]=i;
        }
        sort(left,left+n,cmp_left);
        sort(right,right+n,cmp_right);
        sort(up,up+n,cmp_up);
        for(i=0;i<n;i++)
        rank_up[up[i]]=i;
        find_ans();
    }
    return 0;
}