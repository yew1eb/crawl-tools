/*
ä¸ºbå¼ä¸ä¸ªæ°ç»ï¼å­æ¾æå¤§çaçä¸ªæ°ï¼
vec[i]æ¥å­æ¾a,c,dä¸­çcï¼dä»¥åa,c,dè¿ä¸ªåç´ çåç´ 
ç¶åä»å¤§å°å°æä¸¾aï¼ä»å°å°å¤§å¥½åä¸å¯ä»¥ï¼å ä¸ºä¸ç¥éæ¯ä¸ä¸æ¬¡aå¨äºç»´æ ç¶ä¸­å¨xï¼yè¿ä¸ªç¹æ¾äºä¸æ¬¡è¿æ¯å½åæä¸¾çaå¨xï¼yè¿ä¸ªç¹æ¾äºä¸æ¬¡ï¼
ç¶åäºç»´æ ç¶æ°ç»å¤æ­åºåä¸­ææ ç¹ï¼åæ´æ°ï¼æå®
*/
#include <bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
const int maxn = 100005;

struct ppp{
    int a,b;
    void read(){
        scanf("%d%d",&a,&b);
    }
}A[maxn];
struct pp{
    int c,d,e;
    void read(){
        scanf("%d%d%d",&c,&d,&e);
    }
}B[maxn];
struct ttt{
    int x,y,cnt;
    ttt(int _c,int _d,int _cnt){
        x = _c,y = _d,cnt = _cnt;
    }
};
int n,m;
int max_a[maxn][2];
vector<ttt> vec[maxn];
int sum[1005][1005];
inline int lowbit(int x){
    return x & -x;
}
int query(int x,int y){
    int ret = 0;
    for(int i = x;i >= 1;i -= lowbit(i)){
        for(int j = y;j >= 1;j -= lowbit(j)){
            ret += sum[i][j];
        }
    }
    return ret;
}
void add(int x,int y){
    for(int i = x;i <= 1000;i += lowbit(i)){
        for(int j = y;j <= 1000;j += lowbit(j)){
            sum[i][j] += 1;
        }
    }
}
int cmp(ttt a,ttt b){
    return (a.x != b.x) ? a.x > b.x : a.y > b.y;
}

void init(){
    for(int i= 0;i < maxn;i++){
        max_a[i][0] = max_a[i][1] = 0;
        vec[i].clear();
    }
    for(int i = 1,a,b;i <= n;i++){
        scanf("%d%d",&a,&b);
        if(max_a[b][0] < a){
            max_a[b][0] = a;
            max_a[b][1] = 1;
        }else if(max_a[b][0] == a){
            max_a[b][1]++;
        }
    } 
    for(int i = 1,c,d,e;i <= m;i++){
        scanf("%d%d%d",&c,&d,&e);
        if(max_a[e][1] != 0){
//            cout<<max_a[e][0]<<" "<<max_a[e][1]<<endl;
            vec[max_a[e][0]].push_back(ttt(c,d,max_a[e][1]));
        }
    }
    mem(sum,0);
}

int main(){
    int T;
    scanf("%d",&T);
    for(int cas = 1;cas <= T;cas++){
        scanf("%d%d",&n,&m);
        init();
        for(int i = 0;i < maxn;i++)sort(vec[i].begin(),vec[i].end(),cmp);
        for(int i = 0;i < maxn;i++){
            for(int j = 1;j < vec[i].size();j++){
                if(vec[i][j - 1].x == vec[i][j].x && vec[i][j - 1].y == vec[i][j].y){
                    vec[i][j].cnt += vec[i][j - 1].cnt;
                    vec[i][j - 1].cnt = 0;
                }
            }
        }
        int now;
        int ans = 0;
        for(int i = maxn - 1;i >= 0;i--){
            for(int j = 0;j < vec[i].size();j++){
                if(vec[i][j].cnt == 0)continue;
                now = query(1000,1000);
                now -= query(vec[i][j].x - 1,1000);
                now -= query(1000,vec[i][j].y - 1);
                now += query(vec[i][j].x - 1,vec[i][j].y - 1);
                if(now <= 0){
                    ans += vec[i][j].cnt;
                    add(vec[i][j].x,vec[i][j].y);
//                    cout<<i<<" "<<vec[i][j].x<<" "<<vec[i][j].y<<" "<<vec[i][j].cnt<<endl;
                }
            }
        }
        printf("Case #%d: %d\n",cas,ans);
    }
}