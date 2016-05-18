//125MS	408K	1718B	C++

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<sstream>

#define max(a,b) a>b?a:b
using namespace std;
int n; 
int f[20],dp[16][1666];
int X[1666], Y[1666], num[1666];
// X[i]: 某行中取数状态,其下一行不能取的位置都标为1 (状态X)
// Y[i]: 取数的状态,将被取数的位置标1 (状态Y)
int len,a[20];  
void DFS(int k,int t,int c){
    if(c==t) {
        int u=0,v=0;   // u: 取了数的位置及左右两位置标1;   V: 取了数的位置标1
        for(int i=1;i<=t;++i)
            if(a[i]){
                v|=(1<<(i-1));  
                u|=(1<<(i-1));
                u|=(1<<i);
                if(i>1) u|=(1<<(i-2));
            }
            X[len]=u, Y[len]=v; ++len;
        return ;
    }
    for(int i=0;i<2;++i){
        if(i&&a[k-1]) continue;
        a[k]=i;
        DFS(k+1,t,c+1);
    }
}
int work(int x){                  // 计算某一状态在一行中取数的和
    int ret=0,i=1;
    while(x){
        if(x&1)ret+=f[i];
        x>>=1; ++i;
    }
    return ret;
}
void Init(char* ch){
    char x[10];
    stringstream in(ch);          // 截取空格分开的子串, 即提取每个整数
    n=len=0;                      // len状态种数
    while(in>>x) f[++n]=atoi(x);  // 把串转为整形
    DFS(1,n,0);
    memset(dp,0,sizeof(dp));
    for(int j=0; j<len; ++j)
        dp[1][j]=work(Y[j]);      // 第一行的状态Y做为dp方程初始化
}
int main(){
    char ch[150];
    while(gets(ch)!=NULL){
        Init(ch);
        int ans=0;
        for(int i=2;i<=n;++i){
            for(int j=1;j<=n;++j)
                scanf("%d",f+j);
            for(int j=0;j<len;++j)
                num[j]=work(Y[j]);     // num[j]: 第j种状态Y, 在i行取数的和
            for(int j=0; j<len; ++j)
                for(int k=0; k<len; ++k)
                    if(!(Y[j]&X[k])) { //用i行的状态Y匹配i-1行的状态X 等于0为可行
                        dp[i][j]=max(dp[i][j],dp[i-1][k]+num[j]);
                        ans=max(dp[i][j],ans);
                    }
        }
        printf("%d\n",ans); 
        getchar(); 
        getchar();
    }
}