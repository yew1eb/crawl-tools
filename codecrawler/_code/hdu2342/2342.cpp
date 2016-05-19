#include <iostream>
#include <string.h>
using namespace std;
int a[300],b[300];
int main()
{
    void f(int x,int y);
    int i,j,n,m,s,t,k;
    int x,y;
    while(cin>>n>>m)
    {
        memset(a,0,sizeof(a));
        for(i=0;i<=n-1;i++)
        {
            b[i]=i;
        }
        s=0;
        for(i=0;i<=m-1;i++)
        {
            cin>>x>>y;
            a[y]++; a[x]++;
             f(x,y);
        }
        for(i=0;i<=n-1;i++)
        {
            if(b[i]==i)
            {
                s+=1;
            }
            if(s>1)
            {
                break;
            }
        }
        if(s==1)
        {
            for(i=0;i<=n-1;i++)
            {
                if(a[i]%2!=0)
                {
                    break;
                }
            }
            if(i==n)
            {
                cout<<"Possible"<<endl;
            }else
            {
                cout<<"Not Possible"<<endl;
            }
        }else
        {
            cout<<"Not Possible"<<endl;
        }
    }
    return 0;
}
int find(int x)
{
    int k1,k2;
    k1=x;
    while(k1!=b[k1])
    {
        k1=b[k1];
    }
    while(x!=b[x])
    {
        k2=b[x];
        b[x]=k1;
        x=k2;
    }
    return k1;
}
void f(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x!=y)
    {
        b[x]=y;
    }
}