#include <iostream>
#include <algorithm>
using namespace std;
#define N 105

struct treasure_node{
    int pi,mi;
};

treasure_node treasure[N];

bool cmp(treasure_node a,treasure_node b){
    return a.pi>b.pi;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("2111in.txt","r",stdin);
#endif
    int v,n,i,value;
    while (scanf("%d",&v)!=EOF&&v){
        scanf("%d",&n);
        for (i=0;i<n;i++)
            scanf("%d%d",&treasure[i].pi,&treasure[i].mi);
        sort(treasure,treasure+n,cmp);
        value=0;
        for (i=0;i<n&&v;i++){
            if (v>=treasure[i].mi){
                v-=treasure[i].mi;
                value+=treasure[i].mi*treasure[i].pi;
            }
            else {
                value+=treasure[i].pi*v;
                v=0;
            }
        }
        printf("%d\n",value);
    }
    return 0;
}