#pragma comment(linker, "/STACK:102400000,102400000")
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define maxn 1001

char ma[maxn][maxn];
int check[maxn][maxn];
int dep[maxn][maxn];

struct Node{
    int x,y;
    Node(int _x=0,int _y=0):x(_x),y(_y){}
};

queue<Node> que;
vector<int> ans;
vector<Node> one;
vector<Node> zero;
int n,m;
void dfs(int x,int y){
    if(check[x][y] || x  == n || y == m || x < 0 || y < 0 || ma[x][y] == '1') return;
    que.push(Node(x,y));
    check[x][y] = 1;
    dfs(x+1,y);
    dfs(x,y+1);
    dfs(x-1,y);
    dfs(x,y-1);
}
void work(){
    while(que.size() > 0)
        que.pop();
    if(ma[0][0] == '1'){
        check[0][0] = 1;
        que.push(Node(0,0));
    }
    else {
        dfs(0,0);
    }
}
void bfs(){
    Node a;
    while(que.size() > 0){
        a = que.front();
        que.pop();
        if(a.x + 1 < n && a.y < m && check[a.x+1][a.y] == 0){
            que.push(Node(a.x+1,a.y));
            check[a.x+1][a.y] = 1;
            dep[a.x+1][a.y] = dep[a.x][a.y] + 1;
        }
        if(a.x < n && a.y + 1 < m && check[a.x][a.y+1] == 0){
            que.push(Node(a.x,a.y+1));
            check[a.x][a.y+1] = 1;
            dep[a.x][a.y+1] = dep[a.x][a.y] + 1;
        }
    }
}
int mark[maxn][maxn];
void nidfs(int x,int y){
    mark[x][y] =  1;
    if(x-1>=0 && y >= 0 && mark[x-1][y] == 0 && dep[x-1][y] == dep[x][y] - 1 && dep[x-1][y] > 0)
        nidfs(x-1,y);
    if(x >= 0 && y-1>=0 && mark[x][y-1] == 0 && dep[x][y-1] == dep[x][y] - 1 && dep[x][y-1] > 0)
        nidfs(x,y-1);
}

void getans(){
    ans.clear();
    Node a;
    while(1){
        one.clear();
        zero.clear();
        while(que.size() > 0){
            a = que.front();
            que.pop();
            if(a.x == n -1 && a.y == m -1 ) return ;
            if(a.x + 1 < n && a.y < m && check[a.x+1][a.y] == 0&& dep[a.x+1][a.y] == dep[a.x][a.y] + 1 && mark[a.x+1][a.y]){
                if(ma[a.x+1][a.y] == '1') one.push_back(Node(a.x+1,a.y));
                else zero.push_back(Node(a.x+1,a.y));
                check[a.x+1][a.y] = 1;
            }
            if(a.x < n && a.y + 1< m && check[a.x][a.y+1] == 0 && dep[a.x][a.y+1] == dep[a.x][a.y] + 1 && mark[a.x][a.y+1]){
                if(ma[a.x][a.y+1] == '1') one.push_back(Node(a.x,a.y+1));
                else zero.push_back(Node(a.x,a.y+1));
                check[a.x][a.y+1] = 1;
            }
        }
        if(zero.size() > 0){
            ans.push_back(0);
            for(int i = 0;i < zero.size();i++)
                que.push(zero[i]);
        }
        else {
            ans.push_back(1);
            for(int i = 0;i < one.size();i++)
                que.push(one[i]);
        }
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i = 0;i < n; i++){
            scanf("%s",ma[i]);
        }
        memset(check,0,sizeof(check));
        work();
        memset(dep,0,sizeof(dep));
        bfs();
// for(int i = 0;i < n; i++){
//            for(int j = 0;j < m; j++){
//                printf("%d ",dep[i][j]);
//            }cout<<endl;
//        }
//        cout<<endl;
        memset(mark,0,sizeof(mark));
        nidfs(n-1,m-1);

        memset(check,0,sizeof(check));
        work();
        getans();
//        for(int i = 0;i < n; i++){
//            for(int j = 0;j < m; j++){
//                printf("%d ",dep[i][j]);
//            }cout<<endl;
//        }
        if(ans.size() == 0 && ma[0][0] =='0'){
            printf("0\n");
        }
        else {
            if(ma[0][0] == '1') printf("1");
            for(int i = 0;i < ans.size(); i++)
                printf("%d",ans[i]);
            printf("\n");
        }

    }
    return 0;

}
/*
20
2 2
11
11
3 3
001
111
101
3 3
111
111
111
3 3
000
000
000
3 3
001
011
111
*/

