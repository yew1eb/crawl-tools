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

const int MAX=1001;
int sum[MAX][2],**s;//sum[i][]è®°å½ä»¥ç¬¬iä¸ªåç´ ä¸ºæååç´ çæé¿å­åºåçé¿åº¦åè¯¥åç´ åä¸ä¸ªåç´  

bool cmp(int *a,int *b){
    if(a[0] == b[0])return a[1]>b[1];
    return a[0]<b[0];
}

void DFS_output(int i){
    if(sum[i][1] == i){
        cout<<s[i][2]+1<<endl;
        return;
    }
    DFS_output(sum[i][1]);
    cout<<s[i][2]+1<<endl;
}

int main(){
    int n=0,k;
    s=new int*[MAX];
    for(int i=0;i<MAX;++i)s[i]=new int[3];
    while(cin>>s[n][0]>>s[n][1]){s[n][2]=n;++n;}
    sort(s,s+n,cmp);
    for(int i=0;i<n;++i){
        k=i;
        for(int j=0;j<i;++j){
            if(s[i][1]<s[j][1] && s[i][0]>s[j][0] && sum[j][0]>sum[k][0])k=j;
        }
        sum[i][0]=sum[k][0]+1;
        sum[i][1]=k;
    }
    k=0;
    for(int i=1;i<n;++i)if(sum[i][0]>sum[k][0])k=i;
    cout<<sum[k][0]<<endl;
    DFS_output(k);
    return 0;
}