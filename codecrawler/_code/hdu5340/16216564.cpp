#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<queue>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1 | 1
using namespace std;
const int N=2e4+10;
int INF=0x7f7f7f7;
int T,n,m,k;
const int MOD=1e9+7;
char s[N];
int len;
vector<int> vec[26];
void init(){
    for(int i=0;i<26;i++) vec[i].clear();
    for(int i=0;i<len;i++){
        vec[s[i]-'a'].push_back(i); /*æ è®°å­æ¯åºç°çä½ç½®*/
    }
}
bool ok(int l,int r){
    while(l<=r){
        if(s[l++]!=s[r--]) return false;
    }
    return true;
}

bool solve(){
    for(int i=0;i<vec[s[0]-'a'].size();i++){/*æä¸¾ç¬¬ä¸æ®µ*/
        int u=vec[s[0]-'a'][i];
        if(u+2>=len || !ok(0,u)) continue;
        u++;
        for(int j=0;j<vec[s[u]-'a'].size();j++){
            int t=vec[s[u]-'a'][j];/*æä¸¾ç¬¬äºæ®µ*/
            if(t<u) continue;
            if(t+1>=len || s[t+1]!=s[len-1]|| !ok(u,t)) continue;
            if(ok(t+1,len-1)) {/*å¤æ­ç¬¬ä¸æ®µæ¯å¦å¯ä»¥*/
               return true;
             }
        }
    }
    return false;
}
int main()
{
#ifndef  ONLINE_JUDGE
 freopen("aaa","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s",s);
        len=strlen(s);
        init();
        if(solve()) puts("Yes");
        else puts("No");
    }

    return 0;
}
