#include<iostream>
#include<cstring>
using namespace std;
int n,m;
int mark[6400];
int vis[85][85];   
int main()
{
    int T;
    cin>>T;int ct=1;
    while(T--)
    {
        for(int i=0;i<=m;i++)
            mark[i]=0;
        memset(vis,0,sizeof(vis));
           cin>>n>>m;
        for(int i=1;i<n;i++)
        {
           // cout<<i<<" "<<i+1<<" "<<i<<endl;
            mark[i]=1;vis[i][i+1]=vis[i+1][i]=i;
        }
        int tei=0;
        for(int i=n;i<n+3;i++)
           if((n*(n-1)/2+i)%3==0)
           {
              //cout<<n<<" "<<1<<" "<<i<<endl;
              tei=i;
              mark[i]=1;
              vis[n][1]=vis[1][n]=i;
              break;
          }
       for(int i=n;i<=m;i++)
       {
           if(!mark[i])
           {
               int flags=0;
               for(int j=1;j<=n;j++)
               {

                for(int k=j+2;k<=n;k++)
                {

                    if(!vis[j][k]&&((k-j)*(j+k-1)/2)%3==i%3)
                    {
                        vis[j][k]=vis[k][j]=i;
                        mark[i]=1;
                        flags=1;
                        break;
                    }
                }
                if(flags)break;
               }
           }
       }
       bool flag=1;
       for(int i=1;i<=m;i++)
       {
           if(mark[i]==0)
             {
                 flag=0;break;
             }
       }
       cout<<"Case #"<<ct++<<":"<<endl;
       if(flag==0)
       cout<<-1<<endl;
       else
       {
           for(int i=1;i<=n;i++)
             for(int j=(i+1);j<=n;j++)
             {
                 if(vis[i][j]!=0&&!(i==1&&j==n))
                 {
                     cout<<i<<" "<<j<<" "<<vis[i][j]<<endl;
                 }
             }
            cout<<n<<" "<<1<<" "<<tei<<endl;
       }
    }
}
