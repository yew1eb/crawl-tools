#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int a[55],b[1005];
    int i,j,ans,k,l;
    int n,m,t=0;
    while(cin>>n>>m,m&&n)
    {
        t++;
        memset(b,0,sizeof(b));
        for(i=0;i<m;i++)
            cin>>a[i];
        sort(a,a+m,cmp);
        /*for(i=0;i<m;i++)
        cout<<a[i];*/
        l=0;
        ans=0;
        for(i=m*n;i>a[m-1];i--)
        {   k=0;
            for(j=0;j<m;j++)
             {
                if(a[j]==i)
                   {
                        k=1;
                    continue;
                   }
             }
             if(!k)
             {b[l]=i;/*cout<<b[l]<<" ";*/l++;}
        }
        k=m*(n-1);
        j=0;
        for(i=0;i<m;i++)
           {
              if(a[i]<b[j])
              {
                  ans++;
                  j++;
              }
           }
           cout<<"Case "<<t<<": ";
        cout<<(m-ans)<<endl;
    }

    return 0;
}
