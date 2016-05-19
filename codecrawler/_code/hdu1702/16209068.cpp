#include<stdio.h>
#include<stack>
#include<queue>
using namespace std;
int main()
{
    int cas,i,j,n,m;
    char s[10];
    scanf("%d",&cas);
    while(cas--)
    {
          scanf("%d %s",&n,s);
          if(s[2]=='F')
          {
              queue<int>que;
              for(i=0;i<n;i++)
              {
                  scanf("%s",s);
                  if(s[0]=='I')
                  {
                      scanf("%d\n",&m);
                      que.push(m);
                  }
                  else
                  {
                      if(que.empty())
                          printf("None\n");
                      else 
                      {
                          printf("%d\n",que.front());
                          que.pop();
                      }
                  }
              }
          }
          else
          {
             stack<int>sta;
             for(i=0;i<n;i++)
              {
                  scanf("%s",s);
                  if(s[0]=='I')
                  {
                      scanf("%d\n",&m);
                      sta.push(m);
                  }
                  else
                  {
                      if(sta.empty())
                          printf("None\n");
                      else 
                      {
                          printf("%d\n",sta.top());
                          sta.pop();
                      }
                  }
              }

          }
    }
    return 0;
}