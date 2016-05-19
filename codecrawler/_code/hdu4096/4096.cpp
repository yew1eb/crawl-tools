#include <iostream>
#include <cstdio>
#include <sstream>
#include <cstring>
#include <string>
#include <map>
#include <queue>
#include <vector>
using namespace std;
const int N = 101;
map <string,int> noun;
map <string,int> verb;
int n,m;
string res,wd[20];
vector <int> adj[N*5];
bool visited[N*5];
int getNounId(string str){
    if (noun[str]==0) noun[str] = ++n;
    return noun[str];
}
int getVerbId(string str){
    if (verb[str]==0){
        ++m;
        verb[str] = m + N;
    }
    return verb[str];
}
void statements(int l){
    wd[l-1] = wd[l-1].substr(0,wd[l-1].length()-1);
    int v,u;
    if (l==3){
        v = getNounId(wd[0]);
        if (wd[1]=="are") u = getNounId(wd[2]);
        else u = getVerbId(wd[2]);
    }else{
        v = getVerbId(wd[3]);
        if (wd[4]=="are") u = getNounId(wd[5]);
        else u = getVerbId(wd[5]);
    }
    adj[v].push_back(u);
}
queue <int> q;
bool bfs(int v,int u){
    if (v==u) return true;
    while (!q.empty()) q.pop();
    visited[v] = true;
    q.push(v);
    while (!q.empty()){
        int k = q.front(); q.pop();
        for (int i=0;i<(int)adj[k].size();i++){
            int r = adj[k][i];
            if (r==u) return true;
            if (!visited[r]){
                q.push(r);
                visited[r] = true;
            }
        }
    }
    return false;
}
void questions(int l){
    wd[l-1] = wd[l-1].substr(0,wd[l-1].length()-1);
    int v,u;
    if (l==3){
        v = noun[wd[1]];
        if (wd[0]=="are"){
            if (wd[1]==wd[2]){
                res= res + 'Y';
                return ;
            }
            u = noun[wd[2]];
        }
        else u = verb[wd[2]];
    }else{
        v = verb[wd[4]];
        if (wd[0]=="are") u = noun[wd[5]];
        else{
            if (wd[4]==wd[5]){
                res = res + 'Y';
                return ;
            }
            u = verb[wd[5]];
        }
    }
    if (v==0 || u==0) {res=res+'M';return;}
    memset(visited,false,sizeof(visited));
    if (bfs(v,u)) res = res + 'Y';
    else res = res + 'M';
}
void read(){
    int l;
    char chr[80];
    while (gets(chr)){
        l = 0;
        string str(chr);
        istringstream is(str);
        while (is>>wd[l])   l++;
        //for (int i=0;i<l;i++)   cout<<wd[i]<<' ';puts("");
        if (wd[l-1][wd[l-1].length()-1] == '.') statements(l);
        else if (wd[l-1][wd[l-1].length()-1] == '?') questions(l);
        else break;
    }
}
int main(){
   // freopen("test.in","r",stdin);
    int T; cin>>T;
    char ch = getchar(); while (ch!='\n') ch = getchar();
    for (int it=0;it<T;++it){
        printf("Case #%d:\n",it+1);
        n = m = 0;
        res = "";
        noun.clear();
        verb.clear();
        for (int i=0;i<N*5;i++) adj[i].clear();
        read();
        puts(res.c_str());
    }
    return 0;
}