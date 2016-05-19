/*
¶ÔÓÚÈÎÒâµÄÕûÊýn£¬±ØÈ»´æÔÚÒ»¸öÓÉ²»¶àÓÚÁ½¸öµÄÊýÀ´×é³ÉµÄÒ»¸ö±¶Êý¡£
ÒòÎªa£¬aa£¬aaa¡­¡­È¡n+1¸ö£¬Ôò±ØÓÐÁ½¸öÄ£nÓàÊýÏàÍ¬£¬Ïà¼õ¼´µÃnµÄ±¶Êým¡£
¶ømÖ»ÓÉa¡¢0×é³É¡£
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <set>
#include <queue>
#include <string>
using namespace std;

const int maxn = 100000;
int N;
int a[5], cnt;
string ans;
int ansn;
struct node{
    int d;
    int pre;
    int re;
};
node q[maxn];
int head, tail;

string tmp;
void getstr(int pos){
    if(pos==-1) return ;
    getstr(q[pos].pre);
    tmp += q[pos].d + '0';
}
int cmpstr(string a, string b){
    if( a.size()<b.size() || (a.size()==b.size()&&a<b) )
        return -1;
    return 1;
}
bool hash[70000];
void bfs(){
    head = tail = 0;
    node nt, qt;
    memset(hash, 0, sizeof hash );
    for(int i=0; i<cnt; ++i){
        if(a[i]==0) continue;
        nt.d = a[i];
        nt.pre = -1;
        nt.re = a[i] % N;
        q[tail++] = nt;
        hash[nt.re] = 1;
    }
    while(head<tail){
        nt = q[head];
        for(int i=0; i<cnt; ++i){
            qt.d = a[i]; qt.pre = head; qt.re = (nt.re*10+a[i]) % N;
            if(!hash[qt.re]){
                hash[qt.re] = 1;
                q[tail++] = qt;
            }
            if(qt.re==0){
                tmp = "";
                getstr(tail-1);
                if(cnt<ansn){
                    ans = tmp;
                    ansn = cnt;
                }else if(cnt==ansn){
                    if( cmpstr(tmp, ans) <0){
                        ans = tmp;
                        ansn = cnt;
                    }
                }
            }
        }
        head++;
    }
}

void solve(int N){
    set<int> st;
    ans = "";
    for(int x=N, y; x>0; x/=10){
        y = x % 10;
        ans += y + '0';
        st.insert(y);
    }
    ansn = st.size();
    reverse(ans.begin(), ans.end());
    cnt = 1;
    for(int i=1; i<10; ++i){
        a[0] = i;
        bfs();
    }
    cnt = 2;
    for(int i=0; i<10; ++i){
        a[0] = i;
        for(int j=i+1; j<10; ++j){
            a[1] = j;
           bfs();
        }
    }
    printf("%s\n", ans.c_str());
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(~scanf("%d", &N)){
        if(N==0) break;
        if(N<10){
            printf("%d\n", N);
            continue;
        }
        solve(N);
    }
    return 0;
}
