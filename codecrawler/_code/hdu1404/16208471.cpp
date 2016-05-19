#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
int sg[1000010];
int dfs(int k){
    if(sg[k]!=-1)return sg[k];
    int i,kk;
    for(i=1;i<=k;i*=10){
        if(k/i%10){
            kk=k;
            do{
                kk-=i;
                if(kk<i)break;
                if(!sg[kk])return sg[k]=1;
            }while(kk/i%10);
        }
        else if(!sg[k/i/10])return sg[k]=1;
    }
    return sg[k]=0;
}

int main(){
    char s[10];
    int i,sum;
    memset(sg,-1,sizeof(sg));
    sg[0]=1;
    for(i=1;i<1000010;i++)
        dfs(i);
    while(~scanf("%s",s)){
        if(s[0]=='0'){
            puts("Yes");
            continue;
        }
        sum=0;
        for(i=0;s[i];i++){
            sum*=10;
            sum+=s[i]-'0';
        }
        puts(sg[sum]?"Yes":"No");
    }
    return 0;
}
