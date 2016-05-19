#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 102;

int p[MAX],m[MAX],ans[MAX*MAX],tmp[MAX*MAX];
int n;

void work(int aim){
    int i,j,k;

    memset(ans,0,sizeof(ans));
    memset(tmp,0,sizeof(tmp));

    for(i=0;i<=m[0] && i*p[0]<=aim;++i){
        ans[i*p[0]] = 1;
    }

    //(author : CSDN iaccepted)
    for(i=1;i<n;++i){
        for(j=0;j<=aim;++j){
            for(k=0;k<=m[i] && k*p[i]+j<=aim;++k){
                tmp[j+k*p[i]] += ans[j];
                tmp[j+k*p[i]] %= 10000;
            }
        }
        for(j=0;j<=aim;++j){
            ans[j] = tmp[j];
            tmp[j] = 0;
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    //(author : CSDN iaccepted)
    int i,all;
    while(scanf("%d",&n)!=EOF){
        if(n==0)break;
        all = 0;
        for(i=0;i<n;++i){
            scanf("%d %d",&p[i],&m[i]);
            all += (p[i] * m[i]);
        }
        if(all%3!=0){
            printf("sorry\n");
            continue;
        }
        all /= 3;
        work(all);
        if(ans[all]!=0){
            printf("%d\n",ans[all]);
        }else{
            printf("sorry\n");
        }
    }
    return 0;
}



