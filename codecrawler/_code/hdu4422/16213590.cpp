#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<string>
using namespace std;
int n=0;
int w[6]={0};
bool Vis[6]={false};
int Sum=0,MaxSum=0;
int flag=false;
int ans=0;
/*init the var*/
int InitVar()
{
    Sum=0;
    MaxSum=0;
    memset(Vis,false,sizeof(Vis));
    flag=false;
    ans=0;
    return(0);
}
/*DFS the w[i]*/
bool DFS3(int cur)
{
    if(flag)
    {
        return(flag);
    }
    if(cur==4)//have count 3
    {
        if(Sum%1024==0)
        {
            flag=true;
        }
        return(flag);
    }
    else
    {
        int i=0;
        for(i=1;i<=n;i++)
        {
            if(Vis[i]==false)
            {
                Vis[i]=true;
                Sum+=w[i];
                DFS3(cur+1);
                Vis[i]=false;
                Sum-=w[i];
            }
        }
        return(flag);
    }
}
/*DFSSub pass 1  and  2  entry*/
int DFSSub(int cur,int cnt)
{
    if(cur==cnt+1)
    {
        if(cnt==2)//n=4
        {
            int Sums=w[1]+w[2]+w[3]+w[4]-Sum;
            while(Sums>1024)
            {
                Sums-=1024;
            }
            if(Sums>MaxSum)
            {
                MaxSum=Sums;
            }
        }
        else//n=5
        {
            int Sums=0;
            if(Sum%1024!=0)
            {
                Sums=0;
            }
            else
            {
                Sums=w[1]+w[2]+w[3]+w[4]+w[5]-Sum;
                while(Sums>1024)
                {
                    Sums-=1024;
                }
                if(Sums>MaxSum)
                {
                    MaxSum=Sums;
                }
            }
        }
    }
    else
    {
        int i=0;
        for(i=1;i<=n;i++)
        {
            if(Vis[i]==false)
            {
                Vis[i]=true;
                Sum+=w[i];
                DFSSub(cur+1,cnt);
                Vis[i]=false;
                Sum-=w[i];
            }
        }
    }
    return(0);
}
/*for test*/
int test()
{
    return(0);
}
/*main process*/
int MainProc()
{
    while(scanf("%d",&n)!=EOF)
    {
        int i=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&w[i]);
        }
        InitVar();
        if(n<=3)
        {
            printf("1024\n");
        }
        else
        {
            if(n==4)
            {
                //C43
                if(DFS3(1))//could % 1024 ==0
                {
                    printf("1024\n");
                }
                else
                {
                    //C42=6,DFS get 2 bags randomly
                    DFSSub(1,2);
                    printf("%d\n",MaxSum);
                }
                
            }
            else
            {
                //get 3 bags randomly
                DFSSub(1,3);
                printf("%d\n",MaxSum);
            }
        }
    }
    return(0);
}
int main()
{
    MainProc();
    return(0);
}
