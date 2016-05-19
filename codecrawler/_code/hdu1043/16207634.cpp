#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
#include<map>
#include<string>
#define inf 1<<30
#define eps 1e-7
#define LD long double
#define LL long long
#define maxn 1000000005
using namespace std;
struct Node{
    int maze[3][3];   //å«æ°ç å·ä½æåµ 
    int h,g;    //ä¸¤ä¸ªä¼°ä»·å½æ°
    int x,y;   //ç©ºä½çä½ç½®
    int Hash;   //HASHå¼
    bool operator<(const Node n1)const{     //ä¼åéåç¬¬ä¸å³é®å­ä¸ºh,ç¬¬äºå³é®å­ä¸ºg
        return h!=n1.h?h>n1.h:g>n1.g;
    }
    bool check(){    //å¤æ­æ¯å¦åæ³
        if(x>=0&&x<3&&y>=0&&y<3)
            return true;
        return false;
    }
}s,u,v,tt;
int HASH[9]={1,1,2,6,24,120,720,5040,40320};   //HASHçæå¼
int destination=322560;   //ç®æ æåµçHASHå¼
int vis[400000];            //å¤æ­ç¶æå·²éåï¼åå§ä¸º-1ï¼å¦åä¸ºå°è¾¾è¿æ­¥çè½¬å
int pre[400000];        //è·¯å¾ä¿å­
int way[4][2]={{0,1},{0,-1},{1,0},{-1,0}};   //åä¸ªæ¹å
void debug(Node tmp){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
            printf("%d ",tmp.maze[i][j]);
        printf("\n");
    }
    printf("%d %d\n%d %d\n",tmp.x,tmp.y,tmp.g,tmp.h);
    printf("hash=%d\n",tmp.Hash);
}
int get_hash(Node tmp){    //è·å¾HASHå¼
    int a[9],k=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            a[k++]=tmp.maze[i][j];
    int res=0;
    for(int i=0;i<9;i++){
        int k=0;
        for(int j=0;j<i;j++)
            if(a[j]>a[i])
                k++;
        res+=HASH[i]*k;
    }
    return res;
}
bool isok(Node tmp){    //æ±åºéåºå¯¹ï¼å¤æ­æ¯å¦æè§£
    int a[9],k=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            a[k++]=tmp.maze[i][j];
    int sum=0;
    for(int i=0;i<9;i++)
        for(int j=i+1;j<9;j++)
            if(a[j]&&a[i]&&a[i]>a[j])
                sum++;
    return !(sum&1);    //ç±äºç®æ è§£ä¸ºå¶æ°ï¼æä»¥ç¶æçéåºæ°ä¸ºå¶æ°æå¯è¡
}
int get_h(Node tmp){   //è·å¾ä¼°ä»·å½æ°H
    int ans=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(tmp.maze[i][j])
                ans+=abs(i-(tmp.maze[i][j]-1)/3)+abs(j-(tmp.maze[i][j]-1)%3);
    return ans;
}
void astar(){    //æç´¢
    priority_queue<Node>que;
    que.push(s);
    while(!que.empty()){
        u=que.top();
        que.pop();
        for(int i=0;i<4;i++){
            v=u;
            v.x+=way[i][0];
            v.y+=way[i][1];
            if(v.check()){
                swap(v.maze[v.x][v.y],v.maze[u.x][u.y]);   //å°ç©ºä½åç¸é»ä½äº¤æ¢
                v.Hash=get_hash(v);                //å¾å°HASHå¼
                if(vis[v.Hash]==-1&&isok(v)){   //å¤æ­æ¯å¦å·²éåä¸æ¯å¦å¯è¡ï¼åèå¯ä»¥ä¸è¦
                    vis[v.Hash]=i;           //ä¿å­æ¹å
                    v.g++;;                  //å·²è±ä»£ä»·+1
                    pre[v.Hash]=u.Hash;     //ä¿å­è·¯å¾
                    v.h=get_h(v);           //å¾å°æ°çä¼°ä»·å½æ°H
                    que.push(v);     //å¥é
                }
                if(v.Hash==destination)
                    return ;
            }
        }
    }
}
void print(){
    string ans;
    ans.clear();
    int nxt=destination;
    while(pre[nxt]!=-1){  //ä»ç»ç¹å¾èµ·ç¹æ¾è·¯å¾
        switch(vis[nxt]){   //åä¸ªæ¹åå¯¹åº
        case 0:ans+='r';break;
        case 1:ans+='l';break;
        case 2:ans+='d';break;
        case 3:ans+='u';break;
        }
        nxt=pre[nxt];    
    }
    for(int i=ans.size()-1;i>=0;i--)
        putchar(ans[i]);
    puts("");
}
int main(){
    char str[100];
    while(gets(str)!=NULL){
        int k=0;
        memset(vis,-1,sizeof(vis));
        memset(pre,-1,sizeof(pre));
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++){
                if((str[k]<='9'&&str[k]>='0')||str[k]=='x'){
                    if(str[k]=='x'){
                        s.maze[i][j]=0;
                        s.x=i;
                        s.y=j;
                    }
                    else
                        s.maze[i][j]=str[k]-'0';
                }
                else
                    j--;
                k++;
            }
        if(!isok(s)){   //èµ·å§ç¶æä¸å¯è¡
            printf("unsolvable\n");
            continue;
        }
        s.Hash=get_hash(s);
        if(s.Hash==destination){   //èµ·å§ç¶æä¸ºç®æ ç¶æ
            puts("");
            continue;
        }
        vis[s.Hash]=-2;
        s.g=0;s.h=get_h(s);
        astar();
        print();
    }
    return 0;
}