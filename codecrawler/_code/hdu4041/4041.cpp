/*
Pro: 0

Sol:

date:
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
#include <cmath>
#include <queue>
#include <set>
#include <vector>
using namespace std;
char str[1000010],tmp[15];
char name[50010][12];
void solve(){
    stack <int> ss;
    queue <int> qq;
    scanf("%s",str);
    int len = strlen(str);  int j = 0, people = 0;
    for(int i = 0; i <= len;i ++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            tmp[j ++] = str[i];
        }else{
            if(j != 0 || str[j] == '\0'){
                tmp[j ++] = '\0';
                strcpy(name[people ++],tmp);
                j = 0;
            }
            if(str[i] == '('){
               ss.push(people);
               qq.push(people);
            }else if(str[i] == ','){
                if(str[i - 1] != ')'){
                    qq.push(people);
                }
                qq.push(ss.top());
            }else if(str[i] == ')'){
                if(str[i - 1] != ')'){
                    qq.push(people);
                }//从这个点回到父亲节点
                qq.push(ss.top());//回到父亲节点
                ss.pop();
            }
        }
    }
    printf("%d\n",people);
    for(int i = 0; i < people; i ++)
        printf("%s\n",name[i]);
    if(qq.size() == 1) return ;
    while(!qq.empty()){
        printf("%d ",qq.front());
        qq.pop();
        printf("%d\n",qq.front());
        if(qq.size() == 1) break;
    }
}
int main(){
    int t;  scanf("%d",&t);
    for(int ca = 1; ca <= t; ca ++){
        solve();
        puts("");
    }
	return 0;
}
