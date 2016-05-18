 #include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <algorithm>
 #include <vector>
 
 #define KT ch[ch[root][1]][0]
 #define LC ch[x][0]
 #define RC ch[x][1]
 #define N 61001
 #define M 61000
 #define Q 500000
 using namespace std;
 
 
 int fa[N];
 int ch[N][2];
 int sz[N];
 int top1;
 int top2;
 int ss[N];
 int que[N];
 int nodque[N],top3;
 int val[N];
 int nodbelong[N];
 int ini[N];
 const int inf=1e9;
 vector<int> g[N];
 struct SplayTree{
     int root;
     void rotate(int x,bool f){
         int y=fa[x];
         int z=fa[y];
         pushdown(y);
         pushdown(x);
         ch[y][!f]=ch[x][f];
         fa[ch[x][f]]=y;
         fa[x]=z;
         if (z) {
             ch[z][ch[z][1]==y] = x;
         }
         ch[x][f] = y;
         fa[y]=x;
         pushup(y);
     }
     void splay(int x, int g) {
         int y = fa[x];
         pushdown(x);
         while(y!=g){
             int z= fa[y];
             bool f = (ch[y][0]==x);
             if(z != g && f == (ch[z][0]==y)){
                 rotate(y,f);
             }
             rotate(x,f);
             y=fa[x];
         }
         pushup(x);
         if(g==0) root = x;
     }
     void rotateTo(int k,int g) {
         int x=root;
         pushdown(x);
         while(sz[LC] != k){
             if(k<sz[LC]){
                 x=LC;
             }else{
                 k -= sz[LC] + 1;
                 x = RC;
             }
             pushdown(x);
         }
         splay(x,g);
     }
     void build(int l,int r,int f){
         if(l>r){
             return ;
         }
         int x = (l + r) >> 1;
         LC = (x - 1 >= l)? (x - 1 + l)>> 1 :0;
         RC = (r >= x + 1)? (x + 1 + r)>> 1 :0;
         fa[x] = f;
         build(l,x - 1,x);
         build(x + 1,r,x);
         pushup(x);
     }
     void erase(int x){
         if(x==0)
             return;
         int father= fa[x];
         int head = 0, tail=0;
         for(que[tail++] =x ; head < tail; head++){
             ss[top2++] = que[head];
             if(ch[que[head]][0]){
                 que[tail++]=ch[que[head]][0];
             }
             if(ch[que[head]][1]){
                 que[tail++] = ch[que[head]][1];
             }
         }
         ch[father][ch[father][1]==x]=0;
         pushup(father);
     }
     void makeTree(int &x, int l, int r, int f ,vector<int>& g){
         if(l > r){
             return;
         }
         int m=(l+r)>>1;
         newNode(x, ini[g[m]],g[m]);
         makeTree(LC,l,m-1,x,g);
         makeTree(RC,m+1,r,x,g);
         fa[x]=f;
         pushup(x);
     }
     void treaval(int x){
         if (x) {
             pushdown(x);
             treaval(LC);
             printf("@%d",val[x]);
 
             //ans[cnt++]=val[x];
             treaval(RC);
         }
     }
     void dfs(int x){
         if (x) {
             pushdown(x);
             dfs(LC);
             nodque[top3++]=x;
             dfs(RC);
         }
     }
     void newNode(int &x,int c,int id){
         if(id){
             x=id;//直接另节点号一致
         }
         else if(top2){
             x = ss[--top2];
         } else {
             x = ++top1;//top1从n+1，开始
         }
         LC = 0;
         RC = 0;
         fa[x] =0;
         sz[x] = 1;
 
         val[x]=c;
     }
     void pushdown(int x){
 
     }
     void pushup(int x){
         sz[x]=1+sz[LC]+sz[RC];
     }
 
     void debug(){
         treaval(root);
         cout<<endl;
     }
     void cutTo(int l,int r,int c){
         rotateTo(l-1,0);
         rotateTo(r+1,root);
         int tmp=KT;
         KT=0;
         pushup(ch[root][1]);
         pushup(root);
 
         rotateTo(c,0);
         rotateTo(c+1,root);
         fa[tmp]=ch[root][1];
         KT=tmp;
         pushup(ch[root][1]);
         pushup(root);
     }
 
     void init(vector<int>&g){
 
         root=0;
         int n=g.size();
         newNode(root,inf,0);
         newNode(ch[root][1],-inf,0);
         fa[ch[root][1]]=root;
         //for(int i=1;i<=n;i++)scanf("%d",&num[i]);
         makeTree(KT,0,n-1,ch[root][1],g);
         pushup(ch[root][1]);
         pushup(root);
     }
     int size(){
         return sz[root]-2;
     }
     int find(int x,int v,int cur){
         if(val[x]>=v){
             cur=x;
             return RC?find(RC,v,cur):cur;
         }else{
             return LC?find(LC,v,cur):cur;
         }
 //        if(val[LC]<v){
 //            return find(LC,v);
 //        }else if(val[RC]>v){
 //            return find(RC,v);
 //        }else
 //            return val[x]<v?LC:RC;
     }
     void insert(int y){//将y节点插入splay
         int x=find(root,val[y],root);
         splay(x,0);
         int s=sz[LC]+1;
         rotateTo(s,root);
         fa[y]=ch[root][1];
         ch[y][0]=0;
         ch[y][1]=0;
         KT=y;
         sz[y]=1;
         pushup(ch[root][1]);
         pushup(root);
     }
     void merge(SplayTree spt){
         top3=0;
         spt.dfs(spt.root);
         rotateTo(1,0);
         int tmp=nodbelong[root];
         for(int i=1;i<top3-1;i++){
             insert(nodque[i]);
             nodbelong[nodque[i]]=tmp;
         }
     }
     void change(int x,int k){
         splay(x,0);
         int s=sz[LC];
         rotateTo(s-1,0);
         rotateTo(s+1,root);
 
         KT=0;
         pushup(ch[root][1]);
         pushup(root);
 
         val[x]=k;
         insert(x);
     }
     int query(int k){
         if(k>size()||k<=0)return 0;
         rotateTo(k,0);
         return val[root];
     }
 
 }spt[N];
 
 struct edge{
     int flag;
     int to;
     int next;
 }e[M<<1];
 int head[N],num;
 void _add(int u,int v){
     e[num].flag=0;
     e[num].to=v;
     e[num].next=head[u];
     head[u]=num++;
 }
 void add(int u,int v){
     _add(u,v);
     _add(v,u);
 }
 struct Ques{
     char op;
     int x,k;
     void set(char o,int xx,int kk){
         op=o;
         x=xx;
         k=kk;
     }
 }questa[Q];
 int top4;
 int vis[N];
 
 void dfs(int x,int id){
     vis[x]=1;
     nodbelong[x]=id;
     for(int i=head[x];i!=-1;i=e[i].next)if(!e[i].flag&&!vis[e[i].to]){
         dfs(e[i].to,id);
     }
 }
 int cmp(int i,int j){
     return ini[i]>ini[j];
 }
 void init(int n,int m){
     memset(head,-1,sizeof(int)*(n+1));
     num=top4=0;
     top1=n;top2=0;
     memset(vis,0,sizeof(int)*(n+1));
 }
 void solve( int n,int m){
 
     int u,v;
     int x,k;
     char op[10];
 
     init(n,m);
     for(int i=1;i<=n;i++){
         scanf("%d",&ini[i]);
     }
     for(int i=0;i<m;i++){
         scanf("%d%d",&u,&v);
         add(u,v);
     }
     top4=0;
     while(scanf("%s",op),op[0]!='E'){
         if(op[0]=='D'){
             scanf("%d",&x);
             int id=(x-1)*2;
             questa[top4++].set(op[0],e[id].to,e[id^1].to);
             e[id].flag=1;
             e[id^1].flag=1;
         }else if(op[0]=='Q'){
             scanf("%d%d",&x,&k);
             questa[top4++].set(op[0],x,k);
         }else{
             scanf("%d%d",&x,&k);
             questa[top4++].set(op[0],x,ini[x]);
             ini[x]=k;
         }
     }
     int cnt=0;
     for(int i=1;i<=n;i++)if(!vis[i]){
         dfs(i,cnt++);
     }
     for(int i=1;i<=n;i++){
         g[nodbelong[i]].push_back(i);
     }
     for(int i=0;i<cnt;i++){
         sort(g[i].begin(),g[i].end(),cmp);
 //        for(int j=g[i].size()-1;j>=0;j--){
 //            cout<<g[i][j]<<" ";
 //        }
 //        cout<<endl;
     }
     for(int i=0;i<cnt;i++){
         spt[i].init(g[i]);
     }
 //    for(int i=0;i<cnt;i++)
 //        cout<<spt[i].size()<<endl;
     double ans=0;
     int ret=0;
     while(top4--){
         char op=questa[top4].op;
         x=questa[top4].x;k=questa[top4].k;
         if(op=='D'){
             int id1=nodbelong[x];
             int id2=nodbelong[k];
             int sz1=spt[id1].size();
             int sz2=spt[id2].size();
             if(id1==id2)continue;
             if(sz1>sz2){
                 spt[id1].merge(spt[id2]);
             }else{
                 spt[id2].merge(spt[id1]);
             }
         }else if(op=='C'){
             int id=nodbelong[x];
 
             spt[id].change(x,k);
         }else{
             int id=nodbelong[x];
             //spt[id].debug();
             //int t=spt[id].query(k);
             ans+=spt[id].query(k);
             //cout<<t<<endl;
             ret++;
         }
     }
     printf("%.6lf\n",(double)ans/ret);
     for(int i=0;i<cnt;i++)g[i].clear();
 }
 int main()
 {
     int n,m;
 
     int cas=1;
     while(scanf("%d%d",&n,&m),n||m){
         printf("Case %d: ",cas++);
         solve(n,m);
     }
     return 0;
 }
