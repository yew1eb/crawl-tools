#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
struct node
{
    int a,b,c,n;
};
bool v[103][103][103];
void bfs(int a,int b,int c)
{
    memset(v,false,sizeof(v));
    node t,s;
    queue<node> q;
    t.a = a;
    t.b = 0;
    t.c = 0;
    t.n = 0;
    q.push(t);
    while(!q.empty())
    {
        t = q.front();
        q.pop();
        v[t.a][t.b][t.c]=true;
        if((t.a == a/2 && t.b == a/2)
            ||(t.a == a/2 && t.c == a/2)
            ||(t.b == a/2 && t.c == a/2))
        { 
            printf("%d\n",t.n);
            return;
        }
        if(t.a != 0)
        {
            if(t.a > b - t.b)
            {
                s.a = t.a - (b - t.b);
                s.b = b;
                s.c = t.c;
                s.n = t.n+1;
            }
            else
            {
                s.a = 0;
                s.b = t.a + t.b;
                s.c = t.c;
                s.n = t.n+1;
            }
            if(!v[s.a][s.b][s.c])
            {
                v[s.a][s.b][s.c] = true;
                q.push(s);
            }
            if(t.a > c - t.c)
            {
                s.a=t.a-(c-t.c);
                s.c=c;s.b=t.b;
                s.n=t.n + 1;
            }
            else
            {
                s.a = 0;
                s.b = t.b;
                s.c = t.a + t.c;
                s.n = t.n + 1;    
            }
            if(!v[s.a][s.b][s.c])
            {
                v[s.a][s.b][s.c] = true;
                q.push(s);
            }
        }
        if(t.b != 0)
        {
            if(t.b > a-t.a)
            {
                s.b=t.b-(a-t.a);
                s.a=a;s.c=t.c;
                s.n=t.n+1;
            }
            else
            {
                s.a = t.a + t.b;
                s.b = 0;
                s.c = t.c;
                s.n = t.n + 1;
            }
            if(!v[s.a][s.b][s.c])
            {
                v[s.a][s.b][s.c] = true;
                q.push(s);
            }
            if(t.b > c - t.c)
            {
                s.a = t.a;
                s.b = t.b - (c - t.c);
                s.c = c;
                s.n = t.n + 1;
            }
            else
            {
                s.a = t.a;
                s.b = 0;
                s.c = t.b + t.c;
                s.n = t.n + 1;
            }
            if(!v[s.a][s.b][s.c])
            {
                v[s.a][s.b][s.c] = true;
                q.push(s);
            }
        }
        if(t.c != 0)
        {
            if(t.c > a - t.a)
            {
                s.a = a;
                s.b = t.b;
                s.c = t.c - (a - t.a);
                s.n = t.n + 1;
            }
            else
            {
                s.a = t.a + t.c;
                s.b = t.b;
                s.c = 0;
                s.n = t.n + 1;
            }
            if(!v[s.a][s.b][s.c])
            {
                v[s.a][s.b][s.c] = true;
                q.push(s);
            }
            if(t.c > b - t.b)
            {
                s.a = t.a;
                s.c = t.c - (b - t.b);
                s.b = b;
                s.n = t.n + 1;
            }
            else
            {
                s.c = 0; s.a = t.a;
                s.b = t.b + t.c;
                s.n = t.n + 1;
            }
            if(!v[s.a][s.b][s.c])
            {
                v[s.a][s.b][s.c] = true;
                q.push(s);
            }
        }    
    }
    printf("NO\n");
    return;
}
int main()
{
    int a,b,c;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF)
    {
        if((a + b + c) == 0) break;
        if(a & 1) printf("NO\n");
        else
            bfs(a,b,c);
    }
    return 0;
}