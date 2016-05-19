# include <stdio.h>
# include <malloc.h>
# include <string.h>
  typedef struct node
  {
      int num;
      struct node *next;
  }Node;
  Node *T[105];
  int main()
  {
      int i,n,x,k,a,b,ans,count,front,rear,q[105],visit[105];
      Node *e;
      while(scanf("%d%d",&n,&k)!=EOF)
      {
          for(i=1;i<=n;i++)
            T[i]=NULL;
          for(i=1;i<n;i++)
          {
              scanf("%d%d",&a,&b);
              e=(Node *)malloc(sizeof(Node));
              e->num=b;
              e->next=T[a];
              T[a]=e;
          }
          for(i=1,ans=0;i<=n;i++)
          {
              memset(visit,0,sizeof(visit));
              front=rear=count=0;visit[i]=1;
              for(e=T[i];e;e=e->next)
              {
                  q[rear++]=e->num;
                  count++;visit[e->num]=1;
              }
              while(front<rear)
              {
                  x=q[front++];
                  for(e=T[x];e;e=e->next)
                    if(!visit[e->num])
                    {
                        q[rear++]=e->num;
                        visit[e->num]=1;
                        count++;
                    }
              }
              if(count==k)
                ans++;
          }
          printf("%d\n",ans);
      }
      return 0;
  }
