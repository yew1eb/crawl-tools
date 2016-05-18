#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 1005
using namespace std;
int n;
inline int rd(int &x)
{
    char c=getchar();
    while(!isdigit(c))c=getchar();
    x=0;
    while(isdigit(c))
    {
        x=x*10+c-'0';
        c=getchar();
    }
    return x;
}
struct node
{
    int x,y,z;
} a[maxn];
bool cmp(node x1,node x2)
{
    if(x1.y==x2.y) return x1.z<x2.z;
    else
        return x1.y<x2.y;
}
int gcd(int a,int b)
{
    if(!b) return a;
    else return gcd(b,a%b);
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0; i<n; i++)
        {
            rd(a[i].x);rd(a[i].y);rd(a[i].z);
//            scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
        }
        if(n<=1)
        {
            printf("Can Take off\n");
            continue;
        }
        sort(a,a+n,cmp);
//        for(int i=0;i<n;i++)
//        {
//            cout<<a[i].x<<' '<<a[i].y<<' '<<a[i].z<<endl;
//        }
        int flag=0;
        for(int i=0; i<n-1; i++)
        {
            int l1=a[i].y,r1=a[i].z,l2=a[i+1].y,r2=a[i+1].z;
            int x1=a[i].x,x2=a[i+1].x;
            if(l2<=r1)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            printf("Cannot Take off\n");
            continue;
        }
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                 int l1=a[i].y,r1=a[i].z,l2=a[j].y,r2=a[j].z;
                 int x1=a[i].x,x2=a[j].x;
                 int Max=r2-l1,Min=l2-r1;
                 int d=gcd(x1,x2);
                 if((Min<=d&&d<=Max)||d<=(Max-Min+1))
                 {
                     flag=1;
                     break;
                 }
            }
            if(flag==1)
            {
                break;
            }
        }
        if(flag==1)
        {
            printf("Cannot Take off\n");
        }
        else
        {
            printf("Can Take off\n");
        }
    }
    return 0;
}