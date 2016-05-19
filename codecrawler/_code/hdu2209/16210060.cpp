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

const int MAX=20+10;
char s[MAX];
int p[MAX];

int dfs(int i,int len,int num){
    if(i == len)return p[i-1]?INF:num;
    if(p[i-1])p[i-1]=0,p[i]=!p[i],p[i+1]=!p[i+1],++num;
    return dfs(i+1,len,num);
}

int main(){
    while(cin>>s){
        int len=strlen(s);
        for(int i=0;i<len;++i)p[i]=s[i]-'0';
        int sum=INF;
        p[0]=!p[0],p[1]=!p[1];
        sum=min(sum,dfs(1,len,1));//ç¿»è½¬ç¬¬ä¸ä½ 
        for(int i=0;i<len;++i)p[i]=s[i]-'0';
        sum=min(sum,dfs(1,len,0));//ä¸ç¿»è½¬ç¬¬ä¸ä½ 
        if(sum == INF)cout<<"NO"<<endl;
        else cout<<sum<<endl;
    }
    return 0;
}