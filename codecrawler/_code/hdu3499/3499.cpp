#include<iostream>
#include<cstdio>
#include<string>
#include<queue>
#include<map>
#define MAXN 111111
#define MAXM 555555
const __int64 INF=(_I64_MAX)>>1;
//const __int64 INF=4611686018427387903;
using namespace std;

struct node
{
 	   int v;
	   __int64 price;
 	   node* next;
}Edge[MAXM],*ptr[MAXN];

int EdgeNum;
int N,M;//N node,M edge
 	
void addEdge( int u,int v,__int64 price )
{
 	 node *p=&Edge[EdgeNum++];
 	 p->price=price;
 	 p->v=v;
 	 p->next=ptr[u];
 	 ptr[u]=p;
}

__int64 dist[2][MAXN];
bool inS[MAXN];

__int64 spfa( int src,int dst )
{
 	 for( int i=0;i<=N;i++ )
 	 {
 	 	  dist[1][i]=dist[0][i]=INF;
 	 	  inS[i]=false;
	 }
 	 queue<int>myQ;
 	 dist[1][src]=dist[0][src]=0;
 	 
	 int top=0;
	 myQ.push(src);
 	 inS[src]=true;
 	 
 	 while( !myQ.empty() )
 	 {
	  		int cur=myQ.front();
	  		myQ.pop();
	  		node *p=ptr[cur];
	  		while( p )
	  		{
			 	   bool flag=false;
			 	   if( dist[1][p->v]>dist[1][cur]+p->price )
			 	   	   dist[1][p->v]=dist[1][cur]+p->price,flag=true;
			 	   	   
			 	   if( dist[0][p->v]>dist[0][cur]+p->price ||  dist[0][p->v]>dist[1][cur]+p->price/2 )
					   dist[0][p->v]=min( dist[0][cur]+p->price,dist[1][cur]+p->price/2 ),flag=true;
				   
				   if( flag && inS[p->v]==false )
	   	   		   {
	   	   		   	   myQ.push(p->v);
		   	   	   	   inS[p->v]=true;
  	   			   }
			 	   p=p->next;
 	   		}
	  		inS[cur]=false;
	 }
	 return dist[0][dst];
}

string str1,str2;

int main()
{
 	while( scanf( "%d %d",&N,&M )!=EOF )
 	{
	 	   memset( ptr,0,sizeof(ptr) );
	 	   EdgeNum=0;
		   map<string,int>map;
 	 	   int citynum=1;
		   __int64 price;
		   //cout<<INF<<endl;
   	   	   map.clear();
   	   	   
		   for( int i=1;i<=M;i++ )
		   {
		   		cin>>str1>>str2>>price;
		   		if( map.find(str1)==map.end() )
		   			map[str1]=citynum++;
		   		if( map.find(str2)==map.end() )
		   			map[str2]=citynum++;
		   		addEdge( map[str1],map[str2],price );
   		   }
	 	   cin>>str1>>str2;
	 	   //若SE城市中没有可去的边 
	 	   if( map.find(str1)==map.end() || map.find(str2)==map.end() )
	 	   {
	 	   	   printf("-1\n"); continue;
		   }
		   //S==E
		   else if( str1==str2 )
		   {
	 	   	    printf("0\n"); continue;
   		   }
   		   
	 	   __int64 ans=spfa( map[str1],map[str2] );
	 	   
		   if( ans==INF )
           	   printf("-1\n");
		   else
           	   printf("%I64d\n",ans);
  	}
  	return 0;
}
