/*
ID:cxlove
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#define LL unsigned long long
using namespace std;
int n,m,T;
int way[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int str[10][10];
struct Node{
    int x,y,step;
    int mmap[10][10];
    bool check(){
        if(x>=0&&x<n&&y>=0&&y<m)
            return true;
        return false;
    }
}s,e,u,v,ss,ee,uu,vv;
bool bfs_people(Node n1){   //æç´¢äººæ¯å¦è½å°è¾¾æå®ä½ç½®
    queue<Node>que;
    ss=n1;
    bool flag[10][10];
    memset(flag,false,sizeof(flag));
    for(int i=0;i<n;i++){   //æ¾å°äººçèµ·ç¹
        for(int j=0;j<m;j++)            
            if(n1.mmap[i][j]==4){
                ss.x=i;
                ss.y=j;
                ss.step=0;
            }
    }
    if(ss.x==ee.x&&ss.y==ee.y)
        return true;
    que.push(ss);
    flag[ss.x][ss.y]=true;
    while(!que.empty()){
        uu=que.front();
        que.pop();
        for(int i=0;i<4;i++){
            vv=uu;
            vv.step++;
            vv.x+=way[i][0];
            vv.y+=way[i][1];
            if(vv.check()&&flag[vv.x][vv.y]==false&&(n1.mmap[vv.x][vv.y]!=1&&n1.mmap[vv.x][vv.y]!=2)){ //ç®æ ç¹ä¸æ¯å¢ä¹ä¸æ¯ç®±å­
                flag[vv.x][vv.y]=true;
                if(vv.x==ee.x&&vv.y==ee.y)
                    return true;
                que.push(vv);
            }
        }
    }
    return false;
}
int bfs_box(){ //æç´¢ç®±å­
    int flag[10][10][4];
    queue<Node>que;
    que.push(s);
    memset(flag,false,sizeof(flag));
    while(!que.empty()){
        u=que.front();
        que.pop();
        for(int i=0;i<4;i++){
            v=u;
            v.x+=way[i][0];
            v.y+=way[i][1];
            v.step++;
            if(v.check()&&str[v.x][v.y]!=1&&flag[v.x][v.y][i]==false){
                //äººçç®æ ä½ç½®
                ee.x=u.x-way[i][0];
                ee.y=u.y-way[i][1];
                if(ee.check()==false)
                    continue;
                if(bfs_people(v)){
                    //æ´æ°å°å¾ï¼ç®±å­åäººçä½ç½®
                    swap(v.mmap[v.x][v.y],v.mmap[u.x][u.y]);
                    swap(v.mmap[ee.x][ee.y],v.mmap[ss.x][ss.y]);
                    flag[v.x][v.y][i]=true;
                    if(str[v.x][v.y]==3)
                        return v.step;
                    que.push(v);
                }
            }
        }
    }
    return -1;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                scanf("%d",&str[i][j]);
                s.mmap[i][j]=str[i][j];
                if(str[i][j]==2){   //æ æ³¨ç®±å­èµ·ç¹
                    s.x=i;
                    s.y=j;
                    s.step=0;
                }
            }
            printf("%d\n",bfs_box());
    }
    return 0;
}