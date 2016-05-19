#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

#define inf 1<<30;
typedef pair<int,int>PP;


struct Node{
    int x,y;
}node[44];

char str[11][11];
int map[11][11],Index[1111],dist[11][11];
int n,m,maxdeep;
int dir[4][2]={{0,1},{-1,0},{1,0},{0,-1}};

bool In_Edge(int x,int y){
    if(x==1||x==n||y==1||y==n)
    return true;
    return false;
}

//bfsç¨æ¥æ±å°è¾¹ç¼çæç­é¿åº¦ 
int bfs(int x,int y){
    queue<PP>que;
    que.push(make_pair(x,y));
    int dd[11][11];
    memset(dd,-1,sizeof(dd));
    dd[x][y]=0;
    while(!que.empty()){
        x=que.front().first,y=que.front().second;
        que.pop();
        if(In_Edge(x,y))
        return dd[x][y];
        
        for(int i=0;i<4;i++){
            int xx=x+dir[i][0],yy=y+dir[i][1];
            if(map[xx][yy]&&dd[xx][yy]==-1){
                dd[xx][yy]=dd[x][y]+1;
                que.push(make_pair(xx,yy));
            }
        }
    }
    return -1;
}

int Get_H(Node node[]){
    int max_dist=0;
    for(int i=0;i<m;i++){
        max_dist=max(max_dist,dist[node[i].x][node[i].y]);
    }
    return max_dist;
}


bool IDA_star(int deep,Node node[]){
    //A*åªæ 
    if(Get_H(node)+deep>maxdeep)
    return false;
    
    if(deep==maxdeep)
    return true;
    
    Node tmp_node[44];
    for(int i=0;i<4;i++){
        Index[deep]=i;
        
        for(int j=0;j<m;j++){
            int xx=node[j].x+dir[i][0],yy=node[j].y+dir[i][1];
            //å¦æè¿ä¸ªæ¹åä¸è½ç»§ç»­å¾ä¸èµ° 
            if(In_Edge(node[j].x,node[j].y)||map[xx][yy]==0){
                tmp_node[j]=node[j];
            }
            //è¿ä¸ªæ¹åè½ç»§ç»­èµ° 
            else
            tmp_node[j].x=xx,tmp_node[j].y=yy;
        }
        if(IDA_star(deep+1,tmp_node))
        return true;
    }
    return false; 
    
}


int main(){
    int t=0;
    
    while(scanf("%d",&n)!=EOF){
        if(t++){
            puts("");
        }
        
        for(int i=1;i<=n;i++){
            scanf("%s",str[i]+1);
            for(int j=1;j<=n;j++)
            map[i][j]=1-(str[i][j]-'0');
        }
        
        
        m=0;
    
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(map[i][j]){
                    if(In_Edge(i,j))
                    dist[i][j]=0;
                    else{
                        dist[i][j]=bfs(i,j);
                        node[m].x=i,node[m++].y=j;
                    }
                }
                else{
                    dist[i][j]=inf;
                }
                
            }
        }
        
        if(m==0)
        continue;
        for(maxdeep=1;;maxdeep++){
            if(IDA_star(0,node))
            break;
        }
        
        for(int i=0;i<maxdeep;i++){
            if(Index[i]==0)
            puts("east");
            else if(Index[i]==1)
            puts("north");
            else if(Index[i]==2)
            puts("south");
            else if(Index[i]==3)
            puts("west");
        }
    }
    return 0;
}