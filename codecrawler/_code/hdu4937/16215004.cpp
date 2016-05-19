#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<list>
#include<map>
#include<set>
using namespace std;
typedef long long LL;

LL n;
int cnt[6];
vector<LL>res;

void  deal_1(){

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
           LL base = (n - cnt[j]) / cnt[i];
//           printf("base= %lld cnt[i]= %d cnt[j]= %d\n",base,cnt[i],cnt[j]);
//           cout << base * cnt[i] + cnt[j] << endl;
           LL tp = base * cnt[i] + cnt[j];
           if(base > cnt[i] && base > cnt[j] && n == tp) res.push_back(base);
        }
    }
//    printf("size=%d\n",res.size());
}

void Push(LL a, LL b, LL c, LL fi){
    LL tp = -b + fi;
    LL base = tp / 2 / a;
    tp = a * base * base + b * base + c;
    if(base > a && base > b && base > c && tp == n)
        res.push_back(base);
}

void deal_2(){
    for(int i = 0 ; i < 4; i++)
        for(int j = 0; j < 4; j++)
           for(int k = 0; k < 4; k++){
                LL dt = 1LL * cnt[j] * cnt[j] - 1LL * 4 *cnt[i] *(cnt[k] - n);
                if(dt < 0) continue;
                dt = (LL)sqrt(dt);
                Push(cnt[i], cnt[j], cnt[k], dt);
                Push(cnt[i], cnt[j], cnt[k], -dt);
           }
}

bool OK(LL x){
    if(x == 3 || x == 4 || x == 5 || x == 6) return 1;
    return 0;
}
bool check(int base){
    LL x = n;
    LL tp;
    while(x){
        tp = x / base;
        LL u = x - tp * base;
        if(base <= u || OK(u)==0) return 0;
        x = tp;
    }
    return 1;
}
LL work(){
    if(n > 0 && n < 10){
        if(OK(n)) return -1;
        else return 0;
    }
    res.clear();
    deal_1();
    deal_2();

    for(int base = 4; base <= 7000; base++){
        if(check(base))
            res.push_back(base);
    }
    sort(res.begin(), res.end());
    return unique(res.begin(), res.end()) - res.begin();
}
int main()
{

//    freopen("in.in","r",stdin);
    for(int i = 0; i < 4; i++)
        cnt[i] = i + 3;

    int T;
    scanf("%d",&T);
    for(int ca = 1; ca <= T; ca ++){
        cin >> n;
        printf("Case #%d: ",ca);
        cout << work() << endl;
    }

    return 0;
}



