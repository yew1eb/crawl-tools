#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int n, m;
int sum1, sum2;
int dp[10005];
int vis[10005];
int sta[2][10005];

vector<int> mapn[10005];

void Init(int n)
{
    memset(vis, -1, sizeof(vis));
    for(int i = 0; i <= n; i++){
        mapn[i].clear();
    }
}

void Dfs(int rt) //æè²
{
    if(vis[rt] == -1)
        vis[rt] = 0;
    int len = mapn[rt].size();
    for(int i = 0; i < len; i++){
        int v = mapn[rt][i];
        if(vis[v] == -1){
            vis[v] = (vis[rt] ^ 1);
            if(vis[v] == 0)
                sum1++; // ç»è®¡é»ç¹
            else
                sum2++; // ç»è®¡ç½ç¹
            Dfs(v);
        }
    }
}

int main()
{
    int Test;
    cin>>Test;
    while(Test--){
        cin>>n>>m;
        Init(n);
        int x, y;
        for(int i = 0; i < m; i++){
            cin>>x>>y;
            mapn[x].push_back(y);
            mapn[y].push_back(x);
        }
        int top = 0;
        int num = 0, num1 = 0, num2 = 0;
        for(int i = 1; i <= n; i++){
            if(vis[i] == -1){
                sum1 = 1;
                sum2 = 0;
                Dfs(i);
                sta[0][top] = sum1; //ä¿å­é»ç¹
                sta[1][top++] = sum2; //ä¿å­ç½ç¹
                if(sum2 == 0){
                    num++;  //å­¤ç«ç¹
                }
                //ç²ç¥çå¡«åå®å¨äºåå¾çä¸¤è¾¹ï¼ç¨äºåªæ
                else if(num1 < num2){
                    num1 += sum1 > sum2 ? sum1 : sum2;
                    num2 += sum2 > sum1 ? sum1 : sum2;
                }
                else{
                    num2 += sum1 > sum2 ? sum1 : sum2;
                    num1 += sum2 > sum1 ? sum1 : sum2;
                }
            }
        }
        //åªæ
        if(abs(num1 - num2) <= num){
            cout<<((n+1)/2)*(n/2) - m<<endl;
            continue;
        }
        int minn = -1; // ä¿å­éæ©iä¸ªèéååæå°çç»ç¹æ°ã
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < top; i++){
            int minnn = 10000000000; //ç¨äºæ´æ°minn
            for(int j = n/2; j >= sta[0][i] || j >= sta[1][i]; j--){
                int ans = 0;
                //dp[j-sta[0][i]] >= minn æ¯ä¸ªèéåé½å¿é¡»é
                if(j >= sta[0][i] && dp[j-sta[0][i]] >= minn && ans < dp[j-sta[0][i]] + sta[0][i]){
                    ans = dp[j-sta[0][i]] + sta[0][i];
                }
                if(j >= sta[1][i] && dp[j-sta[1][i]] >= minn && ans < dp[j-sta[1][i]] + sta[1][i]){
                    ans = dp[j-sta[1][i]] + sta[1][i];
                }
                dp[j] = ans;
                if(ans && ans < minnn) //æ´æ°
                    minnn = ans;
            }
            minn = minnn;  //æ´æ°
        }
        cout<<(dp[n/2] * (n - dp[n/2])) - m<<endl;
    }
    return 0;
}