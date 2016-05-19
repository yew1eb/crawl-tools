#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<algorithm>
#include<iostream>
#include<set>
#define LL long long
using namespace std;
const int N=1e5+10;
int a[N],b[N],c[N];
bool bo[N];
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       memset(bo,0,sizeof(bo));
       for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
       for(int i=0;i<n;i++)
       {
           scanf("%d",&b[i]);
           c[a[i]]=b[i];
       }
       int ans=n;
       for(int i=1;i<=n;i++)
       {
           if(!bo[i])
           {
               int x=i;
               if(c[x]!=x)
                ans--;
               while(!bo[x])
               {
                   bo[x]=1;
                   x=c[x];
               }
           }
       }
       cout<<ans<<endl;
   }
   return 0;
}
