#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define N 32001

int C[N];
int num[N];
int T;

int Lowbit(int x){
    return x&(x^(x-1));
}

void add(int pos,int num) {
    while(pos <= N) {//xæå¤§æ¯N
        C[pos] += num;
        pos += Lowbit(pos);
    }
}

int Sum(int end) {
    int sum = 0;
    while(end > 0) {
        sum += C[end];
        end -= Lowbit(end);
    }
    return sum;
}

int main() {
    int s, t, i, j, T;
    while(~scanf("%d",&T)) {
        memset(C,0,sizeof(C));
        memset(num,0,sizeof(num));
        for(j = 1; j <= T; j ++) {
            scanf("%d%d",&s,&t);
            num[Sum(s+1)]++;
            add(s+1,1);
        }
        for(i = 0; i < T; i ++){
            printf("%d\n",num[i]);
        }


    }
    return 0;
}
