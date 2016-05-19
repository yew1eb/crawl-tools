#include<iostream>
#include<cstdlib>
#include<stdio.h>
using namespace std;
const int N=2000000;
int a[N],b[N];
int main()
{
    int t,n,k;
    int count=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        a[0]=b[0]=1;
        int i=0,j=0;
        while(a[i]<n)
        {
            i++;
            a[i]=b[i-1]+1;
            while(a[j+1]*k<a[i])
            j++;
            if(a[j]*k<a[i])  b[i]=b[j]+a[i];
            else b[i]=a[i];
        }
        printf("Case %d: ",count++);
        if(a[i]==n) puts("lose");
        else
        {
            int ans;
            while(n)
            {
                if(n>=a[i])
                {
                    n-=a[i];
                    ans=a[i];
                }
                i--;
            }
            cout<<ans<<endl;
        }

    }
}
