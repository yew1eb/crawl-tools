#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=15+10;
int s[MAX][MAX],sum,n;
bool mark[MAX];

void dfs(int id,int num,int sorce){
    for(int i=0;i<n;++i){
        if(mark[i] || s[id][i]<sorce)continue;
        mark[i]=true;
        dfs(i,num+1,s[id][i]);
        mark[i]=false;
    }
    sum=max(sum,num);
}

int main(){
    while(cin>>n){
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j)cin>>s[i][j];
        }
        memset(mark,false,sizeof mark);
        sum=0;
        mark[0]=true;
        dfs(0,1,0);
        cout<<sum<<endl;
    }
    return 0;
}