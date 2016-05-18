/*
    dp[node][i][0]: node节点 在 消耗i陷阱时 并从该节点往下走（或者理解为还有能力往下走）的最大权值
    dp[node][i][1]: node节点 在 消耗i陷阱时 并从子节点往上走（到该节点或者理解为没有能力接着走了）的最大权值


*/

#pragma comment(linker,"/STACK:102400000,102400000")
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
#define ReadFile(str) freopen(str,"r",stdin);
#define CLR(c,v) memset(c,v,sizeof(c))
typedef long long ll;
const int N = 5e4 + 5;

struct Node{
    int val;  // 权值
    int tra;  // 陷阱
    bool vis; // 判断回头路
    ll dp[5][2];
}node[N];
vector <int > tree[N];
ll ans;
int n,c;

void dfs(int father){ // father,child(id)  nfather,nchild(node) 
    int size = tree[father].size();
    node[father].vis = true;
    Node& nfather = node[father];
    
    ///// init dp
    int& trap = nfather.tra;
    nfather.dp[trap][0] = nfather.dp[trap][1] = nfather.val;

    for(int i = 0 ; i < size ; i++){
        int  child  = tree[father][i];
        Node& nchild = node[child];
        if(nchild.vis)continue;
        dfs(child);
        for(int j = 0 ; j <= c ; j++){
            for(int k = 0 ; k+j <= c ; k++){
                if(j != c) // 若j==c了 那么在父节点得到的最大值就没有机会再往孩子下面走了 否则还有机会往下走
                    ans = max(ans , nfather.dp[j][0] + nchild.dp[k][1]); //所以转移是到父节点+另一个孩子回来
                if(k != c) // 同理
                    ans = max(ans , nfather.dp[j][1] + nchild.dp[k][0]); 
                if(j + k < c)// 以nfather为衔接点 当i+k==c的时候有(1||2)个端点一定在陷阱上
                    ans = max(ans , nfather.dp[j][0] + nchild.dp[k][0]); 
                    
                //ans = max(ans , nfather.dp[j][1] + nchild.dp[k][1]); 
            }
        }
        for(int j = 0 ; j <= c ; j++){
            if(j+trap>c)break;
            nfather.dp[j+trap][0] = max(nfather.dp[j+trap][0] , nfather.val + nchild.dp[j][0]);    
            if(j) // 当前机会数 必须大于0才能网上推
            nfather.dp[j+trap][1] = max(nfather.dp[j+trap][1] , nfather.val + nchild.dp[j][1]);    
        }
    }
}

int main(){
    //ReadFile("in.txt");
    int T;cin >> T;
    while(T--){
        cin >> n >> c;
        for(int i = 0 ; i < n ; i++){
            scanf("%d %d", &node[i].val, &node[i].tra);
            node[i].vis = false;
            CLR(node[i].dp,0);
        }
        for(int i = 1 ; i < n ; i++){
            int u,v;
            scanf("%d %d", &u, &v);
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        ans = 0;
        dfs(0);
        cout << ans << endl;
        for(int i = 0; i <= n ; i++)
            tree[i].clear();
    }
    return 0;
}