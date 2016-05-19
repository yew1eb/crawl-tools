#include <iostream>
#include <algorithm>
using namespace std;
#define N 105

struct program_node{
    int s,f;
};
program_node program[N];

bool cmp(program_node a,program_node b){
    return a.f<b.f;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("2037in.txt","r",stdin);
#endif
    int n,i,k,time_e;
    while (scanf("%d",&n)!=EOF&&n){
        for (i=0;i<n;i++)
            scanf("%d%d",&program[i].s,&program[i].f);
        sort(program,program+n,cmp);
        k=0;
        time_e=0;
        for (i=0;i<n;i++)
            if (time_e<=program[i].s){
                time_e=program[i].f;
                k++;
            }
        printf("%d\n",k);
    }
    return 0;
}