#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
map<string,int> MP;
stack<int> ST;
const int N = 1100;
char ss[N], s[N];
int T, t, m, in[N];
bool mk[N];
vector<int> V[N];
int getid(){
    if(!MP.count(s)){
        MP[s] = ++m;
        V[m].clear();
    }
    return MP[s];
}
void solve(){
    int ans = 0, cnt = m;
    queue<int> Q;
    for(int i=1; i<=m; i++){
        if(!in[i])  Q.push(i);
    }
    while(cnt){
        while(!Q.empty()){
            int x=Q.front(); Q.pop();
            if(mk[x])   ST.push(x);
            else{
                cnt--;
                for(int i=0; i<V[x].size(); i++){
                    int j = V[x][i];
                    if(!(--in[j]))  Q.push(j);
                }
            }
        }
        if(!cnt)    break;
        ans++;
        while(!ST.empty()){
            int x = ST.top(); ST.pop();
            cnt--;
            for(int i=0; i<V[x].size(); i++){
                int j = V[x][i];
                if(!(--in[j]))  Q.push(j);
            }
        }
    }
    printf("Case %d: %d\n", ++t, ans);
}
void init(){
    MP.clear();
    m = 0;
    memset(mk, 0, sizeof(mk));
    memset(in, 0, sizeof(in));
}
void insert(){
    int len = strlen(ss);
    bool flag = 0;
    int i, j;
    for(i=0; i<len; i++){
        if(ss[i]=='*'){
            flag = 1;
            s[i] = '\0';
            break;
        }
        if(ss[i]==':'){
            s[i] = '\0';
            break;
        }
        s[i] = ss[i];
    }
    int x = getid();
    mk[x] |= flag;
    for(i+=2, j=0; i<len; i++){
        if(ss[i]==' '){
            s[j] = '\0';
            int y = getid();
            V[y].push_back(x);
            in[x]++;
            j = 0;
        }
        else{
            s[j++] = ss[i];
        }
    }
    s[j] = '\0';
    int y = getid();
    V[y].push_back(x);
    in[x]++;
}
int main(){
    scanf("%d", &T);
    getchar();
    gets(ss);
    t = 0;
    init();
    while(gets(ss)){
        if(strcmp(ss, "")==0){
            solve();
            init();
        }
        else{
            insert();
        }
    }
    solve();
    return 0;
}
