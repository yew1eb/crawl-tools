/* **********************************************
Author      : wuyiqi
Created Time: 2013-8-13 11:34:59
File Name   : Cube number on a tree.cpp
*********************************************** */
#include<cstdio>  
#include<cstring>  
#include<vector>  
#include<map>
#include<algorithm>  
using namespace std;  
typedef __int64 lld;
const int maxn = 50010;  
lld val[maxn];
int in[maxn][33];
int pri[33];
int K;
int n;
int head[maxn];
int nxt[maxn*2];
int pnt[maxn*2];
int E ;
void add(int a,int b){
    pnt[E] = b;
    nxt[E] = head[a];
    head[a] = E++;
}
const int H = 100007;
struct Hash_table{
    int head[H];
    int nxt[maxn*2];
    int cnt[maxn*2];
    int biao[maxn*2][33];
    int E;
    void init() {
        E = 0;
        memset(head,-1,sizeof(head));
    }
    int find(lld num,int x[],bool flag) {
        int h = num % H;
        for(int i = head[h]; i != -1; i = nxt[i]) {
                bool f = true;
                for(int j = 0; j < K; j++) {
                        if(biao[i][j] != x[j]) {
                            f = false;
                            break;
                        }
                }
                if(f){
                     int ans = cnt[i];
                     if(flag) cnt[i] ++;
                     return ans;
                } 
         }
        if(flag) {
            cnt[E] = 1;
            for(int i = 0; i < K; i++) biao[E][i] = x[i];
            nxt[E] = head[h];
            head[h] = E++;
        }
        return 0;
    }
}ta;
struct fenzhi {
    bool Del[maxn];
    int size[maxn];
    int opt[maxn];
    int tnode[maxn] , tns;
    int all[maxn][33],as;
    int ID[maxn];
    void Dfs(int u,int f) {
        tnode[tns++] = u;
        size[u] = 1;
        opt[u] = 0;
        for(int i = head[u]; i != -1; i = nxt[i]) {
            int v = pnt[i];
            if(!Del[v] && v != f) {
                Dfs(v,u);
                size[u] += size[v];
                opt[u] = max(opt[u],size[v]);
            }
        }
    }
    int Get_Root(int u){
        tns = 0;
        Dfs(u,-1);
        int mi = maxn , ans = -1;
        for(int i = 0; i < tns; i++) {
            opt[tnode[i]] = max(opt[tnode[i]],size[u]-size[tnode[i]]);
            if(opt[tnode[i]] < mi) {
                mi = opt[tnode[i]];
                ans = tnode[i];
            }
        }
        return ans;
    }
    void Get_Dis(int u,int fa){
      //  printf("u=%d\n",u);
        int fid ;
        if(fa != -1) {
            fid = ID[fa];
            for(int i = 0; i < K; i++) {
                all[as][i] = all[fid][i] + in[u][i];
//                all[as][i] %= 3;
                if(all[as][i] >= 3) all[as][i] -= 3;
            }
        } else {
            for(int i = 0; i < K; i++) {
                all[as][i] = in[u][i] ;
            }
        }
        ID[u] = as;
        as++;
        for(int i = head[u]; i != -1; i = nxt[i]) {
            int v = pnt[i];
            if(!Del[v] && v != fa) {
                Get_Dis(v,u);
            }
        }
    }
    void Solve(int u) { 
        //printf("u=%d\n",u);
        u = Get_Root(u);
      //  printf("u=%d\n",u);
        Ans += Calc(u,u,false);
     //  printf("Ans=%d\n",Ans);
     //   puts("ddd");
        Del[u] = true;
        for(int i = head[u]; i != -1; i = nxt[i]) {
            int v = pnt[i];
            if(!Del[v]) {
                int tmp = Ans;
             //   printf("v=%d\n",v);
                Ans -= Calc(v,u,true);
             //   printf("tmp=%d Ans=%d\n",tmp,Ans);
            }
        }
      //  printf("u=%d aaaa Ans=%d\n",u,Ans);
        for(int i = head[u]; i != -1; i = nxt[i]) {
            int v = pnt[i];
            if(!Del[v]) {
                Solve(v);
            }
        }

    }
    lld Calc(int u,int root,bool yes){
        as = 0;
        Get_Dis(u,-1);
      /*  for(int i = 0; i < as;i++) {
            for(int j = 0; j < K; j++) {
             //   printf("all[%d][%d]=%d\n",i,j,all[i][j]);
            }
        }*/
        if(yes) {
           // printf("u=%d root=%d\n",u,root);
            for(int i = 0; i < as; i++) {
                for(int j = 0; j < K; j++) {
                    all[i][j] += in[root][j];
                    if(all[i][j] >= 3) all[i][j] -= 3;
                }
            }
           /* for(int i = 0; i < as; i++) {
                for(int j = 0; j < K; j++) {

                    printf("all[%d][%d]=%d\n",i,j,all[i][j]);
                }
            }*/
        }
      //  printf("as=%d\n",as);
        lld ans = 0;
      //  ta.init();
       map<lld,int> tt;
        int start = (u == root) ? 1 : 0;
        for(int i = start; i < as; i++) {
            int x[33];
            lld sum = 0 , g = 0;
            bool f = true;
            
            for(int j = 0; j < K; j++) {
                if(all[i][j] == 0) x[j] = 0;
                if(all[i][j] == 1) x[j] = 2;
                if(all[i][j] == 2) x[j] = 1;
                g<<=2;
                g |= x[j];
                int tmp = all[i][j] - in[root][j];
                if(tmp < 0) tmp += 3 ;
                sum<<=2;
                sum |= tmp;
//                sum = sum * 10 + tmp;

                if(all[i][j] != 0) f = false;
            }
          // puts("x:::");
         //   for(int j = 0; j < K; j++) printf("%d ",x[j]);puts("");
         //   puts("y:::");
       //     for(int j = 0; j < K; j++) printf("%d ",y[j]);puts("");
            if(f && !yes) {
                ans++;
           //      puts("fffff");
            //    puts("ddd");
            }//printf("g=%d sum=%d\n",g,sum);
            ans += tt[g];
         //   printf("ans=%d\n",ans);
            tt[sum]++;
        }
      return ans;
  }
    lld gao() {
        Ans = 0;
        fill(Del,Del+n+1,false);
        Solve(1);
        return Ans;
    }
    lld Ans;
}nice;
int extr ;
void split(int node,lld num) {
    if(num == 0) return ;
    bool  f = true;
    for(int i = 0; i < K; i++) {
        in[node][i] = 0;
        if(num % pri[i] == 0) {
            while(num % pri[i] ==0) {
                num /= pri[i];
                in[node][i]++;
            }
        }
        in[node][i] %= 3;
        if(in[node][i] != 0) f =false; 
    }
    if(f) extr ++;
   // for(int i = 0; i < K; i++) printf("in[%d][%d]=%d\n",node,i,in[node][i]);
}
int get_val()
{     
    int ret(0);     
    char c;     
    while((c=getchar())==' '||c=='\n'||c=='\r');     
        ret=c-'0';     
    while((c=getchar())!=' '&&c!='\n'&&c!='\r')                 
            ret=ret*10+c-'0';     
        return ret;
}

int main() {
    while(scanf("%d",&n)!=EOF) {
        E = 0; extr = 0;
        fill(head,head+n+1,-1);
        scanf("%d",&K);
        for(int i = 0; i < K; i++) {
//            scanf("%d",&pri[i]);
              pri[i] = get_val();
        }
        lld num;
        for(int i = 1; i <= n; i++) {
            scanf("%I64d",&num);
            split(i,num);
        }
        E = 0;
        for(int i = 1,a,b; i < n; i++){
            a = get_val();
            b = get_val();
  //          scanf("%d%d",&a,&b);
            add(a,b);
            add(b,a);
        }

        printf("%I64d\n",nice.gao()+extr);
    }
    return 0;
}
/*
4
2 2 5
100 10 100 10
1 2
2 3
3 4

7
1 2 
2 2 2 2  2 2 2
1 2
1 3
2 4
2 5
3 6
3 7

5
3 2 3 5
2500 200 9 270000 27
4 2
3 5
2 5
4 1

4
7
1

6
3 2 3 5
6 1 30 150 150 12
1 2
2 4
1 3
3 5
3 6

 */ 
