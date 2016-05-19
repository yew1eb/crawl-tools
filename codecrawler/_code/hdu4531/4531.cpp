#include<cstdio>
#include<cstring>
#include<vector>
#include<cctype>
using namespace std;

typedef int int64;

const int HashSize = 1000003; // 哈希值尺寸，视情况而定
const int MaxState = 400000;     // 共需要存多少个
const int MAXQUE = 500000;

int  g[40][40];
int  mat[3][3];
char str[12][6];
bool vis[40], alpha[150];
bool isCol[3], isRow[3];
int  ans;
vector<int>G[40];


template<typename Type>
class Hash{
public:
    void init(){
        rear=1;  
        memset(head, -1, sizeof(head));
        memset(state, -1, sizeof(state));
    }

    int insert(Type s){  
        int h = hash(s), u = head[h];
        while(u!=-1){
            if(state[u] == s) return u; //返回所在位置
            u = next[u];
        }
        state[rear] = s;
        next[rear] = head[h];
        head[h] = rear++;
        return rear-1;  // 返回新插入的位置
    }
    int find(Type s){
        int h = hash(s), u = head[h];
        while(u!=-1){
            if(state[u] == s) return u; //返回所在位置
            u = next[u];
        }
        return 0;
    }

private:
    int hash(Type x){
        int d = ((x&0x7fffffff)%HashSize);
        return d;
    }
private:
    int head[HashSize], next[MaxState], rear;
    Type state[MaxState];
};
Hash<int64>hash;


inline void init();

struct Node{
    int st;
    int cnt;
}Q[MAXQUE];


int que[100];
char s[40];
inline bool bfs(int st){
    int pos=35;
    while(st>0){
        int p = st%10;
        for(int k=3; k>=0; --k) s[pos--] = str[p][k];
        st /= 10;
    }
    memset(alpha, 0, sizeof(alpha));
    memset(vis, 0, sizeof(vis));

    for(int i=0; i<36; ++i)if(!vis[i+1]){
        if(alpha[s[i]]) return false;
        vis[i+1] = true;
        int front=0, rear=1;
        que[0] = i+1;
        while(front < rear){
            int u = que[front++];
            for(int j=0; j<G[u].size(); ++j){
                int v = G[u][j];
                if(!vis[v] && s[v-1]==s[u-1]){
                    vis[v] = true;
                    que[rear++] = v;
                }
            }
        }
        alpha[s[i]] = true;
    }
    return true;
}

char buf[15];
inline int rotateRow(int st, int row){
    sprintf(buf, "%d", st);
    char tmp = buf[row*3];
    buf[row*3] = buf[row*3+1];
    buf[row*3+1] = buf[row*3+2];
    buf[row*3+2] = tmp;
    sscanf(buf, "%d", &st);
    return st;
}
inline int rotateCol(int st, int col){
    sprintf(buf, "%d", st);
    char tmp = buf[col];
    buf[col]   = buf[3+col];
    buf[3+col] = buf[6+col];
    buf[6+col] = tmp;
    sscanf(buf, "%d", &st);
    return st;
}

inline void solve(){
    Q[0].st = 123456789;
    Q[0].cnt = 0;
    int front=0, rear=1;
    hash.insert(Q[0].st);
    while(front < rear){
        const Node& q = Q[front++];

	    if(bfs(q.st)){
            ans = q.cnt;
            return ;
        }

        int st;
        for(int i=0; i<3; ++i){
            if(!isRow[i]) {
                st = rotateRow(q.st, i);
                if(!hash.find(st)){
                    hash.insert(st);
                    Q[rear].st = st;
                    Q[rear++].cnt = q.cnt+1;
                }

                st = rotateRow(st, i);
                if(!hash.find(st)){
                    hash.insert(st);
                    Q[rear].st = st;
                    Q[rear++].cnt = q.cnt+1;
                }
            }
            if(!isCol[i]){
                st = rotateCol(q.st, i);
                if(!hash.find(st)){
                    hash.insert(st);
                    Q[rear].st = st;
                    Q[rear++].cnt = q.cnt+1;
                }

                st = rotateCol(st, i);
                if(!hash.find(st)){
                    hash.insert(st);
                    Q[rear].st = st;
                    Q[rear++].cnt = q.cnt+1;
                }
            }
        }
    }
}

