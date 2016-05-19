#include <cstdio>
#include <bitset>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAX = 1010;

int T,k,N,num;
bitset<MAX> key[MAX];

int main(void)
{
    //freopen("input.txt","r",stdin);
    int cas = 1;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        for(int i = 0; i < N; ++i){
            key[i].reset();
            key[i][i] = true;
        }
        for(int i = 0; i < N; ++i){
            scanf("%d", &k);
            for(int j = 0; j < k; ++j){
                scanf("%d", &num);
                key[i][num-1] = true;
            }
        }

        for(int j = 0; j < N; ++j)
            for(int i = 0; i < N; ++i)
                if(key[i][j])
                    key[i] |= key[j];


        double ans = 0.0;
        for(int j = 0; j < N; ++j){
            int cnt = 0;
            for(int i = 0; i < N; ++i)
                if(key[i][j]) cnt++;
            ans += 1.0 / cnt;
            //printf("%f\n",ans);
        }

        printf("Case #%d: %.5f\n",cas++,ans);
    }
    return 0;
}

