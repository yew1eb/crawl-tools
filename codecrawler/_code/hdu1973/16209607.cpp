#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int MAX_ = 10001;

bool vis[MAX_], v[MAX_];
int pri[MAX_];
int M,n,k;

void prime(){
    for(int i = 2; i < MAX_; ++i){
        if(!vis[i]){
            pri[M++] = i;
        }
        for(int j = 0; j < M && i * pri[j] < MAX_; ++j){
            vis[i * pri[j]] = 1;
            if(i % pri[j] == 0)break;
        }
    }
}

void bfs(){
    queue<int >q;
    int f[4];
    memset(v,0,sizeof(v));
    q.push(n);
    q.push(0);
    while(!q.empty()){
        int cur = q.front(), step;
        q.pop();
        step = q.front();
        q.pop();
        if(cur == k){
            cout<<step<<endl;
            return ;
        }
        f[3] = cur % 10;
        f[2] = (cur /10)%10;
        f[1] = (cur/100)%10;
        f[0] = cur /1000;

        for(int i = 0; i < 4; ++i){
            int tmp = f[i];
            for(int j = 0; j < 10; ++j){
                if(j == tmp)continue;
                f[i] = j;
                int cnt = 0;
                for(int k = 0; k < 4; ++k){
                    cnt = cnt * 10 + f[k];
                }
                if(cnt < 1000)continue;
                if(!vis[cnt] && !v[cnt]){
                    //cout<<"cnt="<<cnt<<endl;
                    v[cnt] = 1;
                    q.push(cnt);
                    q.push(step + 1);
                }
            }
            f[i] = tmp;
        }
    }
    cout<<"Impossible"<<endl;
}


int main() {
    int T, sum;
    M = 0;
    prime();
    cin>>T;
    while(T--) {
        cin>>n>>k;
        bfs();

    }
    return 0;
}
