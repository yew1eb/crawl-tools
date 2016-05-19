/*
	Orz : http://www.cnblogs.com/lee41sum/archive/2010/05/01/1725769.html
这图如果是不连通的，SPFA是会出问题的，所以可以增加一个V0的虚拟节点。
注意，题目中是>和<，要转换成>=和《=才能应用差分约束，由于是整数，是很好转换的。
得到差分约束方程：s[si+ni]-s[si-1]>=cost+1
                s[si+ni]-s[si-1]<=cost-1  
在做SPFA时，如果存在负环则return false，表明不能满足所有的约束方程，如果不出现负权环
则可以找到这样的序列。


*/

#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

const int N = 1005;
const int INF = 0x7f7f7f7f;
int dis[N];
bool hash[N];
int visit[N];
bool hh[N];
struct node
{
	int x;
	int dis;
	struct node *next;
	node () 
	{
		next = NULL;
	}
};
node *map[N], vex[N];

inline void Init()
{
	//map = new node[N];
	for(int i = 0; i < N; i++)
	{
		//map[i] = &vex[i];
		map[i] = new node;
		//map[i]->next = NULL;
	}
}

inline void creat(int x, int y, int dis)
{
	node *p;
	p = new node;
	p->x = y;
	p->dis = dis;
	p->next = map[x]->next;
	map[x]->next = p;
}
struct In
{
	int x;
	int dis;
};
bool SPAF(int st, int v)
{
	queue<In> Q;
	memset(dis, 0x7f, sizeof(dis));
	memset(hash, false ,sizeof(hash));
	memset(visit, 0, sizeof(visit));
	In P, M; //prev, next
	M.x = st;
	M.dis = 0;
	hash[st] = true;//标记进入队列的点为true
	dis[st] = 0;
	visit[st]++;
	Q.push(M);
	while(!Q.empty())
	{
		P = Q.front();
		Q.pop();
		hash[P.x] = false;//表示改点不在对列中
		//map[P.x] = &vex[P.x];
		node *r;
		r = map[P.x]->next;
		for(; r != NULL; r = r->next)
		{
			if( dis[P.x] + r->dis < dis[r->x] )
			{
				dis[r->x] = dis[P.x] + r->dis;
				M.dis = dis[r->x];
				M.x = r->x;
				if(!hash[r->x])//不在队列中的点当松弛过了就标记true
				{
					hash[r->x] = true;
					visit[r->x]++;
					if(visit[r->x] > v)
					return false;
					Q.push(M);
				}
			}
		}
		if(dis[st] < 0)
		return false;
	}
return true;




}

struct Node
{
	int x;
	int dis;
	friend bool operator < (Node a, Node b)
	{
		return a.dis > b.dis;
	}
};
/*
void BFS(int st, int n)
{
	priority_queue<Node> Q;
	Node P, M;
	memset(hash, false, sizeof(hash));
	memset(dis, 0x7f, sizeof(dis));
	map[st] = &vex[st];
	node *p;
	p = map[st]->next;
	for(; p != NULL; p = p->next)
	{
		M.dis = p->dis;
		M.x = p->x;
		dis[p->x] = p->dis;
		Q.push(M);
	}
	hash[st] = true;
	while(!Q.empty())
	{
		P = Q.top();
		Q.pop();
		hash[P.x] = true;
		map[P.x] = &vex[P.x];
		p = map[P.x]->next;
		for(; p != NULL; p = p->next)
		{
			if(!hash[p->x] && P.dis + p->dis < dis[p->x])
			{
				dis[p->x] = P.dis + p->dis;
				M.dis = dis[p->x];
				M.x = p->x;
				Q.push(M);
			}
		}
	}

}
*/
int main()
{
    int n, m;
    while(scanf("%d", &n) != EOF && n)
    {
        scanf("%d", &m);
        int  si, ni, ki;
        char oi[20];
        int v = 0;
        Init();
        memset(hh, false, sizeof(hh));
        while(m--)
        {
            scanf("%d %d %s %d", &si, &ni, oi, &ki);
            if(oi[0] == 'g')
            {
            	/*
                Evde[v].st = si + ni;
                Evde[v].en = si - 1 ;
                Evde[v].dis = -ki - 1;
                v++;
                */
                //if()
               hh[si + ni] = true;
               hh[si - 1] = true;
                creat(si + ni + 1, si, -ki - 1); 
            }
            else
            {
            	/*
                Evde[v].st = si - 1;
                Evde[v].en = ni + si;
                Evde[v].dis = ki - 1;
                */
                 hh[si + ni] = true;
              	 hh[si - 1] = true;
                creat(si , si + ni + 1, ki - 1);
            }
            
        }
        for(int i =  1 ; i <= n; i++)
        creat(0, i, 0);
        
    
        if(SPAF(0, n + 1))
            printf("lamentable kingdom/n");
        else
            printf("successful conspiracy/n");
    }
}