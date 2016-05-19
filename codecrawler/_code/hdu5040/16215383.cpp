#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N = 510;
char map[N][N];
bool ban[N][N][4], vis[N][N][4];
struct Node{
    int x, y, u;
    Node(){}
    Node(int x, int y, int u):x(x),y(y),u(u){}
    bool operator < (const Node &A)const{
        return u > A.u;
    }
};
int xl[4]={-1,0,1,0};
int yl[4]={0,1,0,-1};
int getd(char ch){
    if(ch=='N') return 0;
    if(ch=='E') return 1;
    if(ch=='S') return 2;
    if(ch=='W') return 3;
    return -1;
}
int T, n, sx, sy;
int solve(){
    memset(vis, 0, sizeof(vis));
    priority_queue<Node> Q;
    Q.push(Node(sx, sy, 0));
    while(!Q.empty()){
        Node nd=Q.top(); Q.pop();
        if(vis[nd.x][nd.y][nd.u%4]) continue;
        if(map[nd.x][nd.y]=='T')    return nd.u;
        vis[nd.x][nd.y][nd.u%4]=1;
        Q.push(Node(nd.x, nd.y, nd.u+1));
        for(int i=0; i<4; i++){
            int a = nd.x + xl[i];
            int b = nd.y + yl[i];
            if(a<0 || a>=n || b<0 || b>=n)  continue;
            if(map[a][b]=='#')  continue;
            int u = nd.u;
            if(ban[a][b][nd.u%4] || ban[nd.x][nd.y][nd.u%4]){
                u += 3;
            }
            else{
                u++;
            }
            if(!vis[a][b][u%4]) Q.push(Node(a,b,u));
        }
    }
    return -1;
}
int main(){
    scanf("%d",&T);
    for(int t=1; t<=T; t++){
        scanf("%d", &n);
        memset(ban, 0, sizeof(ban));
        for(int i=0; i<n; i++){
            scanf("%s", map[i]);
            for(int j=0; j<n; j++){
                if(map[i][j]=='M'){
                    sx=i; sy=j;
                }
                else{
                    int d = getd(map[i][j]);
                    if(~d){
                        for(int k=0; k<4; k++){
                            ban[i][j][k] = 1;
                            int x = i + xl[(d+k)%4];
                            int y = j + yl[(d+k)%4];
                            if(x<0 || x>=n || y<0 || y>=n)  continue;
                            ban[x][y][k] = 1;
                        }
                    }
                }
            }
        }
        printf("Case #%d: %d\n", t, solve());
    }
    return 0;
}
