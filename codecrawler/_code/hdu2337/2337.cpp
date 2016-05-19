#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
int t;
int n;// the number of the enemys
int xmax,ymax;//边界
int stx,sty,endx,endy;//开始和终止的坐标
const  int  dx[4]={-1,1,0,0};
const  int  dy[4]={0,0,-1,1};
bool check(int x,int y){ //检查 是否越界
  if(x<1||x>xmax||y<1||y>ymax)
	  return false;
  return true;
}
struct Node{
   int x;
   int y;
   int len;
};// node  在 预处理 距离 和求路的长度是用到，两者len 的意义不一样  ， 一个表示据敌人的距离，一个表示据起点的距离  由于结构相同就 使用相同的struct
Node node[1000100];//自己手写的队列 用到
struct queue2{  //自己手写的队列
  int head;
  int tail;
  void init(){
    head=0;
    tail = 0;
  }
  Node front(){
      return node[head];
  }
  void pop(){
      head++;
  }
  void push(Node a){
      node[tail]=a;
      tail++;
  }
  bool empty(){
    if(tail==head)
	 return true;
    return false;
  }
}q={0,0};

bool vis[1010][1010];  // 记录是否搜过
int length[1010][1010]; // 记录据敌人的距离

void init(){  
   for(int i=1;i<=xmax;i++){
     for(int j=1;j<=ymax;j++){     
         vis[i][j]=false;
	 length[i][j]=-1;
     }
   }
}

void init_length(){  //  预处理 length距离数组 
    while(!q.empty()){
       Node a = q.front();
       q.pop();
       int x = a.x;
       int y = a.y;
      for(int i=0;i<=3;i++){ // 向四个方向搜索
          int x2 = x +dx[i];
	  int y2 = y +dy[i];
          if(length[x2][y2]==-1){  // -1 表示没搜过
	     length[x2][y2]=a.len+1;
             Node b = {x2,y2,a.len+1};
	     q.push(b);
	  }
      }
    }
}


void init_vis(){
   for(int  i=1;i<=xmax;i++){
     for(int  j=1;j<=ymax;j++){
        vis[i][j]=false;
     }
   }
}
int cal_dis(int len){ //给定一个 距离敌人的最小距离，判断这个距离能不能到达终点  不能返回 -1 能的话返回长度
    if(length[stx][sty]<len||length[endx][endy]<len)
	    return -1;
    init_vis();
    q.init();//队列初始化
    if(stx==endx&&sty==endy){
      return 0;
    }
    Node a = {stx,sty,0};
    vis[stx][sty]=true;
    q.push(a);
    while(!q.empty()){
        Node top = q.front();
        q.pop();
        for(int i=0;i<=3;i++){
	   int x = top.x+dx[i];
	   int y = top.y+dy[i];
	   if(x==endx&&y==endy){
	         return   top.len+1;
	   }
	   if(check(x,y)&&!vis[x][y]){
	       vis[x][y]=true;
	       if(length[x][y]>=len){
		  Node tmp ={x,y,top.len+1};
	          q.push(tmp);
	       }
	   }
	}
        
    }
    return -1;
}
void  output (){
    int left =1;
    int right =xmax+ymax;
    int mid ;
    int distance;    
    while(left<=right){  // 二分
	  mid =(left +right)>>1;
          distance = cal_dis(mid);
	  
	  if(distance ==-1){
	     right=mid-1; 
	  }else{
	     left =mid+1;
	  }
    }
    cout <<right << " "<<cal_dis(right)<<endl;
    
}
int main(){
   scanf("%d",&t);   
   while(t--){
       scanf("%d%d%d",&n,&xmax,&ymax);
        q.init();
	init();
	scanf("%d%d%d%d",&stx,&sty,&endx,&endy);
	stx++; sty++; endx++;  endy++;  // 自己的是 1 到x  而给定的 0 到x-1，所以要++ 
        for(int i=1;i<=n;i++){
            int x,y ;
	    scanf("%d%d",&x,&y);
	    length[x+1][y+1]=0;
	    vis[x+1][y+1]=true;
	    Node a ={x+1,y+1,0};
	    q.push(a);
       }
       init_length();
       output(); 
   }
}