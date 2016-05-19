#include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <algorithm>
 #define INF 0x7fffffff
 #define maxn 20010
 #define maxm 500000
 using namespace std;
 int v[maxm],next[maxm],w[maxm];
 int first[maxn],d[maxn],work[maxn],q[maxn];
 int e,S,T;
 int map[105][105];
 struct Row{
     int x,y,z;
 }row[maxn];
 struct Col{
     int x,y,z;
 }col[maxn];
 
 void init(){
     e = 0;
     memset(first,-1,sizeof(first));
 }
 
 void add_edge(int a,int b,int c){
     //printf("add:%d to %d,cap = %d\n",a,b,c);
     v[e] = b;w[e] = c;next[e] = first[a];first[a] = e++;
     v[e] = a;w[e] = 0;next[e] = first[b];first[b] = e++;
 }
 
 int bfs(){
     int rear = 0;
     memset(d,-1,sizeof(d));
     d[S] = 0;q[rear++] = S;
     for(int i = 0;i < rear;i++){
         for(int j = first[q[i]];j != -1;j = next[j])
             if(w[j] && d[v[j]] == -1){
                 d[v[j]] = d[q[i]] + 1;
                 q[rear++] = v[j];
                 if(v[j] == T)   return 1;
             }
     }
     return 0;
 }
 
 int dfs(int cur,int a){
     if(cur == T)    return a;
     for(int &i = work[cur];i != -1;i = next[i]){
         if(w[i] && d[v[i]] == d[cur] + 1)
             if(int t = dfs(v[i],min(a,w[i]))){
                 w[i] -= t;w[i^1] += t;
                 return t;
             }
     }
     return 0;
 }
 
 int dinic(){
     int ans = 0;
     while(bfs()){
         memcpy(work,first,sizeof(first));
         while(int t = dfs(S,INF))   ans += t;
     }
     return ans;
 }
 
 int cal(int id,int row_cnt){
     int cnt = 0,pos = id+row_cnt;
     for(int i = first[pos];i != -1;i = next[i])
         if(v[i] <= row_cnt) cnt += w[i];
     return cnt+1;
 }
 
 int main()
 {
     int n,m;
     char str[10];
     while(scanf("%d%d",&n,&m) == 2){
         init();
         int row_cnt,col_cnt,id;
         row_cnt = col_cnt = id = 0;
         for(int i = 1;i <= n;i++){
             for(int j = 1;j <= m;j++){
                 scanf("%s",str);
                 if(str[0] == '.'){
                     map[i][j] = ++id;
                 }else{
                     map[i][j] = -1;
                     if(str[0] != 'X'){
                         int tmp = (str[0]-'0')*100 + (str[1]-'0')*10 + str[2]-'0';
                         col[++col_cnt].x = i;
                         col[col_cnt].y = j;
                         col[col_cnt].z = tmp;
                     }
                     if(str[4] != 'X'){
                         int tmp = (str[4]-'0')*100 + (str[5]-'0')*10 + str[6]-'0';
                         row[++row_cnt].x = i;
                         row[row_cnt].y = j;
                         row[row_cnt].z = tmp;
                     }
                 }
             }
         }
         S = 0,T = row_cnt+id+col_cnt+1;
         for(int i = 1;i <= row_cnt;i++){
             int x = row[i].x;
             int y = row[i].y;
             int cnt_len = 0;
             for(y = y+1;y <= m;y++){
                 if(map[x][y] != -1){
                     cnt_len++;
                     add_edge(i,row_cnt+map[x][y],8);
                 }
                 else   break;
             }
             add_edge(S,i,row[i].z-cnt_len);
         }
         for(int i = 1;i <= col_cnt;i++){
             int x = col[i].x;
             int y = col[i].y;
             int cnt_len = 0;
             for(x = x+1;x <= n;x++){
                 if(map[x][y] != -1){
                     cnt_len++;
                     add_edge(row_cnt+map[x][y],row_cnt+id+i,8);
                 }
                 else    break;
             }
             add_edge(row_cnt+id+i,T,col[i].z-cnt_len);
         }
         dinic();
         for(int i = 1;i <= n;i++){
             for(int j = 1;j <= m;j++){
                 if(map[i][j] == -1) printf("_ ");
                 else    printf("%d ",cal(map[i][j],row_cnt));
             }
             printf("\n");
         }
     }
     return 0;
 }