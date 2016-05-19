#include<iostream>      
#include<vector>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<cmath>
#include<set>
using namespace std;
int q[5050];   int n,pi;
long long words[5050]; long long  alwaystop=-1;
void add(int u)
{
       for(int i=0;i<pi;i++)
      {
        if(u==q[i])
        {
          printf("same priority.\n");return ;
        }
      }
     printf("success.\n");
    words[pi]=0;
    q[pi++]=u;
}
void close(int u)
{
    for(int i=0;i<pi;i++)
      {
        if(u==q[i])
       {
          printf("close %d with %I64d.\n",u,words[i]);
          for(int j=i+1;j<pi;j++)
          {
              q[j-1]=q[j];
              words[j-1]=words[j];
          }
          if(u==alwaystop)
          {
              alwaystop=-1;
          }
          pi--;
          return ;
        }
      }
      printf("invalid priority.\n");
}
void chat(int u)
{
    if(pi==0)
    {
        printf("empty.\n");return;
    }
     printf("success.\n");
    if(alwaystop!=-1)
    {
        for(int i=0;i<pi;i++)
         {
             if(q[i]==alwaystop)
             {
                 words[i]=words[i]+(long long)u;return ;
             }
         }
    }
    else
      words[0]=words[0]+(long long) u;
}
void rotate(int u)
{
   if(u<1||u>pi)
   {
       printf("out of range.\n");return ;
   }
   u--;
   long long tu=q[u];
   long long tw=words[u];
   for(int i=u;i>0;i--)
   {
       q[i]=q[i-1];
       words[i]=words[i-1];
   }
   q[0]=tu;words[0]=tw;
   printf("success.\n");
}
void Prior()
{
    if(pi==0)
    {
        printf("empty.\n");return;
    }
    int maxp=-1;int id=-1;
    for(int i=0;i<pi;i++)
    {
        if( q[i]>maxp)
        {
            maxp=q[i];id=i+1;
        }
    }
    rotate(id);
}
void choose(int u)
{
    for(int i=0;i<pi;i++)
    {
        if(q[i]==u)
        {
            rotate(i+1);return ;
        }
    }
    printf("invalid priority.\n");
}
void  Top(int u)
{
    for(int i=0;i<pi;i++)
    {
        if(q[i]==u)
        {
          alwaystop=u;
           printf("success.\n");
           return ;
        }
    }
    printf("invalid priority.\n");
}
void untop()
{
    if(alwaystop==-1)
     {
        printf("no such person.\n"); return ;
     }
    alwaystop=-1;
    printf("success.\n");
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        pi=0; alwaystop=-1;
       for(int i=0;i<5019;i++)
          q[i]=words[i]=0;
        scanf("%d",&n);
        string op;
        int opi;
        for(int ii=0;ii<n;ii++)
        {
            cin>>op;
           if(op=="Add")
           {
               scanf("%d",&opi); printf("Operation #%d: ",ii+1);
               add(opi);
           }
           else if(op=="Close")
           {
                scanf("%d",&opi); printf("Operation #%d: ",ii+1);
                close(opi);
           }
           else if(op=="Chat")
           {
               scanf("%d",&opi); printf("Operation #%d: ",ii+1);
               chat(opi);
           }
           else if(op=="Rotate")
           {
               scanf("%d",&opi); printf("Operation #%d: ",ii+1);
               rotate(opi);
           }
           else if(op=="Prior")
          { printf("Operation #%d: ",ii+1);
             Prior();
          }
          else if(op=="Choose")
           {
               scanf("%d",&opi); printf("Operation #%d: ",ii+1);
               choose(opi);
           }
           else if(op=="Top")
            {
               scanf("%d",&opi); printf("Operation #%d: ",ii+1);
               Top(opi);
           }
           else if(op=="Untop")
            {   printf("Operation #%d: ",ii+1);
                    untop();
            }
        }
        for(int i=0;i<pi;i++)
        {
            if(alwaystop==q[i]&&words[i]>0)
            {
                printf("Bye %d: %I64d\n",q[i],words[i]);
            }
        }
         for(int i=0;i<pi;i++)
        {
            if(alwaystop!=q[i]&&words[i]>0)
            {
                printf("Bye %d: %I64d\n",q[i],words[i]);
            }
        }
    }
    return 0;
}
