#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 1000 + 10;
const int maxm = 9 + 5;

int w, h, A, D;
long long Y;
int Q[maxn], P[maxn], N[maxn], M[maxn];
int num[maxm];      //num[i]表示9个格子中占了i个有效格子的种子数
int remain[maxm];       //remain[i]表示在种植了其中的一些种子后，剩余空地中9个格子中占了i个有效格子的种子数
int harvestGrid[maxn];      //harvestGrid[i]表示i天后有收获的土地格子数
int blank[maxn];        //blank[i]表示第i天有多少空地可以种植
int p;      //一个种子，尽量种在占格子尽量多的地方
int now;        //现在是第几天

void read(){
    scanf("%d%d%d%d%I64d", &w, &h, &A, &D, &Y);
    for(int i = 1; i <= A; i++) scanf("%d%d%d%d", &Q[i], &P[i], &N[i], &M[i]);
}

void init(){
    memset(num, 0, sizeof(num));
    num[9] = (w/3) * (h/3);     //左上方
    int ww = w % 3, hh = h % 3;
    num[9-(3-ww)*(3-hh)]++;     //右下角
    num[3*hh] += w/3 - 1;       //左下方
    num[3*ww] += h/3 - 1;       //右上角
    num[ww*hh] += 2;        //左下方与右下角中间的部分和右上角与右下角之间的部分
}

bool isok(int x){       //判断这种种子是否值得购买
    if(!M[x]) return (long long)P[x] * p > Q[x] ? 1 : 0;      //时间要够，要能赚钱
    else return (long long)(1 + (D - now - N[x]) / M[x]) * p * P[x] > Q[x] ? 1 : 0;        //时间不够的话求出的是非正数，一样可以判
}

long long work(int x, long long money){
    if(D - now < N[x]) return money;        //时间不够，直接返回
    while(p >= 1){
        if(!isok(x)){       //看看是否应该买种子
            p = 0;      //没有收获的话，不用再往下扫描，因为格子越少，赚得越少，下面的一定赚不了
            break;
        }
        //最终有收获，该买
        int numOfBuy = (remain[p] < money / Q[x]) ? remain[p] : money / Q[x];        //能买到的种子的个数
        remain[p] -= numOfBuy;      //剩余空地减少
        money -= Q[x] * numOfBuy;       //用去了一部分钱
        harvestGrid[now+N[x]] += numOfBuy * p;      //更新那些可以收获的日子
        blank[now+N[x]] += numOfBuy;        //那天会新空出numOfBuy的空地，是值得种植并且能够种植的（赚的钱比原来的成本更多了）（在时间允许下）
        if(!remain[p]) p--;
        else break;     //没钱了
    }
    return money;
}

long long cal(int x){
    memset(harvestGrid, 0, sizeof(harvestGrid));        //初始时没种种子，哪一天都没有收获
    memcpy(remain, num, sizeof(num));       //初始时所有空地都没种种了，故remain == num
    memset(blank, 0, sizeof(blank));        //初始化
    p = 9;
    now = 0;
    long long money = work(x, Y);        //第一次购买完种子后剩下的钱
    for(now = 1; now <= D; now++){      //模拟D天的收获
        if(!harvestGrid[now]) continue;
        money += harvestGrid[now] * P[x];      //可以收获的话
        if(!M[x] && D - now >= N[x]){       //在时间足够的前提下，将刚刚收获的土地继续种植
            money -= Q[x] * blank[now];       //用去了一部分钱
            harvestGrid[now+N[x]] += harvestGrid[now];      //更新那些可以收获的日子
            blank[now+N[x]] += blank[now];        //那天会新空出的空地，是值得种植并且能够种植的（赚的钱比原来的成本更多了）（在时间允许下）
        }
        else if(M[x] && D - now >= M[x]){        //在时间足够的前提下，将刚刚收获的土地继续收获
            harvestGrid[now+M[x]] += harvestGrid[now];      //更新那些可以收获的日子
        }
        money = work(x, money);
    }
    return money;
}

void solve(){
    long long Max = -1;
    for(int i = 1; i <= A; i++) Max = max(Max, cal(i));
    printf("%I64d\n", Max);
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        read();
        init();
        solve();
    }
    return 0;
}
