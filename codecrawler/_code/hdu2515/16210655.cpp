#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int biao[5005];
int num[55];
int he[5005];
bool cmp(int a,int b)
{
    if(a<b)
        return true;
    else return false;
}
int main()
{
    int n,i,j,all,flag,k,x;
    while(cin>>n)
    {
        all=n*(n-1)/2;
        for(i=1;i<=all;i++)
        {
            scanf("%d",&he[i]);
        }
        sort(he+1,he+1+all,cmp);
        flag=0;
        for(i=3;i<=n+1;i++)
        {
            if(flag==1)
                break;
            for(j=1;j<=all;j++)
                biao[j]=0;
            if(((he[1]+he[2]-he[i])%2)!=0||he[1]+he[2]-he[i]<=0)
                continue;
            num[1]=(he[1]+he[2]-he[i])/2;
            num[2]=he[1]-num[1];
            num[3]=he[i]-num[2];
            biao[1]=1;
            biao[2]=1;
            biao[i]=1;
            for(j=4;j<=n;j++)
            {
                int traget=1;
                while(biao[traget]==1)
                    traget=traget+1;
                num[j]=he[traget]-num[1];
                for(k=1;k<j;k++)
                {
                    int ko=num[j]+num[k];
                    for(x=traget;x<=all;x++)
                    {
                        if(he[x]==ko&&biao[x]==0)
                        {
                            biao[x]=1;
                            break;
                        }
                    }
                }
            }
            int ok=0;
            for(j=1;j<=all;j++)
            {
                if(biao[j]==0)
                {
                    ok=1;
                    break;
                }
            }
            if(ok==0)
            {
                for(j=1;j<=n;j++)
                    cout<<num[j]<<endl;
                flag=1;
            }
        }
    }
    return 0;
}







        