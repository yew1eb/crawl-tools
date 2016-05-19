#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 1002
char w[maxn];
int num[maxn];

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",w);
        int len = strlen(w);
        for(int i = 0;i < len; i++)
            if(w[i] == ')') num[i] = 0;
            else num[i] = 1;
        for(int i= 1;i < len; i++)
            num[i] = num[i]+num[i-1];
        int ans = len-num[len-1];
        for(int i = 0 ;i < len ;i++){
            ans = min(ans,num[i]+len-1-i-num[len-1]+num[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
