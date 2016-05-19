#include <cstdio>
#include <stack>
#define N 201010
using namespace std;

stack<int> st;
struct NODE {
    int v,next;
} a[N],e[N];
int tr[N],pre[N],s[N],b[N];
int n,em,root,tt;

void update(int x) {
    while ( x<=n) {
        tr[x] += 1;
        x += x & -x;
    }
}

int gs(int x) {
    int s = 0;
    while (x>0) {
        s += tr[x];
        x -= x & -x;
    }
    return s;
}

void joint(int a1,int a2){
    e[++em].v = a2;
    e[em].next = a[a1].next;
    a[a1].next = em;
}

int main() {
    while ( ~scanf("%d%d",&n,&root)) {
        if ( !n && !root ) break;
        for ( int i(1); i<=n; i++) tr[i] = a[i].next = b[i] = pre[i]= 0;
        em = 0;
        tt = 0;

        for ( int i(1); i<n; i++) {
            int a1,a2;
            scanf("%d%d",&a1,&a2);
            joint(a1,a2);
            joint(a2,a1);
        }
        
        while (!st.empty()) st.pop();   // dfs
        st.push(root);
        while (!st.empty()) {
            int v = st.top();
            if ( !b[v] ){
                b[v] = 1;
                pre[v] = gs(v);
                update(v);
                for ( int p(a[v].next); p; p=e[p].next) {
                    if ( !b[e[p].v] ) {
                        int u = e[p].v;
                        st.push(u);
                    }
                }
            }
            if ( st.top() == v ) {
                s[v] = gs(v-1) - pre[v];
                st.pop();
            }
        }
        for ( int i(1); i<n; i++) printf("%d ",s[i]);
        printf("%d\n",s[n]);
    }
    return 0;
}
