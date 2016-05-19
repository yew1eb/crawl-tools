#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define LL unsigned long long
using namespace std;
int n,m;
int way[4][2]={{0,1},{0,-1},{1,0},{-1,0}};   //BFSåä¸ªæ¹å
char mmap[10][10];                           //åå§å°å¾
int wallcnt,wallmap[10][10];                 //åå§å°å¾ä¸å¢çæ°éï¼ä»¥ååå¸å¾ï¼å¯¹äºæ¯ä¸ªå¢ç»ä¸ªç¼å·
int bombcnt,bombmap[10][10];                 //åå§å°å¾ä¸ç¸å¼¹çæ°éï¼ä»¥ååå¸å¾ï¼å¯¹äºæ¯ä¸ªç¸å¼¹ç»ä¸ªç¼å·
struct Node{
    int x,y,step,bomb;      //ä½ç½®ï¼æ­¥æ°ï¼å©ä½ç¸å¼¹
    LL vis;                 //å°å¾ä¸çç¸å¼¹å·²åæåµï¼1è¡¨ç¤ºæå¤ç¸å¼¹å·²å
    LL wall;                //å°å¾ä¸å©ä½å¢çæåµï¼1è¡¨ç¤ºæå¤è¿æå¢
    bool check(){           //å¤æ­æ¯å¦å¨å°å¾èå´å
        if(x>=0&&y>=0&&x<n&&y<m)
            return true;
        return false;
    }                       //ä¼åéå
    bool operator<(const Node n1) const{
        return step>n1.step;
    }
}s,e,u,v;                   
vector<Node>flag[8][8][8*8*9+1];   //å¤éï¼flag[x][y][z]è¡¨ç¤º å¨(x,y)å¤æä¸æzä¸ªç¸å¼¹æ¶çç¶æ
bool check(Node tmp){              //å¤æ­æ¯å¦åä¹åå·²å¥éçæåµç¸å
    for(int i=0;i<flag[tmp.x][tmp.y][tmp.bomb].size();i++)
        if(tmp.wall==flag[tmp.x][tmp.y][tmp.bomb][i].wall&&tmp.vis==flag[tmp.x][tmp.y][tmp.bomb][i].vis)    //ç»ç¹å©ä½çå¢æåµä»¥åç¸å¼¹æåµå®å¨ç¸å
            return false;
    return true;
}
int bfs(){
    priority_queue<Node>que;
    que.push(s);
    while(!que.empty()){
        u=que.top();
        que.pop();
        for(int i=0;i<4;i++){
            v=u;
            v.step++;
            v.x=u.x+way[i][0];
            v.y=u.y+way[i][1];
            if(v.check()){
                if(mmap[v.x][v.y]=='D')          //æ¾å°ç»ç¹
                    return v.step;
                if(mmap[v.x][v.y]=='X'&&((1LL<<wallmap[v.x][v.y])&v.wall)){    //æå¤åæ¥æ¯å¢ï¼èä¸ä¹æ²¡è¢«ç¸æ¯
                    if(v.bomb>0){    //æä¸æç¸å¼¹
                        v.bomb--;
                        v.step++;
                        v.wall^=(1LL<<wallmap[v.x][v.y]);    //æ è®°ä¸ï¼å·²ç»è¢«ç¸æ¯
                        que.push(v);                           //ç»ç¹å¥é
                        flag[v.x][v.y][v.bomb].push_back(v);   //ä¿å­ç¶æ
                    }    
                }  
                else if(mmap[v.x][v.y]>='1'&&mmap[v.x][v.y]<='9'&&(v.vis&(1LL<<bombmap[v.x][v.y]))==0){    //æå¤æ¯ç¸å¼¹ï¼èä¸ä¹åæ²¡æå
                    v.bomb+=mmap[v.x][v.y]-'0';             //åç¸å¼¹
                    v.vis|=(1LL<<bombmap[v.x][v.y]);         //æ è®°ç¸å¼¹å·²å
                    que.push(v);                              //ç»ç¹å¥é
                    flag[v.x][v.y][v.bomb].push_back(v);       //ä¿å­ç¶æ
                }
                else{
                    if(flag[v.x][v.y][v.bomb].empty()||check(v)){   //å½åæ²¡æç¶ææèåä¹åçç¶æé½ä¸ç¸å
                        flag[v.x][v.y][v.bomb].push_back(v);      //ä¿å­
                        que.push(v);         //å¥é
                    }
                }        
            }

        }
    }
    return -1;
}
int main(){
    while(scanf("%d%d",&n,&m)!=EOF&&n+m){ 
        for(int i=0;i<n;i++)           //å¤éåå§å
            for(int j=0;j<m;j++)
                for(int k=0;k<=(n*m*9);k++)
                    if(!flag[i][j][k].empty())
                        flag[i][j][k].clear();
        bombcnt=wallcnt=0;
        memset(wallmap,-1,sizeof(wallmap));
        memset(bombmap,-1,sizeof(bombmap));
        for(int i=0;i<n;i++){
            scanf("%s",mmap[i]);
            for(int j=0;j<m;j++)
                if(mmap[i][j]=='S'){            //èµ·ç¹æ è®°
                    s.x=i;
                    s.y=j;
                    s.step=0;
                    s.bomb=0;
                    s.vis=0;
                } 
                else if(mmap[i][j]=='X')           
                    wallmap[i][j]=wallcnt++;             //å¯¹äºæ¯ä¸ªå¢ç»ä¸ªç¼å·
                else if(mmap[i][j]>='1'&&mmap[i][j]<='9')
                    bombmap[i][j]=bombcnt++;           //å¯¹äºæ¯ä¸ªç¸å¼¹ä½ç½®ç»ä¸ªç¼å·
        }
        s.wall=(1LL<<wallcnt)-1;               //åå§åï¼ææå¢é½æ²¡æè¢«ç¸
        printf("%d\n",bfs());
    }
    return 0;
}
