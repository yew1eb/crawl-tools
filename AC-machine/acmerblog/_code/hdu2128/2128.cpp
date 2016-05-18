#include<iostream>
 #include<cstdio>
 #include<cstring>
 #include<algorithm>
 #include<queue>
 using namespace std;
 struct Node {
     int x,y,time;
     bool operator < (const Node &p) const {
         return p.time<time;
     }
     int key;//炸药
     int count;//所有爆破位置的坐标的映射（有点瞎搞的味道，hd数据弱，应该也会有冲突的吧）
     bool visited[9][9];//记录每个状态爆破的位置，有可能重复走
 } st;
 char map[9][9];
 bool mark[9][9][66][2222];//标记
 int n,m;
 int dir[4][2]= {{-1,0},{1,0},{0,-1},{0,1}};
 int ex,ey;
 
 bool bfs() {
     memset(mark,false,sizeof(mark));
     mark[st.x][st.y][st.key][st.count]=true;
     Node p,q;
     priority_queue<Node>Q;
     Q.push(st);
     while(!Q.empty()) {
         p=Q.top();
         Q.pop();
         if(p.x==ex&&p.y==ey) {
             printf("%d\n",p.time);
             return true;
         }
         for(int i=0; i<4; i++) {
             q=p;
             q.x=p.x+dir[i][0];
             q.y=p.y+dir[i][1];
             q.time=p.time+1;
             if(q.x<1||q.x>n||q.y<1||q.y>m)continue;
             if(map[q.x][q.y]=='.') {
                 if(!mark[q.x][q.y][q.key][q.count]) {
                     mark[q.x][q.y][q.key][q.count]=true;
                     Q.push(q);
                 }
             } else if(map[q.x][q.y]=='X') {
                 if(!q.visited[q.x][q.y]) {
                     if(q.key>0) {
                         q.key--,q.count+=(q.x*q.y+8*(q.x+q.y));
                         q.time++;
                         q.visited[q.x][q.y]=true;
                         if(!mark[q.x][q.y][q.key][q.count]) {
                             mark[q.x][q.y][q.key][q.count]=true;
                             Q.push(q);
                         }
                     }
                 } else if(!mark[q.x][q.y][q.key][q.count]) {
                     mark[q.x][q.y][q.key][q.count]=true;
                     Q.push(q);
                 }
             } else {
                 if(!q.visited[q.x][q.y]) {
                     q.visited[q.x][q.y]=true;
                     q.key+=map[q.x][q.y]-'0';
                 }
                 if(!mark[q.x][q.y][q.key][q.count]) {
                     mark[q.x][q.y][q.key][q.count]=true;
                     Q.push(q);
                 }
             }
         }
     }
     return false;
 }
 
 
 int main() {
  //  freopen("1.txt","r",stdin);
     while(scanf("%d%d",&n,&m),(n+m)) {
         for(int i=1; i<=n; i++) {
             scanf("%s",map[i]+1);
             for(int j=1; j<=m; j++) {
                 if(map[i][j]=='S') {
                     map[i][j]='.';
                     st.x=i;
                     st.y=j;
                     st.time=st.key=st.count=0;
                     memset(st.visited,false,sizeof(st.visited));
                     st.visited[st.x][st.y]=true;
                 } else if(map[i][j]=='D') {
                     map[i][j]='.';
                     ex=i,ey=j;
                 }
             }
         }
         if(!bfs())puts("-1");
     }
     return 0;
 }