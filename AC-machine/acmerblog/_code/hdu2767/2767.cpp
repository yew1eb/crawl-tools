#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <list>
#include <set>
#include <sstream>
#include <istream>
#include <fstream>
#include <climits>
#include <string.h>

#define SIZE 21000
#define SIZE2 30
#define infinity 200000000
#define MOD 10000007
#define BINT 2147483647
#define SINT -2147483648
#define pusb(a) push_back(a)
#define popb() pop_back()
#define mp(a,b) make_pair(a,b)
#define finput freopen("input.txt","r",stdin)
#define foutput freopen("output.txt","w",stdout)
const double Pi = acos(-1);
const double PCSN = 1e-10;

using namespace std;

typedef long long int Bint;
typedef vector<int> Vint;
typedef vector<string> Vstring;
typedef pair<int,int> Prr;
typedef vector<Prr> Vprr;
typedef multiset<int> MSet;
typedef map<Prr,int> PM;
typedef map<Prr,int> ::iterator PMit;
typedef multiset<int>::iterator MSetit;
typedef priority_queue< int, Vint, greater<int> > MinPQ;
typedef priority_queue< int, Vint, less<int> > MaxPQ;

///int BigMod(Bint B,Bint P,Bint M){Bint R=1; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return (int)R;}
///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int cx[]={-1,0,0,1},cy[]={0,-1,1,0};

Vint graph[SIZE];
int color[SIZE],low[SIZE],dis[SIZE],indegree[SIZE],outdegree[SIZE],groupID[SIZE],dfstime,componant;
stack<int> stk;

void input(void);
void SCC(int);
void TarjanSCC(int);
int MakeDAG(int);
void memclr(int);

int main()
{
 input();
 return 0;
}

void input(void)
{
 int ver,edge,i,u,v,test;

 scanf("%d",&test);

 while(test--)
 {
 scanf("%d %d",&ver,&edge);
 {
 for(int i=0; i<edge; i++)
 {
 scanf("%d %d",&u,&v);
 graph[u].pusb(v);
 }

 TarjanSCC(ver);
 printf("%d\n",MakeDAG(ver));
 memclr(ver);
 }
 }
 return ;
}


void TarjanSCC(int ver)
{
 for(int i=1; i<=ver; i++)
 {
 if(!color[i])
 SCC(i);
 }
 return ;
}


void SCC(int u)
{
 int i,v,item;

 color[u]=1;
 low[u]=dis[u]=++dfstime;
 stk.push(u);

 for(int i=0; i<graph[u].size(); i++)
 {
 v = graph[u][i];
 if(color[v]==1) low[u] = min(low[u],dis[v]);
 else if(color[v]==0)
 {
 SCC(v);
 low[u]=min(low[u],low[v]);
 }
 }

 if(low[u]==dis[u])
 {
 do
 {
 item = stk.top();
 stk.pop();
 color[item]=2;
 groupID[item]=componant;
 }
 while(item!=u);

 componant++;
 }

 return ;
}


int MakeDAG(int ver)
{
 int in=0,out=0,u,v;

 if(componant!=1)
 {
 for(int i=1; i<=ver; i++)
 {
 for(int j=0; j<graph[i].size(); j++)
 {
 u = groupID[i];
 v = groupID[graph[i][j]];
 if(u!=v)
 {
 indegree[v]++;
 outdegree[u]++;
 }
 }
 }


 for(int i=0; i<componant; i++)
 {
 if(indegree[i]==0) in++;
 if(outdegree[i]==0) out++;
 }
 }

 return max(in,out);
}


void memclr(int ver)
{
 componant = dfstime=0;

 while(!stk.empty()) stk.pop();

 memset(color,0,sizeof(color));
 memset(low,0,sizeof(low));
 memset(dis,0,sizeof(dis));
 memset(indegree,0,sizeof(indegree));
 memset(outdegree,0,sizeof(outdegree));

 for(int i=0; i<=ver; i++)
 graph[i].clear();

 return ;
}