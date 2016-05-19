/************************************************
 * By: chenguolin                               * 
 * Date: 2013-08-21                             *
 * Address: http://blog.csdn.net/chenguolinblog *
 ***********************************************/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN = 1010;

int m;
int num[MAXN][MAXN];
int treeNum[MAXN][MAXN];

int lowbit(int x){
    return x&(-x);
}

int getSum(int x , int y){
    int sum = 0;
    for(int i = x ; i > 0 ; i -= lowbit(i))
        for(int j = y ; j > 0 ; j -= lowbit(j))
            sum += treeNum[i][j];
    return sum;
}

void add(int x , int y , int val){
    for(int i = x ; i < MAXN ; i += lowbit(i))
        for(int j = y ; j < MAXN ; j += lowbit(j))
            treeNum[i][j] += val;
}

void solve(){
    memset(num , 0 , sizeof(num));
    memset(treeNum , 0 , sizeof(treeNum));
    char c;
    int x , y , val;
    int x1 , x2 , y1 , y2;
    int x3 , x4 , y3 , y4;
    while(m--){
         scanf("%c" , &c); 
         if(c == 'B'){
             scanf("%d%d%*c" , &x , &y);
             x++ , y++;
             val = num[x][y] ? 0 : 1;
             if(val)
                 add(x , y , val);
             num[x][y] = 1;
         }
         else if(c == 'D'){
             scanf("%d%d%*c" , &x , &y);
             x++ , y++;
             if(num[x][y])
                add(x , y , -1);
             num[x][y] = 0;
         }
         else{
             scanf("%d%d" , &x1 , &x2);
             scanf("%d%d%*c" , &y1 , &y2);
             x1++ , x2++ , y1++ , y2++;
             x3 = min(x1 , x2) , y3 = min(y1 , y2);
             x4 = max(x1 , x2) , y4 = max(y1 , y2);
             int ans = getSum(x4 , y4);
             ans -= getSum(x3-1 , y4);
             ans -= getSum(x4 , y3-1);
             ans += getSum(x3-1 , y3-1);
             printf("%d\n" , ans);
         }
    }
}

int main(){
    while(scanf("%d%*c" , &m) != EOF)
          solve(); 
    return 0;
}