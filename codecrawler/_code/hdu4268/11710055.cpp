#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <set>
using namespace std;

const int N=100010;
struct Node{
    int x,y,type;
    bool operator<(const Node &b) const {
        if(x!=b.x) return x<b.x;
        if(y!=b.y) return y<b.y;
        return type>b.type;
    }
};

typedef multiset<int> SET;
typedef multiset<int>::iterator IT;


Node a[N<<1];
SET S;
const int Inf=0x80000000;
int T,n;


int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        for(int i=0;i<2*n;i++) scanf("%d%d",&a[i].x,&a[i].y);
        for(int i=0;i<n;i++) a[i].type=0;
        for(int i=n;i<n<<1;i++) a[i].type=1;
        sort(a,a+2*n);
        S.clear();
        int ans=0;
        for(int i=0;i<2*n;i++) {
            if(a[i].type==1) S.insert(a[i].y);
            else {
                if(!S.empty()){
                    if(*S.begin()<=a[i].y){
                        IT it=S.upper_bound(a[i].y);
                        it--;
                        ans++;
                        S.erase(it);
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}