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
    short d;
    int pre;
    int re;
};
node q[maxn];
int head, tail;

string tmp;

inline int cmpstr(string a, string b){
    if( a.size()<b.size() || (a.size()==b.size()&&a<b) )
        return -1;
    return 1;
}
bool hash[70000];
bool bfs(){
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
                for(int pos=tail-1; pos!=-1; pos = q[pos].pre){
                    tmp += q[pos].d + '0';
                }
                reverse(tmp.begin(), tmp.end());
                return 1;
            }
        }
        head++;
    }
    return 0;
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
    for(a[0]=1; a[0]<10; ++a[0]){
        if(bfs())
        if(ansn>cnt || (ansn==cnt&&cmpstr(tmp,ans)<0) ){
            ans = tmp;
            ansn = cnt;
        }
    }
    if(ansn==cnt){
        printf("%s\n", ans.c_str());
        return ;
    }
    cnt = 2;
    for(a[0]=0; a[0]<10; ++a[0]){
        for(a[1]=a[0]+1; a[1]<10; ++a[1]){
           if(bfs())
           if(ansn>cnt ||(ansn==cnt&&cmpstr(tmp,ans)<0)){
                ans = tmp;
                ansn = cnt;
           }
        }
    }
    printf("%s\n", ans.c_str());
}

template<class T>
inline bool scan_d(T &ret){
    char c; ret = 0;
    while((c=getchar())<'0'||c>'9');
    while(c>='0'&&c<='9') ret = ret*10 + (c-'0'),c=getchar();
    return 0;
}
int main(){
   // freopen("in.txt","r",stdin);
    while(true){
        scan_d(N);
        if(N==0) break;
        if(N<10){
            printf("%d\n", N);
            continue;
        }
        solve(N);
    }
    return 0;
}
