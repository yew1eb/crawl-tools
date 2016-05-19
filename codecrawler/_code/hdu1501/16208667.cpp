/*åæ:å¯¹äºå­ç¬¦ä¸²a,b,cï¼ç±äºcçé¿åº¦ä¸å®æ¯aåbçé¿åº¦ä¹å,æä»¥å¯¹äºç¨cå¹éa,bå°ä½ç½®i,j
èå¹éå°i,jçæ¹å¼å¯è½å¾å¤,ä½æ¯ä¸ç®¡æä¹å¹éå°i,jç,cå©ä½çå­ç¬¦ä¸æ ·,a,bå©ä½çä¹ä¸æ ·,
æä»¥i,jåçå¹éç»æä¸æ · 
æä»¥å¯ä»¥è®°å¿åæç´¢é²æ­¢éå¤å»æ±å¹éi,jåçç»æ
mark[i][j]è®°å¿a,bå¨i,jåçå¹éæåµ,0è¡¨ç¤ºæ²¡å¹é,1è¡¨ç¤ºå¹éæå,2è¡¨ç¤ºå¹éä¸æå 
*/
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

const int MAX=200+10;
char a[MAX],b[MAX],c[2*MAX];
int mark[MAX][MAX];

int dfs(int i,int j,int k){
    if(mark[i][j])return mark[i][j];
    if(c[k] == '\0')return 1;
    mark[i][j]=2;//2è¡¨ç¤ºè®¿é®è¿ä½æ¯ä¸å­å¨ 
    if(a[i] == c[k])mark[i][j]=dfs(i+1,j,k+1);
    if(b[j] == c[k] && mark[i][j] != 1)mark[i][j]=dfs(i,j+1,k+1);//1è¡¨ç¤ºè®¿é®è¿ä¸å­å¨ 
    return mark[i][j];
}

int main(){
    int t,num=0;
    scanf("%d",&t);
    while(t--){
        scanf("%s%s%s",a,b,c);
        memset(mark,0,sizeof mark);
        if(dfs(0,0,0) == 1)printf("Data set %d: yes\n",++num);
        else printf("Data set %d: no\n",++num);
    }
    return 0;
}