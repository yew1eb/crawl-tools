#ifdef _MSC_VER
#define DEBUG
#endif

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
//#include <memory.h>
#include <limits.h>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <functional>
#include <ctype.h>
#include <vector>
using namespace std;

#define  MAX 50005              //题目中可能的最大点数       
int STACK[MAX],top;          //Tarjan 算法中的栈 
bool InStack[MAX];             //检查是否在栈中 
int DFN[MAX];                  //深度优先搜索访问次序 
int Low[MAX];                  //能追溯到的在栈中的最早次序
int ComponentNumber;       //有向图强连通分量个数 
int Index;                 //索引号 
vector <int> Edge[MAX];        //邻接表表示 
int InComponent[MAX];			//记录每个点在第几号强连通分量里
void Tarjan(int i) 
{ 
  int j; 
  DFN[i]=Low[i]=Index++; 
  InStack[i]=true; 
  STACK[++top]=i; 
  for (size_t e=0;e<Edge[i].size();e++) 
  { 
    j=Edge[i][e]; 
    if (DFN[j]==-1) 
    { 
      Tarjan(j); 
      Low[i]=min(Low[i],Low[j]); 
    } 
    else if (InStack[j]) //如果指向的节点j仍在栈中，由于j先于i入栈，则j有到i的通路，同时由于i指向j，则i与j构成回路
      Low[i]=min(Low[i],DFN[j]); 	//如果指向的节点扔在栈中，则指向的节点仍未编入强连通分量
    //如果前面两个判断条件都是错误的话，则i和j不在同一个连通分量中
  } 
  if (DFN[i]==Low[i]) //连通分量中最早进栈的点
  { 
    ComponentNumber++; 
    do 
    { 
      j=STACK[top--]; 
      InStack[j]=false; 
//       Component[ComponentNumber].push_back(j);
      InComponent[j]=ComponentNumber;	//给每一个连通分量上的节点染色
    } 
    while (j!=i); 
  } 
}

void solve(int N)     //N是此图中点的个数，注意是0-indexed！ 
{ 
  memset(STACK,-1,sizeof(STACK)); 
  memset(InStack,0,sizeof(InStack)); 
  memset(DFN,-1,sizeof(DFN)); 
  memset(Low,-1,sizeof(Low)); 
  top=0;Index=0;ComponentNumber=0;

  for(int i=1;i<=N;i++) 
    if(DFN[i]==-1) 
      Tarjan(i);    
}

vector<int> v_component_edge[MAX];
int used[MAX];
int mat[MAX];
bool find(const int &x)
{
  size_t i;
  for(i=0;i<v_component_edge[x].size();++i)
  {
    int v=v_component_edge[x][i];
    if(!used[v])
    {
      used[v]=1;
      if(mat[v]==-1 || find(mat[v]))
      {
        mat[v]=x;
        return true;
      }
    }
  }
  return false;
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int ncases,n,m,u,v;
  scanf("%d",&ncases);

  while(ncases--)
  {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
    {
      Edge[i].clear();
      v_component_edge[i].clear();
    }
    while(m--)
    {
      scanf("%d%d",&u,&v);
      Edge[u].push_back(v);
    }

    solve(n);

    for(int i=1;i<=n;++i)
      for(size_t j=0;j<Edge[i].size();++j)
        if(InComponent[i]!=InComponent[Edge[i][j]])
          v_component_edge[InComponent[i]].push_back(InComponent[Edge[i][j]]);

    int ans=0;
    memset(mat,-1,sizeof(mat));
    for (int i=1;i<=ComponentNumber;++i)
    {
      memset(used,0,sizeof(used));
      if(find(i)) ++ans;
    }

    printf("%d\n",ComponentNumber-ans);

  }

  return 0;
}
