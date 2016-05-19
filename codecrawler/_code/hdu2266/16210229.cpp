#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <stack>
#include <deque>
#include <vector>
#include <set>
#include <map>
using namespace std;
typedef __int64 ll;
#define MAXN 15
char s[MAXN];
ll n;
int len;
int ans;

void DFS(int pos,int sum){
    if(pos==len && sum==n){
        ans++;
        return ;
    }
    ll tmp=0;
    int i;
    for(i=pos;i<len;i++){
        //tmp = tmp*10+(s[i]-'0');
        tmp=tmp*(ll)10+s[i]-'0';
        DFS(i+1,tmp+sum);
        if(pos!=0){
            DFS(i+1,sum-tmp);
        }
    }
}

int main(){
    int i;

    while(~scanf("%s",s)){
        scanf("%I64d",&n);
        len = strlen(s);
        ans = 0;
        DFS(0,0);
        cout<<ans<<endl;
    }

    return 0;
}
