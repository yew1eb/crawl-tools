#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>


const int MAX = 9;

int dir[4][2]={1,0,-1,0,0,1,0,-1};

int map[MAX][MAX],step[MAX][MAX],time[MAX][MAX];
int n,m,sx,sy,dx,dy,minx;

void dfs(int x,int y,int len,int cnt){
    if(x<0 || y<0 || x>=n || y>=m)return;
    if(len<=0 || cnt>=minx)return;
    if(map[x][y]==0)return;
    if(map[x][y]==3){
        if(cnt<minx)minx=cnt;
        return;
    }
    if(map[x][y]==4){
        len=6;
    }
    //ä¸é¢çè¿ä¸ªåªæå¾éè¦ï¼ä¸åªå°±ä¼è¶æ¶
    //ä»å½åç¹xï¼yèµ°å°ä¸ä¸ä¸ªå¯è½ç¹çè·ç¦»å¤§äºä»å¶ä»éå¾å°tx,tyçè·ç¦»ï¼ä¸å°tx,tyç¹æ¶çå©ä½æ¶é´å¤§äºç±x,yç¹å°tx,tyç¹åçå©ä½æ¶é´ï¼å°±è·³è¿
    //è¿æ¯å ä¸ºç»ç¹å¯éå¤è®¿é®æä»¥æ¬èº«æ²¡æ è®°ï¼é£ä¹å½ä¸è¿°æ¡ä»¶æ»¡è¶³æ¶ï¼ç±tx,tyå¼å§çæä¼è§£å·²ç»æ±è¿(å­å¨æèä¸å­å¨)ï¼æä»¥ä¸éè¦åéå¤æ±äºã
    if(cnt>=step[x][y] && time[x][y]>=len)return;
    step[x][y]=cnt;
    time[x][y]=len;
    int tx,ty,i;
    for(i=0;i<4;++i){
        tx = x+dir[i][0];
        ty = y+dir[i][1];
        dfs(tx,ty,len-1,cnt+1);
    }
}

int main(){

    //freopen("in.txt","r",stdin);
    int t,i,j,len,cnt;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        for(i=0;i<n;++i){
            for(j=0;j<m;++j){
                time[i][j]=0;
                step[i][j]=INT_MAX-3;//è¿éç½®ä¸ä¸ªå¤§æ°ï¼è¡¨ç¤ºå°i,jçæ­¥æ°æ éå¤§
                scanf("%d",&map[i][j]);
                if(map[i][j]==2){
                    sx = i;
                    sy = j;
                }else if(map[i][j]==3){
                    dx = i;
                    dy = j;
                }
            }
        }
        len = 6;
        cnt = 0;
        minx = INT_MAX;
        dfs(sx,sy,len,cnt);
        if(minx==INT_MAX){
            printf("-1\n");
        }else{
            printf("%d\n",minx);
        }
    }
    
    return 0;
}
