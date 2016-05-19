#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#define maxn 100+5
#define maxlen 50+5
int n;
char str[maxn][maxlen];
int toX[maxn][maxlen][maxn];
int toY[maxn][maxlen][maxn];
int need[maxn][maxlen][maxn];
int len[maxn];
using namespace std;
void check(){
    for(int i = 0; i < n; i++){
        len[i] = strlen(str[i]);
    }
    for (int i = 0; i < n; i++){
        for (int j = 1; j <= len[i]; j++){
            for (int k = 0; k < n; k++){
                if(j == len[i] && i == k){//如果str[k]就是str[i]本身
                    toX[i][j][k] = -1;
                }
                else if(memcmp(str[i] + len[i] - j, str[k], min(j, len[k])) == 0){
                    toX[i][j][k]  = j > len[k] ? i : k;
                    toY[i][j][k] = fabs(j - len[k]);
                    need[i][j][k] = j > len[k] ? 0 : len[k] - j;
                }
                else  toX[i][j][k]  = -1;
            }
        }
    }
}
const int maxq = (maxn) * (maxlen) * 10;
int q[maxq],begin,end;
int dis[maxn][maxlen];
bool inq[maxn][maxlen];
void spa(){
    begin = 0;
    end = 0;
    memset(dis, 0x3f, (sizeof(dis)));
    memset(inq, 0, sizeof(inq));
    for(int i = 0; i < n; i++){
        q[end++] = i;
        q[end++] = len[i];
        dis[i][len[i]] = len[i];
        inq[i][len[i]] = true;
    }
    while(begin != end){
        int x = q[begin++];
        int y = q[begin++];
        if (begin == maxq)  begin = 0;
        inq[x][y] = false;
        for(int i = 0; i < n; i++){
            if(toX[x][y][i] != -1){
                int xx = toX[x][y][i];
                int yy = toY[x][y][i];
                int ll = need[x][y][i];
                if(dis[xx][yy] > dis[x][y] + ll){//如果dis[xx][yy]还没有求出来
                    dis[xx][yy] = dis[x][y] + ll;
                    if(!inq[xx][yy]){
                        q[end++] = xx;
                        q[end++] = yy;
                        if(end == maxq){
                            end = 0;
                        }
                        inq[xx][yy] = true;//标记inq[xx][yy]在队列中
                    }
                }
            }
        }
    }
}
void output(){
    int ans = 0x3f000000;
    for(int i = 0; i < n; i++){
        if(ans > dis[i][0]){
            ans = dis[i][0];
        }
    }
    printf("%d\n", ans >= 0x30000000 ? -1 : ans);
}
int main(){
        while(scanf("%d", &n), n){
            for (int i = 0; i < n; i++){
                scanf("%s", str[i]);
            }
        /*判断每一个字符串的最后的每一位可以用哪一个字符串的前几位接上，记下最后的几位是属于哪个
        字符串（toX来储存），相对多出了几位（用toY来储存）， 需要在当前的字符串后面加上几位才能、
        得到新串（need来储存）*/
        check();
        /*枚举出所有在末尾加字符串后的结果*/
        spa();
        output();
        }
}