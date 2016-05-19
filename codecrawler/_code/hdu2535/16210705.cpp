#include<iostream>
#include<algorithm>
using namespace std;
int cmp(int a,int b)
{return a<b;}
int main()
{
    int n,a[102],i,s;
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
       for(i=0;i<n;i++){scanf("%d",&a[i]);a[i]=a[i]/2+1;}
       sort(a,a+n,cmp);
       s=0;
       for(i=0;i<=n/2;i++)
            s+=a[i];
       printf("%d\n",s);
    }
    return 0;
}