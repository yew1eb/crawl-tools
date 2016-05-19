#include<stdio.h>
#include<string.h>
int T,cases,n,k,m,fsize;
int isver[25];
int speed[25][25];
int online[25][1010];
int get[25];
int start[25];
void init()
{
    memset(isver,0,sizeof(isver));
    memset(online,0,sizeof(online));
    memset(get,0,sizeof(get));
 memset(start,-1,sizeof(start));
}
int main()
{
    int i,j,k,temp,t;
    int s,end;
    int ti,id;
    int tspeed;
    scanf("%d",&cases);
    while(cases--)
    {
       init();
       scanf("%d%d",&n,&T);
       scanf("%d%d",&k,&fsize);
       for(i=0;i<k;i++)
       {
        scanf("%d",&temp);
        isver[temp-1]=1;
  get[temp-1]=fsize;
       }
       for(i=0;i<n;i++)
         for(j=0;j<n;j++)
            scanf("%d",&speed[i][j]);
       for(i=0;i<n;i++)
       {
            scanf("%d",&t);
            for(j=0;j<t;j++)
            {
                scanf("%d%d",&s,&end);
                for(k=s;k<end;k++)
                  online[i][k]=1;
            }
       }
       scanf("%d",&m);
       for(i=1;i<=m;i++)
       {
             scanf("%d%d",&ti,&id);
    id--;
             if(start[id]==-1||start[id]>ti)
     start[id]=ti;
       }
       for(i=0;i<T;i++)
    {
     for(j=0;j<n;j++)
     {
      if(!isver[j]&&online[j][i]&&start[j]!=-1&&start[j]<=i)
      {
       for(k=0;k<n;k++)
        if(isver[k]&&online[k][i])
         get[j]+=speed[j][k];
      }
     }
     for(j=0;j<n;j++)
      if(!isver[j]&&get[j]>=fsize)
      {
       get[j]=fsize;
       isver[j]=1;
      }
    }
       for(i=0;i<n;i++)
     printf("%d%%\n",get[i]*100/fsize);
    }
    return 0;
}