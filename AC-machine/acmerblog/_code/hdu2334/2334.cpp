#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
using namespace std;
const int SIZE = 220;
const int INF = 100000000;
const int MAX_LEV=10000000;
const double EQ = 1e-9;
const int LEN = 100000;
bool used[SIZE];
int lev[SIZE];
int cap[SIZE][SIZE];
int old[SIZE][SIZE];
int que[LEN];
double lim;
class Pos{
public:
double x,y;
int pen ,jmp;
int in,out;
void set(){
   scanf("%lf%lf%d%d",&x,&y,&pen,&jmp);
   in=out=0;
}
bool near(const Pos & oth){
   double dis = sqrt((x-oth.x)*(x-oth.x) + (y-oth.y)*(y-oth.y));
   return (fabs(dis-lim)<EQ || dis<lim);
}
};
Pos dat[SIZE];
vector<int> li[SIZE];
int n;
int sz;
int tot;
int src,dest;
void init();
vector<int> ans;
void work();
int maxflow();
void cp(int [][SIZE] , int [][SIZE]);
void mklev();
int dfs(int,int);
void show();
int main(){
int cas;
scanf("%d",&cas);
while (cas--){
   init();
   work();
}
return 0;
}
void work(){
int i;
ans.clear();
cp(old,cap);
for (i=0;i<sz;i++){
   cp(cap,old);
   dest=dat[i].in;
   if (maxflow()==tot){
    //printf("arr in dat : %d\n",i);
    ans.push_back(i);
   }
}
int len=ans.size();
if (len){
   printf("%d",ans[0]);
   for (i=1;i<len;i++){
    printf(" %d",ans[i]);
   }
   printf("\n");
}else{
   printf("-1\n");
}
}
void init(){
scanf("%d%lf",&sz,&lim);
int i;
for (i=0;i<sz;i++){
   dat[i].set();
}
for (i=0;i<sz;i++){
   li[i].clear();
}
int j;
for (i=0;i<sz;i++) 
   for (j=0;j<sz;j++){
    if (i!=j && dat[i].near(dat[j])){
     li[i].push_back(j);
    }
   }
src=0;
n=1;
tot=0;
for (i=0;i<sz;i++){
   dat[i].in=n++;
   dat[i].out=n++;
}
memset(cap,0,sizeof(cap));
for (i=0;i<sz;i++){
   cap[src][dat[i].in]=dat[i].pen;
   tot+=dat[i].pen;
   cap[dat[i].in][dat[i].out]=dat[i].jmp;
}
for (i=0;i<sz;i++){
   int len = li[i].size();
   for (j=0;j<len;j++){
    int nx = li[i][j];
    cap[dat[i].out][dat[nx].in]=INF;
   }
}
}
void cp(int a[][SIZE] , int b[][SIZE]){ //a<---b;
int i,j;
for (i=0;i<SIZE;i++)
   for (j=0;j<SIZE;j++){
    a[i][j] = b[i][j];
   }
}
int maxflow(){
int sum=0;
while (true){
   mklev();
   if (lev[dest]==MAX_LEV)
    return sum;
   memset(used,false,sizeof(used));
   used[src]=true;
   sum+=dfs(src,INF);
}
}
void mklev(){
int i;
for (i=0;i<n;i++){
   lev[i]=MAX_LEV;
}
lev[src]=0;
int head=0,tail=1;
que[0]=src;
while (head!=tail){
    int nd = que[head];
    head=(head+1)%LEN;
    if (nd==dest){
    break;
    }
    for (i=0;i<n;i++){
    if (cap[nd][i]>0 && lev[i]>(lev[nd]+1)){
    lev[i]=(lev[nd]+1);
    que[tail]=i;
    tail=(tail+1)%LEN;
    }
    }
}
}
int dfs(int nd,int flow){
if (nd==dest){
    return flow;
}
int i;
for (i=0;i<n;i++){
    if (cap[nd][i]>0 && !used[i]&& lev[nd]+1==lev[i]){
   used[i]=true;
   int nf = flow<cap[nd][i]?flow:cap[nd][i];
   int ret = dfs(i,nf);
   if (ret>0){
   used[i]=false;
   cap[nd][i]-=ret;
   cap[i][nd]+=ret;
   return ret;
   }
    }
}
return 0;
}