#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN = 30010;

int n;
int father[MAXN];
int rank[MAXN];
int maxNum[MAXN];

void init(){
    memset(rank , 0 , sizeof(rank));
    memset(maxNum , 0 , sizeof(maxNum));
    for(int i = 0 ; i < MAXN ; i++)
        father[i] = i;
}

int find(int x){
    if(father[x] != x){
        int fa = father[x];
        father[x] = find(fa);
        rank[x] += rank[fa];
    }
    return father[x];
}

void Union(int x , int y){
    int fx = find(x);
    int fy = find(y);
    if(fx != fy){
        father[fx] = fy; 
        rank[fx] += maxNum[fy]+1;
        maxNum[fy] += maxNum[fx]+1;
    }
}

int main(){
    char c;
    int x , y;
    while(scanf("%d%*c" , &n) != EOF){
         init(); 
         while(n--){
              c = getchar();      
              if(c == 'M'){
                  scanf("%d%d%*C" , &x , &y);
                  Union(x , y);
              }
              else{
                  scanf("%d%*C" , &x);
                  find(x);
                  printf("%d\n" , rank[x]);
              }
         } 
    }
    return 0;
}