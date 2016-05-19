#include <set>
#include <map>
#include <queue>
#include <stack>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <limits.h>
#include <string.h>
#include <string>
#include <algorithm>
#define MID(x,y) ( ( x + y ) >> 1 )
#define L(x) ( x << 1 )
#define R(x) ( x << 1 | 1 )
#define BUG puts("here!!!")

using namespace std;

const int MAX = 310;
const int LALA = 200000;
struct NODE{  
    int from,to,cap,cost;  
    int next;  
};  
NODE node[LALA];  			// 根据题意 
int p[MAX];  				// 相当于指针数组 
int cou,n,m;  
void init()  
{  
    memset(p,-1,sizeof(p));    
    cou = 2;    			// 初始化为偶数 
}  
void Add(int u,int v,int cap,int cost)  
{  
    node[cou].from = u;  
    node[cou].to = v;  
    node[cou].cap = cap;  
    node[cou].cost = cost;  
    node[cou].next = p[u];  
    p[u] = cou++;  
      
    node[cou].from = v;  
    node[cou].to = u;  
    node[cou].cap = 0;  
    node[cou].cost = -cost;  
    node[cou].next = p[v];  
    p[v] = cou++;  
}  
int MincostMaxflow(int s,int t,int n )  
{  
    queue<int> q;  
    int inq[MAX],pre[MAX],dis[MAX],re[MAX];  
    int u,v,i,a,c = 0,ind,cost,cap;  
    while(1)  
    {  
        memset(inq,0,sizeof(inq));  
        fill(dis,dis+MAX,INT_MAX);
        dis[s] = 0;  
        inq[s] = 1;  
        pre[s] = s;  
        q.push(s);  
        while( !q.empty() )  
        {  
            u = q.front();  
            q.pop();  
            inq[u] = 0;  
            ind = p[u];  
            while( ind != -1 )  
            {  
                u = node[ind].from;  
                v = node[ind].to;  
                cost = node[ind].cost;  
                cap = node[ind].cap;  
                if( cap > 0 && dis[v] > dis[u] + cost )  
                {  
                    dis[v] = dis[u] + cost;  
                    pre[v] = u;  
                    re[v] = ind;  
                    if( !inq[v] )  
                    {  
                        q.push(v);  
                        inq[v] = 1;  
                    }  
                }  
                ind = node[ind].next;     
            }  
        }  
        if( dis[t] == INT_MAX ) break; 
        a = INT_MAX;  
        for(u=t; u!=s; u=pre[u])  
            if( node[re[u]].cap < a )    
                a = node[re[u]].cap;  
        for(u=t; u!=s; u=pre[u])  
        {  
            node[re[u]^1].cap += a;   
            node[re[u]].cap -= a;  
        }  
        c += dis[t]*a;  
    }  
    return c;  
}  

int main()
{
	int n, m, k, pp, from, to, len;
	int S, T;
	
	while( ~scanf("%d%d%d%d", &n, &m, &k, &pp) )
	{
		S = 0;
		T = n + m + 1;
		init();
		for(int i=0; i<n; i++)
		{
			scanf("%d", &to);
			Add(S, to, 1, 0);
		}
		
		while( k-- )
		{
			scanf("%d%d%d", &from, &to, &len);
			Add(from, to, m, len);
			Add(to, from, m, len);
		}
		
		while( pp-- )
		{
			scanf("%d%d%d", &from, &to, &len);
			Add(to, from + m, 1, len);
		}
		
		for(int i=1; i<=n; i++)
			Add(i + m, T, 1, 0);

		int ans = MincostMaxflow(S, T, n + m + 2);
		printf("%d\n", ans);
	}

return 0;
}