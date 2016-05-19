#include<iostream>
#include<queue>
using namespace std;
int dir[8][2]={{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1}};
char map[105][105];
char mark  [105][105];
bool visited [105][105];
struct pos
{
   int x,y,num;
};
int n;
void  bfs(int px,int py)
{
	int tx,ty;
	queue<pos> q;
	pos N,P;
	N.x=px;
	N.y=py;
	N.num=0;
	visited[N.x][N.y]=false;
	q.push(N);
	while(!q.empty())
	{
	   N=q.front();
	   q.pop();
	   for(int i=0;i<8;i++)
	   {
		   
		  tx=N.x+dir[i][0];
		  ty=N.y+dir[i][1];
		  if(tx>=0&&tx<n&&ty>=0&&ty<n)
		  {
          if(map[tx][ty]=='X')
			  N.num++;
		  }
	   }
	    if(N.num==0)
		{
			visited[N.x][N.y]=true;   
			mark[N.x][N.y]='0';
		   for(int i=0;i<8;i++)
		   {	
			
			    tx=N.x+dir[i][0];	
			   ty=N.y+dir[i][1];
			   if(visited[tx][ty]==false&&tx>=0&&tx<n&&ty>=0&&ty<n)
			   {  
				   P.x=tx;
				      P.y=ty;
			     	 P.num=0;
                     q.push(P); 
					 visited[tx][ty]=true;
			   }
		   }
		}
		if(N.num!=0)
		{
			mark[N.x][N.y]=N.num+'0';
		      visited[N.x][N.y]=true;
		}
	}
}
int  main()
{
	int px,py;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>map[i][j];
		  cin>>px>>py;
		   for(int i=0;i<n;i++)
			   for(int j=0;j<n;j++)
			   {
				   mark[i][j]='.';
			      visited[i][j]=false;
			   }
			   if(map[px][py]=='X')
				   cout<<"it is a beiju!"<<endl;
			   else
			   {
				   bfs(px,py);
		            for(int i=0;i<n;i++)
		             {
			         for(int j=0;j<n;j++)
	  			        cout<<mark[i][j];
	                    cout<<endl;   
		                }
			        }  
			   cout<<endl;
	}
	return 0;
}