int main(){
   
    int T, cas=1;
    init();
    scanf("%d", &T);

    while(T--){
         
        int idx=1;
        memset(isRow, 0, sizeof(isRow));
        memset(isCol, 0, sizeof(isCol));
        for(int i=0; i<3; ++i){
            for(int j=0; j<3; ++j){
                char& ch = str[idx][0];
                ch = getchar();
                while(!isalpha(ch)) ch=getchar();
                for(int k=1; k<5; ++k) str[idx][k] = getchar();
                if(str[idx][4] == '1') 
                    isRow[i]=isCol[j]=true;
                mat[i][j] = idx++;
            }
        }

        hash.init();
        ans = 100000000;
        solve();
        printf("Case #%d: %d\n",cas++, ans);

    }
    
    return 0;
}



// =============================
inline void init(){
memset(g, 0, sizeof(g));
	g[1][3]=1, g[1][4]=1, 
	g[5][7]=1, g[5][8]=1, 
	g[9][11]=1, g[9][12]=1, 
	g[13][2]=1, g[13][15]=1, g[13][16]=1, 
	g[17][6]=1, g[17][19]=1, g[17][20]=1, 
	g[21][10]=1, g[21][23]=1, g[21][24]=1, 
	g[25][14]=1, g[25][27]=1, g[25][28]=1, 
	g[29][18]=1, g[29][31]=1, g[29][32]=1, 
	g[33][22]=1, g[33][35]=1, g[33][36]=1, 

	g[2][3]=1, g[2][4]=1, g[2][13]=1, 
	g[6][7]=1, g[6][8]=1, g[6][17]=1, 
	g[10][11]=1, g[10][12]=1, g[10][21]=1, 
	g[14][15]=1, g[14][16]=1, g[14][25]=1, 
	g[18][19]=1, g[18][20]=1, g[18][29]=1, 
	g[22][23]=1, g[22][24]=1, g[22][33]=1, 
	g[26][27]=1, g[26][28]=1, 
	g[30][31]=1, g[30][32]=1, 
	g[34][35]=1, g[34][36]=1, 

	g[3][1]=1, g[3][2]=1, 
	g[15][13]=1, g[15][14]=1, 
	g[27][25]=1, g[27][26]=1, 
	g[7][6]=1, g[7][5]=1, g[7][4]=1, 
	g[19][18]=1, g[19][17]=1, g[19][16]=1, 
	g[31][30]=1, g[31][29]=1, g[31][28]=1, 
	g[11][10]=1, g[11][9]=1, g[11][8]=1, 
	g[23][22]=1, g[23][21]=1, g[23][20]=1, 
	g[35][34]=1, g[35][33]=1, g[35][32]=1, 
	g[4][2]=1, g[4][1]=1, g[4][7]=1, 
	g[16][14]=1, g[16][13]=1, g[16][19]=1, 
	g[28][26]=1, g[28][25]=1, g[28][31]=1, 
	g[8][6]=1, g[8][5]=1, g[8][11]=1, 
	g[20][18]=1, g[20][17]=1, g[20][23]=1, 
	g[32][30]=1, g[32][29]=1, g[32][35]=1, 
	g[12][10]=1, g[12][9]=1, 
	g[24][22]=1, g[24][21]=1, 
	g[36][34]=1, g[36][33]=1;

    for(int i=1; i<=36; ++i){
        G[i].clear();
        for(int j=1; j<=36; ++j)if(g[i][j]){
            G[i].push_back(j);
        }
    }
}
