#include<stdio.h>
#include<map>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#define MAX 1000000000
using namespace std;
map<string,  int> my_map;
int cnt,head[250],dis[250];
int n;
struct Edge
{
    int from,to,w,next;       
}edge[20005];
void add(int from,int to,int w)
{
    edge[cnt].to=to;
    edge[cnt].w=w;
    edge[cnt].next=head[from];
    head[from]=cnt++;    
}
int spfa(int s)
{
    queue<int> Q;
    for(int i=1;i<250;i++)
    dis[i]=MAX; 
    dis[s]=0;
    Q.push(s);
    int visit[250];
    memset(visit,0,sizeof(visit));
    visit[s]=1;
    while(!Q.empty())
    {
        int k=Q.front();
        Q.pop();
        visit[k]=0;
        for(int i=head[k];i+1;i=edge[i].next)
        {
            int to=edge[i].to;
            int w=edge[i].w;
            if(dis[k]+w<dis[to])
            {
                dis[to]=dis[k]+w;
                if(!visit[to])
                {
                    visit[to]=1;
                    Q.push(to);          
                }                    
            }
        }                 
    } 
    return 1;       
}
int main()
{
  int juli;
  while(scanf("%d",&n)!=EOF)
    {
      if(n==-1)  break;
      my_map.clear();
      cnt=1;
        for(int i=1;i<250;i++)
         {
            edge[i].next=-1;
            head[i]=-1;
         }
      char s[100],t[100],l[100],ll[100];
     scanf("%s%s",s,t);
      int count=1;
      if(my_map[s]==0)
      my_map[s]=count++;
      int st=my_map[s];
      if(my_map[t]==0)
      my_map[t]=count++;
      int end=my_map[t];
      
      int flag=0;
      for(int i=0;i<n;i++)
       {
        scanf("%s%s",l,ll);
        scanf("%d",&juli);
        if(my_map.find(l)==my_map.end())  my_map[l]=count++;       
        int a=my_map[l];
        if(my_map.find(ll)==my_map.end())  my_map[ll]=count++;
        int b=my_map[ll];
        add(a,b,juli);
        add(b,a,juli);
       }
      
      spfa(my_map[s]);
      if(dis[my_map[t]]>=MAX)
        printf("-1\n");
      else printf("%d\n",dis[my_map[t]]);
    }    
}