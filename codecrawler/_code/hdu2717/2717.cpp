#include<iostream>
 #include<cstdlib>
 #include<cstdio>
 #include<cmath>
 #include<cstring>
 #include<fstream>
 #include<queue>
 #define MAX 100010
 using namespace std;
 int n,k;
 int  cur,next;
 int step[MAX];
 queue<int>q;
 void bfs()
 {
         while(!q.empty())
         {
               cur=q.front();
               q.pop();
               if(cur==k)  break;
               next=cur-1;
               if(next>=0&&step[next]==0)
               {
                       q.push(next);
                       step[next]=step[cur]+1;
               }
               next=cur+1;
               if(step[next]==0)
               {
                       q.push(next);
                       step[next]=step[cur]+1;
               }
               next=cur*2;
               if(next<=100000&&(next-k)<(k-cur)&&step[next]==0)
               {
                       q.push(next);
                       step[next]=step[cur]+1;
               }
         }
 
 }
 int main()
 {
        while(scanf("%d%d",&n,&k)!=EOF)
        {
               memset(step,0,sizeof(step));
               if(n>k)
                       cout<<(n-k)<<endl;
                else
                    {
                         while(!q.empty()) q.pop();
                         q.push(n);
                         bfs();
                         cout<<step[k]<<endl;
                    }
        }
        return 0;
 }