#include<iostream>
using namespace std;
bool vis[60];
int num[60];
bool compare(int a,int b)
{
     return a<b;
}
int main()
{
    int n,k,sum,temp;
    while(scanf("%d%d",&n,&k)!=EOF&&!(n==0&&k==0))
    {
                 sum=0;
                 memset(vis,false,sizeof(vis));
                 for(int i=0;i!=n;i++)
                 {
                         scanf("%d",&num[i]);
                         vis[i]=true;
                 }
                 sort(num,num+n,compare);
                 for(int i=0;i<n;i++)
                 {
                         if(vis[i])//当前玩具未被出售
                         {
                                   for(int j=i+1;j<n;j++)//寻找未被出售而且大小是当前玩具的k倍的玩具
                                   {
                                           if(vis[j]&&num[j]==k*num[i])
                                           {
                                                                       sum++;
                                                                       vis[i]=vis[j]=false;
                                                                       break;
                                           }
                                   }
                         }
                 }
                 cout<<sum<<endl;
    }
return 0;
}