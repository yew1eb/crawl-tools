#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxn 200007
using namespace std;

int n, m, place[200100], next[200100], que[10100][11], data[210000];

void init(){
    memset(data,0,sizeof(data));
    memset(place,0,sizeof(place));
    for (int i=1;i<=n*m*2;i++) next[i] = i;
}

int to(int k){
    if (next[k]==k) return k;
    next[k] = to(next[k]);
    return next[k];
}

void insert_(int pos,int v){
    int a = to(pos);
    next[a] = next[a+1];
    place[a] = v;
}

void init1()
{
    int p=1;
    for (int i=1;i<=n*m*2;i++)
        if (place[i]){
            //cout<<place[i]<<endl;
            que[place[i]][0]++;
            que[place[i]][que[place[i]][0]] = p;
            p++;
        }
}

void in_(int k,int v){
    for (int i=k;i<=maxn;i+=i&(-i))
        data[i] = max(data[i],v);
}

int find_(int k){
    int ans = 0;
    for (int i=k;i>0;i-=i&(-i))
        ans = max(ans,data[i]);
    return ans;
}

int main()
{
    int T,a ,pos;
    scanf("%d",&T);
    for (int T1=1;T1<=T;T1++){
        scanf("%d %d",&n,&m);
        memset(que,0,sizeof(que));
        init();
        for (int i=0;i<n*m;i++){
            scanf("%d %d",&a,&pos);
            insert_(pos,a);
        }
        init1();
        init();
    for (int i=0;i<n*m;i++){
            scanf("%d %d",&a,&pos);
            insert_(pos,a);
    }
    for (int i=1;i<=n*m*2;i++)
        if (place[i]){
            int u = place[i];
            for (int j=que[u][0];j>0;j--){
                int v = que[u][j];
                int l = find_(v);
                in_(v+1,l+1);
            }
        }
    printf("Case #%d: %d\n",T1,find_(maxn));
    }
}