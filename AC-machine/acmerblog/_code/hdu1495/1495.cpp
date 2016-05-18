#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
const int maxn=100+5;
bool hash[maxn][maxn];

int a[5];
struct node {
    int v[3],step;
};
void BFS() {
    node cur,next;
    cur.v[0]=a[0];
    cur.v[1]=cur.v[2]=0;
    cur.step=0;
    queue<node>q;
    memset(hash,0,sizeof(hash));
    hash[0][0]=1;
    q.push(cur);
    while(!q.empty()) {
        cur=q.front();
        q.pop();
        if((cur.v[0]==a[0]/2&&cur.v[1]==a[0]/2)
           ||(cur.v[0]==a[0]/2&&cur.v[2]==a[0]/2)
           ||(cur.v[1]==a[0]/2&&cur.v[2]==a[0]/2)){
            printf("%d\n",cur.step); return ;///出现了两个杯子各占一半，找到状态
        }
        for(int i=0; i<3; i++)///找到还有水的杯子
            if(cur.v[i]>0)
                for(int j=0; j<3; j++) {
                    next=cur;
                    if(i==j) continue;///不能倒给自已
                    if(next.v[i]+next.v[j]>a[j]) {
                        next.v[i]-=a[j]-next.v[j];///装满另一个杯子还有多
                        next.v[j]=a[j];///杯子满了
                    }
                    else {
                        next.v[j]+=next.v[i];///还没满或刚好满
                        next.v[i]=0;///全倒完
                    }
                    if(!hash[next.v[1]][next.v[2]]) {///这种状态没有出现过
                        hash[next.v[1]][next.v[2]]=1;
                        next.step++;
                        q.push(next);
                    }
                }
    }
    printf("NO\n");
}

int main() {
    while(~scanf("%d%d%d",&a[0],&a[1],&a[2]),a[0]||a[1]||a[2]) {
        if(a[0]%2) {///因为三个杯子容量都是整数
            puts("NO"); continue;
        }
        if(a[1]==a[2]) {///刚好平分
            puts("1"); continue;
        }
        BFS();
    }
    return 0;
}