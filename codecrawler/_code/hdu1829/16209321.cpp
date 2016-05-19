#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 2000;

int pre[2*MAX+5];

bool mark;

void init(int n){
    int i;
    ////ï¼authorï¼CSDNï¼åé£ï¼
    for(i=1;i<=MAX+n;++i)pre[i] = i;
    mark = true;
}

int root(int x){
    if(x!=pre[x]){
        pre[x] = root(pre[x]);
    }
    return pre[x];
}

void merge(int x,int y){
    int fx,fy;
    fx = root(x);
    fy = root(y-MAX);
    
    if(fx==fy){
        mark = false;
        return;
    }
    
    fy = root(y);
    if(fx!=fy){
        pre[fx] = pre[fy];
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    //ï¼authorï¼CSDNï¼åé£ï¼
    int t,i,n,m,x,y,k;
    scanf("%d",&t);
    for(i=1;i<=t;++i){
        scanf("%d %d",&n,&m);
        init(n);
        for(k=1;k<=m;++k){
            scanf("%d %d",&x,&y);
            if(mark){
                merge(x,y+MAX);
                merge(y,x+MAX);
            }
        }
        printf("Scenario #%d:\n",i);
        if(mark){
            printf("No suspicious bugs found!\n");
        }else{
            printf("Suspicious bugs found!\n");
        }
        printf("\n");
    }
    return 0;
}
