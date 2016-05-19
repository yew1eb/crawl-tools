//æ·±åº¦ä¼åæç´¢
#include <iostream>

using namespace std;

#include <algorithm>
#include <cstdio>
#include <cstring>

int sticks[65];
bool used[65], flag;

int n, len, piece;

bool cmp(int a, int b)
{
    return a > b;
}

void dfs(int pos, int cur, int cnt)
{
    if(flag)return ;//å·²æç´¢å°å½åè§£å°±è¿å
    if(cur == len){
        cnt ++;
        if(cnt == piece){//å½åè§£å¯è¡
            flag = true;
        }
        dfs(0,0,cnt);
        return ;
    }
    if(pos == n)return ;//æå°äºæåä¸æ ¹stick
    int pre = -1;
    for(int i = pos; i < n; i ++){//ä»posçä½ç½®ç»§ç»­æç´¢
        if(!used[i] && sticks[i] != pre && cur + sticks[i] <= len){
            pre = sticks[i];
            used[i] = true;
            dfs(i + 1, sticks[i] + cur, cnt);
            used[i] = false;
            if(flag||pos==0)return;
        }
    }
}

int main()
{
//    freopen("input.txt", "r+", stdin);
    int i;
    int sum, max;
    while(scanf("%d", &n)&&n){
        sum = 0;
        for(i = 0; i < n; i ++){
            scanf("%d", &sticks[i]);
            sum += sticks[i];
        }
        sort(sticks, sticks+n, cmp);//éåºæåº
        max = sticks[0];
        for(i = max; i <= sum; i ++){//iä¸ºå½åæç´¢çæ¯æ ¹sitckçé¿åº¦
            if(sum%i==0){
                piece = sum/i;//stick çæ°ç®
                len = i;
                memset(used, false, sizeof(used));
                flag = false;
                dfs(0,0,0);
                if(flag)break;
            }
        }
        printf("%d\n", len);
    }
    return 0;
}